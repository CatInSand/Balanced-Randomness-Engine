#include "BREngine.h"

BREngine::BREngine(int min, int max, float deviations)
	: m_MinResult{ min }
	, m_MaxResult{ max }
	, m_Mean{ (min + max) / 2.f }
	, m_StandardDeviation{ CalculateStandardDeviation(min, max) }
	, m_Distribution{ min, max }
	, m_Deviations{ deviations }
{

}

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