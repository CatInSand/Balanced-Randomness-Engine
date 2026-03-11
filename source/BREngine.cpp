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
	const float cumulativeMean{ (m_Count + 1) * m_Mean };
	const float cumulativeDeviation{ sqrt(static_cast<float>(m_Count + 1)) * m_StandardDeviation };
	const float lowerBound{ cumulativeMean - cumulativeDeviation * m_Deviations };
	const float upperBound{ cumulativeMean + cumulativeDeviation * m_Deviations };

	while (true)
	{
		int result{ m_Distribution(m_RD) };
		if (m_Sum + result > lowerBound &&
			m_Sum + result < upperBound)
		{
			m_Sum += result;
			++m_Count;
			return result;
		}
	}
}

void BREngine::Reset()
{
	m_Sum = 0;
	m_Count = 0;
}

int BREngine::Sum() const
{
	return m_Sum;
}
int BREngine::Count() const
{
	return m_Count;
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