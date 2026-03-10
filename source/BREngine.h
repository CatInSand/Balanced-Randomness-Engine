#ifndef BRENGINE_H
#define BRENGINE_H

#include <random>

class BREngine final
{
public:
	BREngine(int min, int max, float deviations = 2.f);

	int Generate();

	void SetDeviations(float deviations);

	const int m_MinResult;
	const int m_MaxResult;
	const float m_Mean;
	const float m_StandardDeviation;

private:
	static float CalculateStandardDeviation(int min, int max);

	std::random_device m_RD; //unitialized by design
	std::uniform_int_distribution<int> m_Distribution;

	float m_Deviations;
	int m_Sum{};
	int m_AmountGenerated{};
};

#endif