#include "SystemPrograms.h"
#include <cstdlib>


//Currently uses DOS commands, but could port to eg. ncurses
void system_clear()
{
	system("CLS");
}


void system_pause()
{
	system("PAUSE");
}
