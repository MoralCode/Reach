#include <iostream>
#include "gui.h"

using namespace G;

ReachGUI::ReachGUI(std::string appid) {

	app = Gtk::Application::create(appid);

	// Instantiate THE gui when the application has been activated.
	// This can only be done after the application has been registered.
	// It's possible to call app->register_application() explicitly, but
	// usually it's easier to let app->run() do it.
	app->signal_activate().connect([this]() { on_app_activate(); });
}

Gtk::ApplicationWindow *window = nullptr;

void ReachGUI::close_hide_window() {
	if (window)
		window->hide(); // hide() will cause Gtk::Application::run() to end.
}

void ReachGUI::on_import() {
	//TODO: Get a reference to and call the Contactsmanager class
	importw_ = new ImportWindow;
	importw_->signal_hide().connect(
		sigc::mem_fun(*this, &ReachGUI::on_close_importwindow));
	importw_->show();
}

void ReachGUI::show_contact(Contact *contact) {

	Field *fullName = nullptr;
	contact->find_field_by_type("FN", fullName);
	set_contact_name(fullName->getValue());
}

void ReachGUI::set_contact_name(std::string name) {

	Gtk::Label *nameLabel = nullptr;
	refBuilder->get_widget<Gtk::Label>("personname", nameLabel);
	if (nameLabel)
		nameLabel->set_label(name);
 }

void ReachGUI::on_close_importwindow() { importw_ = 0; }

void ReachGUI::on_app_activate() {
	// Load the GtkBuilder file and instantiate its widgets:
	refBuilder = Gtk::Builder::create();
	try {
		refBuilder = Gtk::Builder::create_from_resource("/ui/resources/reach.glade");
	} catch (const Glib::MarkupError &ex) {
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return;
	} catch (const Gtk::BuilderError &ex) {
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return;
	}

	// Get the GtkBuilder-instantiated dialog:
	refBuilder->get_widget<Gtk::ApplicationWindow>("ReachWindow", window);

	if (!window) {
		std::cerr << "Could not get the dialog" << std::endl;
		return;
	}
	window->set_title("Reach");
	// Get the GtkBuilder-instantiated button, and connect a signal handler:
	Gtk::ImageMenuItem *pButton = nullptr;
	refBuilder->get_widget<Gtk::ImageMenuItem>("quit_button", pButton);

	if (pButton)
		pButton->signal_activate().connect([this]() { close_hide_window(); });

	// Get the button to import a contact, and connect a signal handler:
	Gtk::Button *newContactButton = nullptr;
	refBuilder->get_widget<Gtk::Button>("new_contact_button", newContactButton);
	if (newContactButton)
		newContactButton->signal_clicked().connect([this]() { on_import(); });

	// It's not possible to delete widgets after app->run() has returned.
	// Delete the dialog with its child widgets before app->run() returns.
	window->signal_hide().connect([this]() { delete window; });

	app->add_window(*window);
	window->show();
}