#include "BREngine.h"

BREngine::BREngine(int min, int max)
	: m_MinResult{ min }
	, m_MaxResult{ max }
	, m_Mean{ (min + max) / 2.f }
	, m_Distribution{ min, max }
{

}

int BREngine::Generate()
{
	int result{ m_Distribution(m_RD) };

	return result;
}