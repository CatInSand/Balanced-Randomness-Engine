# Balanced Randomness Engine
This random number generator generates "balanced" result by making sure that the sum of all generated numbers stays within a specified range. This ensures that the set of numbers you generate as a whole can't go past a certain distance from the average, removing statistical outliers that would occur when many such sets are generated. Basically, it ensures randomness to a certain degree.

## Generation
The engine keeps track of the sum and count of all generated numbers. When it generates a number, it checks if the new sum is within the specified number of standard deviations away from the average. If so, it returns that value, otherwise, it generates a new one and checks again.
