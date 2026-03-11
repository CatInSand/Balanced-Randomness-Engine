# Balanced Randomness Engine
This random number generator generates "balanced" result by making sure that the sum of all generated numbers stays within a specified range. This ensures that the set of numbers you generate as a whole can't go past a certain distance from the average, removing statistical outliers that would occur when many such sets are generated. Basically, it ensures randomness to a certain degree.

## Generation
The engine keeps track of the sum and count of all generated numbers. When it generates a number, it checks if the new sum is within the specified number of standard deviations away from the average. If so, it returns that value, otherwise, it generates a new one and checks again.

The engine uses 2 as the default number of deviations, which corresponds to 95.44% of all results, but you are able to set that number yourself. The following is a list of numbers of deviations together with the chance that a sum is within that range:

-0.674 SD: ~50.00%

-0.977 SD: ~66.67%

-1.0 SD: ~68.27%

-1.281 SD: ~80.00%

-1.645 SD: ~90.00%

-2.0 SD: ~95.45%

-3.0 SD: ~99.73%

-4.0 SD: ~99.99%
