#include "inc/C_tool.h"


int main() {
	Ct_trac_add("test1", TRACV(8), _int);
	for (size_t i = 0; i < 10000; i++) {
		Ct_trac_add("test1", TRACV(i), _int);
		Ct_trac();
		usleep(10000);
	}
	Ct_trac_end();
}