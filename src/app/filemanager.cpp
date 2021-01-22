#include "filemanager.h"
#include <iostream>

#define CONFIG_FILENAME "reach.cfg"

using namespace A;
using namespace libconfig;

FileManager::FileManager(std::string path = "db") {
	setup_metadata();
}

void FileManager::setup_metadata() {
	try {
		metadata.readFile(CONFIG_FILENAME);
	} catch (const FileIOException &fioex) {
		std::cerr << "I/O error while reading file." << std::endl;
		// return (EXIT_FAILURE);
	} catch (const ParseException &pex) {
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
				  << " - " << pex.getError() << std::endl;
		// return (EXIT_FAILURE);
	}
}

vector<string> list_filenames() {
	// http://www.martinbroadhurst.com/list-the-files-in-a-directory-in-c.html
}