#include "helloworld.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
	auto app = Gtk::Application::create(argc, argv, "com.adriancedwards.reach");

	HelloWorld helloworld;

	// Shows the window and returns when it is closed.
	return app->run(helloworld);
}