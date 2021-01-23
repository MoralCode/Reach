#include <iostream>
#include <string>
#include "util.h"
#include "field.h"
using namespace std;

Field::Field(string type, string label, string value) : vc_type(type), label(label), value(value) {}
