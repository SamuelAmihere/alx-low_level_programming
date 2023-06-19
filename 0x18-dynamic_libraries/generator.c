#include <string.h>
#include <unistd.h>

int rand(void)
{
	static int tracker = -1;

	tracker++;
	switch (tracker)
	{
		case 0:
		case 1:
			return (8);
		case 2:
			return (7);
		case 3:
			return (9);
		case 4:
			return (23);
		case 5:
			return (74);
		default:
			return ((tracker % 30000) * tracker);
	}
}
