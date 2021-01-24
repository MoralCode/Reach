#include <iostream>
#include <string>
#include "contact.h"
using namespace std;

Contact::Contact() {
	
}

Contact::Contact(vc_component *component) {
	
	vc_component *next = vc_get_next(component);

	while (next) {
		add_field(new Field(next));
		next = vc_get_next(next);
	}
}

void Contact::add_field(Field *field) {

}

void Contact::find_field_by_type(string vc_type, Field *fieldPtr) {

}