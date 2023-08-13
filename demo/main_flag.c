#include "../inc/C_tool.h"

int	main(void)
{
	short	step;

	step = 0;
	Ct_flag_init();
	for (size_t i = 0; i < 10; i++)
	{
		Ct_make_flag("loop", step);
		if (i % 2 == 0)
			Ct_make_flag("if", step);
	}
	step++;
	for (size_t i = 0; i < 10; i++)
	{
		Ct_make_flag("loop", step);
		if (i % 2 == 0)
			Ct_make_flag("if", step);
	}
	Ct_flag_end(1);
}