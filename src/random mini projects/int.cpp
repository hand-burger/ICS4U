#include <iostream>
#include <time.h>

int main(){
	srand(time(NULL));
	int pos;
	int spread[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int r;
	for (int i = 0; i < 1; i++)
	{
		pos = 1;
		for (int i = 0; i < 9; i++)
		{
			r = rand() % 2;
			if (r == 1)
			{
				pos++;
			}
		}
		spread[pos - 1]++;
	}
	std::cout << "Simulation complete, here is the spread:\n";

	for (int i = 0; i < 10; i++)
	{
		std::cout << "number of " << i + 1 << ": " << spread[i];
		std::cout << "\n";
	}
	return 0;
}
