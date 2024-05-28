#include "inc/C_tool.h"


int main() {
	TIME_START;
	LOG_ERR("this is a loop");
	for (size_t i = 0; i < 10; i++)
	{
		TIME_RESTART;
		sleep(1);
		LOG_MSG(TIME_STOP);
	}
	LOG_WAR("test end");
}