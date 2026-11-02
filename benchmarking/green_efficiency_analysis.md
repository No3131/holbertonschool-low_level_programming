# Green Efficiency Analysis

## Measurement Methodology

The objective of this project was to measure the CPU execution time of different C programs and understand how algorithmic efficiency can affect performance.

All programs were compiled using GCC with the required flags: `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. The experiments were performed in the same Holberton Sandbox environment.

The programs used the `clock()` function from the C standard library to measure CPU time. The difference between the starting and ending clock values was divided by `CLOCKS_PER_SEC` to obtain execution time in seconds.

For the baseline experiment, the program performed 100 million iterations and was executed three times. The algorithm comparison program was executed four times, measuring both implementations during each execution. The instrumentation experiment measured the dataset building, processing, and checksum reduction phases separately, as well as the total execution time.

## Observed Performance Differences

The baseline program produced execution times of 0.238333, 0.225628, and 0.226328 seconds. The average was approximately 0.230096 seconds. These results demonstrate that execution time can vary slightly between runs, even when the same computation is performed.

The algorithm comparison showed a much larger performance difference. The naive algorithm had an average execution time of 2.74365925 seconds, while the single-pass algorithm averaged 0.00010625 seconds.

Based on these measurements, the naive implementation took approximately 25,823 times as long as the single-pass implementation.

The naive algorithm uses nested loops with O(n²) complexity, while the single-pass algorithm uses one loop with O(n) complexity. However, the implementations produced different results: 625025000 and 25000 respectively, because the naive algorithm counts some values multiple times.

In the instrumentation experiment, the total CPU time was 0.000806 seconds. Dataset building took 0.000303 seconds, processing took 0.000361 seconds, and checksum reduction took 0.000136 seconds.

Processing was the longest individual phase in this measurement.

## Relation Between Runtime and Energy Consumption

CPU execution time can provide useful information when discussing software efficiency and energy consumption.

The algorithm comparison demonstrated that different implementations can require substantially different amounts of CPU time.

Reducing unnecessary computations can potentially reduce processor activity and energy consumption. For example, the single-pass implementation required much less CPU time than the naive implementation in the recorded measurements.

However, these experiments measured execution time rather than electrical power or energy consumption. Therefore, the results do not prove a specific reduction in electricity usage or carbon emissions.

## Limitations of the Experiment

The experiments have several limitations.

First, the measurements were performed in a single Sandbox environment, so results may differ on other machines.

Second, CPU scheduling, system activity, and measurement precision can affect recorded execution times.

Third, the single-pass algorithm executed extremely quickly, making its measured duration sensitive to timing resolution and rounding.

Additionally, the two algorithms in the comparison experiment did not produce identical results, limiting the fairness of treating them as equivalent solutions.

Finally, no power measurement equipment was used, so actual energy consumption was not determined.

## Practical Engineering Takeaway

These experiments demonstrate the importance of measuring software performance instead of relying only on assumptions.

The baseline experiment showed timing variability, the algorithm comparison highlighted substantial differences in CPU execution time, and the instrumentation experiment identified processing as the most time-consuming phase.

As a developer, I should compare implementations carefully, repeat measurements, and examine algorithmic complexity before making optimization decisions.

Efficient software engineering requires reliable measurements, correct program behavior, and awareness of the limitations of performance data.

