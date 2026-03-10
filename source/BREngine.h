#ifndef BRENGINE_H
#define BRENGINE_H

#include <random>

class BREngine final
{
public:
	BREngine(int min, int max);

	int Generate();

	const int m_MinResult;
	const int m_MaxResult;
	const float m_Mean;

private:
	std::random_device m_RD; //unitialized by design
	std::uniform_int_distribution<int> m_Distribution;
};

#endif