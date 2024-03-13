#include "inc/C_tool.h"

int main() {
	if (!Ct_flag_end(2))
		Ct_err("hello");
	Ct_err_code = 7;
	Ct_err("hello");
}