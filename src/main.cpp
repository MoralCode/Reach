#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <iostream>

namespace {
Gtk::ApplicationWindow *window = nullptr;
Glib::RefPtr<Gtk::Application> app;

void close_hide_window() {
	if (window)
		window->hide(); // hide() will cause Gtk::Application::run() to end.
}

void on_app_activate() {
	// Load the GtkBuilder file and instantiate its widgets:
	auto refBuilder = Gtk::Builder::create();
	try {
		refBuilder->add_from_file("reach.glade", "ReachWindow");
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
		pButton->signal_activate().connect([]() { close_hide_window(); });

	// It's not possible to delete widgets after app->run() has returned.
	// Delete the dialog with its child widgets before app->run() returns.
	window->signal_hide().connect([]() { delete window; });

	app->add_window(*window);
	window->show();
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