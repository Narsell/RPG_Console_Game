#include "Random.h"
#include <cstdlib>

int Random(int low, int high)
{

	
	return low + rand() % ((high + 1) - low);

}