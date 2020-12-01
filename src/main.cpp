#include "ui/gui.h"
#include <libconfig.h++>
extern "C" {
#include "ui.gresource.h"
}

int main(int argc, char **argv) {

	// register the resource bundle
	auto resource_bundle = Glib::wrap(ui_get_resource());
	// std::cerr << "rp: " << resource_bundle << std::endl;
	resource_bundle->register_global();

	G::ReachGUI gui("com.adriancedwards.reach");

	return gui.app->run(argc, argv);
}