#include "inc/C_tool.h"

/*
int main() {
	float a = 0;
	for (size_t i = 0; i < 1000; i++) {
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
*/


int main(void) {
  char str[200];
  int v = 0;
  for (int i = 0; i < 200 - 1; i++) {
    str[i] = v;
    v++;
  }
  (void)str;
  Ct_mprintf(str, 200 - 1, 1, 'A');
}