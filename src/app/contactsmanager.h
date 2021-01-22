#ifndef REACH_CONTACTSMANAGER_H
#define REACH_CONTACTSMANAGER_H
#include "filemanager.h"
#include <string>
#include <vc.h>
#include <vector>

using namespace std;

namespace A {
class ContactsManager {
	// Maintains a list of contacts while the app is running
public:
	ContactsManager();
	// virtual ~ContactsManager();
	void add_contact();
	void save_contact();
	void load_contact();
	void delete_contact();

private:
	FileManager fileManager;
	vector <vc_component *> contactList;
};
} // namespace A

#endif // REACH_CONTACTSMANAGER_H