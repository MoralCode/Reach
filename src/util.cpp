#include "util.h"
extern "C" {
#include <uuid.h>
}

// std::string newUUID() {
// 	uuid_t uuid;
// 	uuid_generate_random(uuid);
// 	char s[37];
// 	uuid_unparse(uuid, s);
// 	return s;
// }