#include <iostream>
#include <string>
#include "util.h"
#include "field.h"
using namespace std;

Field::Field(string type, string label, string value) : vc_type(type), label(label), value(value) {}

Field::Field(vc_component *component)
	: vc_type("type"), label(vc_get_name(component)), value(vc_get_value(component)) {}

string Field::getValue() { return value; }

string Field::getLabel() { return label; }

string Field::getType() { return vc_type; }