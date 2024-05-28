#include "../inc/C_tool.h"

int	main(void)
{
	short	step;

	step = 0;
	Ct_flag_init();
	for (size_t i = 0; i < 10; i++)
	{
		Ct_flag_make("loop", step);
		if (i % 2 == 0)
			Ct_flag_make("if", step);
	}
	step++;
	for (size_t i = 0; i < 10; i++)
	{
		Ct_flag_make("loop", step);
		if (i % 2 == 0)
			Ct_flag_make("if", step);
	}
	Ct_flag_end(1);
}