#include "inc/C_tool.h"


int main() {
	float a = 0;
	for (size_t i = 0; i < 10000; i++) {
		TRAC_ADD_CHAR("char", i);
		TRAC_ADD_INT("int", i);
		TRAC_ADD_FLOAT("float", a);
		TRAC_ADD_FLOAT("double", a);
		TRAC_ADD_LINE("line", i);
		TRAC_ADD_PER("test", i);
		//Ct_trac_add("test2", TRACV(a), _float);
		usleep(10000);
		a += 1.1;
		Ct_trac();
	}
	Ct_trac_end();
}