#include "inc/C_tool.h"


int main() {
	float a = 1.234;
	for (size_t i = 0; i < 10000; i++) {
		TRAC_ADD_INT("test", i);
		Ct_trac_add("test2", TRACV(a), _float);
		usleep(10000);
		Ct_trac();
	}
	Ct_trac_end();
}