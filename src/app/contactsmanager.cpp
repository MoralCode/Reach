#include "contactsmanager.h"
#include <iostream>
using namespace A;

ContactsManager::ContactsManager() { 
	fileManager = new FileManager();
	// query file manager for a list of all contacts
	//parse all contacts into components
	//store those in memory
}


void add_contact();
void save_contact();
void load_contact();
void delete_contact();