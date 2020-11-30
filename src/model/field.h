#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED


#include <string>

using namespace std;

class Field {
public:
	int id;
	string vc_type;
	string label;
	string value;

	Field(string type, string label, string value);
};

#endif