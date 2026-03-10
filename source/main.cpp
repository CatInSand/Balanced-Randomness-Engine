#include <iostream>

#include "BREngine.h"

struct Data
{
	std::vector<int> results;
};

void TestEngine(int min, int max, int numberCount, int sampleCount, float deviation = 2.f)
{
	std::vector<Data> samples{ };

	for (int sample{ 0 }; sample < sampleCount; ++sample)
	{
		Data sampleData{};
		BREngine brEngine{ min, max, deviation };

		for (int iteration{ 0 }; iteration < numberCount; ++iteration)
		{
			int result{ brEngine.Generate() };
			sampleData.results.push_back(std::move(result));
		}

		samples.push_back(std::move(sampleData));
	}

	float minMean{ FLT_MAX };
	float maxMean{ FLT_MIN };
	float averageMean{};

	float minSum{ FLT_MAX };
	float maxSum{ FLT_MIN };
	float averageSum{};

	for (const Data& data : samples)
	{
		float mean{};
		float Sum{};
		for (int result : data.results)
		{
			mean += result;
			Sum += result;
		}
		mean /= numberCount;

		if (mean < minMean)
		{
			minMean = mean;
		}
		else if (mean > maxMean)
		{
			maxMean = mean;
		}
		averageMean += mean;

		if (Sum < minSum)
		{
			minSum = Sum;
		}
		else if (Sum > maxSum)
		{
			maxSum = Sum;
		}
		averageSum += Sum;
	}
	averageMean /= sampleCount;
	averageSum /= sampleCount;

	std::cout << "- - " << sampleCount << " samples taken - - " << numberCount << " numbers per sample - - deviation is " << deviation << " - -\n";
	std::cout << "Type\tMin\tMax\tAverage\n\n";
	std::cout << "Mean\t" << minMean << "\t" << maxMean << "\t" << averageMean << "\n";
	std::cout << "Sum\t" << minSum << "\t" << maxSum << "\t" << averageSum << "\n";
	std::cout << "\n";
}

int main()
{
	TestEngine(1, 20, 20, 10000, 0.2f);
	TestEngine(1, 20, 20, 10000, 1.f);
	TestEngine(1, 20, 20, 10000, 2.f);
	TestEngine(1, 20, 20, 10000, 3.f);
	TestEngine(1, 20, 20, 10000, 1000.f);
}