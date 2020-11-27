#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <iostream>

namespace {
Gtk::Dialog *pDialog = nullptr;
Glib::RefPtr<Gtk::Application> app;

void on_button_clicked() {
	if (pDialog)
		pDialog->hide(); // hide() will cause Gtk::Application::run() to end.
}

void on_app_activate() {
	// Load the GtkBuilder file and instantiate its widgets:
	auto refBuilder = Gtk::Builder::create();
	try {
		refBuilder->add_from_file("basic.glade", "DialogBasic");
	} catch (const Glib::FileError &ex) {
		std::cerr << "FileError: " << ex.what() << std::endl;
		return;
	} catch (const Glib::MarkupError &ex) {
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return;
	} catch (const Gtk::BuilderError &ex) {
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return;
	}

	// Get the GtkBuilder-instantiated dialog:
	refBuilder->get_widget<Gtk::Dialog>("DialogBasic", pDialog);
	
	if (!pDialog) {
		std::cerr << "Could not get the dialog" << std::endl;
		return;
	}

	// Get the GtkBuilder-instantiated button, and connect a signal handler:
	Gtk::Button* pButton = nullptr;
	refBuilder->get_widget<Gtk::Button>("quit_button", pButton);

	if (pButton)
		pButton->signal_clicked().connect([]() { on_button_clicked(); });

	// It's not possible to delete widgets after app->run() has returned.
	// Delete the dialog with its child widgets before app->run() returns.
	pDialog->signal_hide().connect([]() { delete pDialog; });

	app->add_window(*pDialog);
	pDialog->show();
}
} // anonymous namespace

int main(int argc, char **argv) {
	app = Gtk::Application::create("com.adriancedwards.reach");

	// Instantiate a dialog when the application has been activated.
	// This can only be done after the application has been registered.
	// It's possible to call app->register_application() explicitly, but
	// usually it's easier to let app->run() do it for you.
	app->signal_activate().connect([]() { on_app_activate(); });

	return app->run(argc, argv);
}