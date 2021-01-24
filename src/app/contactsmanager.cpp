#include "contactsmanager.h"
#include <iostream>
#include <vc.h>
using namespace A;

ContactsManager::ContactsManager() { 
	fileManager = new FileManager();
	// query file manager for a list of all contacts
	//parse all contacts into components
	//store those in memory
}

void ContactsManager::import_contact(string filename) {
	std::cout << "Importing..." << std::endl;

	FILE *fptr;
	fptr = fopen(filename.c_str(), "r");

	vc_component *component = parse_vcard_file(fptr);

	add_contact(new Contact(component));
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