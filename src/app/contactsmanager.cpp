#include "contactsmanager.h"
#include <iostream>
using namespace A;

ContactsManager::ContactsManager() { 
	fileManager = new FileManager();
	// query file manager for a list of all contacts
	//parse all contacts into components
	//store those in memory
}

void ContactsManager::add_contact(Contact *contact){
	std::cout << "done." << std::endl;
	Field* f;
	// exception
	contact->find_field_by_type("FN", f);
	std::cout << f->getValue() << std::endl;
}

void save_contact();
void load_contact();
void delete_contact();