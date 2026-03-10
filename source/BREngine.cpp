#include "BREngine.h"

/**
 * Constructs a balanced randomness engine
 * 
 * @param min: Minimum value the engine can generate.
 * @param max: Maximum value the engine can generate.
 * @param deviations: The number of standard deviations the results must stay inside.
 */
BREngine::BREngine(int min, int max, float deviations)
	: m_MinResult{ min }
	, m_MaxResult{ max }
	, m_Mean{ (min + max) / 2.f }
	, m_StandardDeviation{ CalculateStandardDeviation(min, max) }
	, m_Distribution{ min, max }
	, m_Deviations{ deviations }
{

}

/**
 * Generates a random number between the minimum and maximum
 *
 * @return The random number.
 */
int BREngine::Generate()
{
	int result{ m_Distribution(m_RD) };

	bool valid{ false };
	do
	{
		result = m_Distribution(m_RD);

		float cumulativeMean{ (m_AmountGenerated + 1) * m_Mean };
		float cumulativeDeviation{ sqrt(static_cast<float>(m_AmountGenerated + 1)) * m_StandardDeviation };

		if (m_Sum + result > cumulativeMean - cumulativeDeviation * m_Deviations &&
			m_Sum + result < cumulativeMean + cumulativeDeviation * m_Deviations)
		{
			valid = true;
		}

	} while (!valid);

	m_Sum += result;
	++m_AmountGenerated;

	return result;
}

/**
 * Resets the internal counters that track previous results
 * 
 */
void BREngine::Reset()
{
	m_Sum = 0;
	m_AmountGenerated = 0;
}

float BREngine::CalculateStandardDeviation(int min, int max)
{
	int count{ min + max - 1 };
	float mean{ (min + max) / 2.f };

	float result{};
	for (int index{ 1 }; index <= count; ++index)
	{
		result += (index - mean) * (index - mean);
	}
	result = sqrt(result / count);

	return result;
}