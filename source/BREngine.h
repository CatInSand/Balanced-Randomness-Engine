#ifndef BRENGINE_H
#define BRENGINE_H

#include <random>
#include <vector>

/**
A random number generator that balances results by ensuring the sum of all results
stays within a specified number of standard deviations away from the average.
*/
class BREngine final
{
public:
	/**
	* Constructs a balanced randomness engine.
	*
	* @param min: Minimum value the engine can generate.
	* @param max: Maximum value the engine can generate.
	* @param deviations: The number of standard deviations the results must stay inside.
	*/
	BREngine(int min, int max, float deviations = 2.f);

	/**
	* Generates a random number between the minimum and maximum.
	*
	* @return The generated number.
	*/
	int Generate();

	/**
	Resets the internal counters that track previous results.
	*/
	void Reset();

	/**
	The minimum result the engine can generate.
	*/
	const int m_MinResult;
	/**
	The maximum result the engine can generate.
	*/
	const int m_MaxResult;
	/**
	The average result the engine will generate.
	*/
	const float m_Mean;
	/**
	The value of a single standard deviation.
	*/
	const float m_StandardDeviation;
	/**
	The number of standard deviations the sum of results will stay within.
	*/
	float m_Deviations;

	/**
	* Getter for the internal sum of all generated numbers.
	*
	* @return The sum.
	*/
	int Sum() const;
	/**
	* Getter for the internal count of generated numbers.
	*
	* @return The count.
	*/
	int Count() const;

private:
	static float CalculateStandardDeviation(int min, int max);

	std::random_device m_RD; //unitialized by design
	std::uniform_int_distribution<int> m_Distribution;

	int m_Sum{};
	int m_Count{};
};

#endif