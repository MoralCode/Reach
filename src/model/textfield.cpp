#include "util.h"
#include "field.h"
#include <iostream>
#include <string>
#include "textfield.h"
#include "field.h"
using namespace std;

// Base class
TextField::TextField(string type, string label, string value, string format) : Field(type, label, value) {
	format = format;
}

bool TextField::TextField::validate() {
	return true;
}
