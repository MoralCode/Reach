#ifndef REACH_FILEMANAGER_H
#define REACH_FILEMANAGER_H
#include <libconfig.h++>
#include <string>
#include <vector>

using namespace std;
using namespace libconfig;

namespace A {
class FileManager {
	//manages the on-disk file structure of the contacts as a sort of DIY database
public:
	FileManager(string path);
	// virtual ~FileManager();
	FILE * get_file(string filename);
	void delete_file(string filename);
	vector<string> list_filenames();


protected:
	//sets up a metadata file explaining the database and its structure
	void setup_metadata();

private:
	string db_root_path;
	Config metadata;

};
} // namespace A

#endif // REACH_FILEMANAGER_H