#include "gui.h"
#include <libconfig.h++>

int main(int argc, char **argv) {
	G::ReachGUI gui("com.adriancedwards.reach");

	return gui.app->run(argc, argv);
}