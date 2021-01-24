#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include "field.h"
#include <string>
#include <vc.h>
#include <vector>

using namespace std;

class Contact {
public:
	Contact();
	Contact(vc_component *component);
	// virtual ~Contact();
	void add_field(Field *field);
	void find_field_by_type(string vc_type, Field *fieldPtr);

private:
	vector<Field> fields;

};

#endif //CONTACT_H_INCLUDED