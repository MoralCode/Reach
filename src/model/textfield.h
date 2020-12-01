#ifndef TEXTFIELD_H_INCLUDED
#define TEXTFIELD_H_INCLUDED

#include <string>
#include "field.h"

using namespace std;

class TextField: public Field {
public:
	int id;
	string vc_type;
	string label;
	string value;

	TextField(string type, string label, string value, string format);

	bool validate();

};
#endif