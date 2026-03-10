#include <iostream>
#include "BREngine.h"

int main()
{
	BREngine brEngine{ 1, 20 };
	std::cout << "Random number: " << brEngine.Generate() << "\n";
	std::cout << "Random number: " << brEngine.Generate() << "\n";
	std::cout << "Random number: " << brEngine.Generate() << "\n";
	std::cout << "Random number: " << brEngine.Generate() << "\n";
}