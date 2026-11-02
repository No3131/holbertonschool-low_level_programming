# Algorithm Efficiency Comparison — Metrics

## 1. Execution Results

The program was compiled using the required GCC flags and executed four times in the same environment.

### Run 1

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.742738 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

### Run 2

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.749217 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000107 seconds
```

### Run 3

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.740247 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

### Run 4

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.742435 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

## 2. Average Execution Times

| Algorithm | Average execution time |
|---|---|
| Naive | 2.74365925 seconds |
| Single-pass | 0.00010625 seconds |

## 3. Relative Performance

Performance ratio:

2.74365925 / 0.00010625 = 25822.68

Based on the recorded CPU times, the naive implementation took approximately 25,823 times as long as the single-pass implementation.

## 4. Analysis

The naive algorithm uses nested loops and has O(n²) time complexity.

The single-pass algorithm uses one loop and has O(n) time complexity.

The single-pass implementation requires significantly fewer operations and was much faster in these measurements.

However, the algorithms produce different results because the naive implementation counts some even numbers multiple times. Therefore, they are not strictly equivalent computations.

The measurements also have limited precision, particularly for the very short single-pass execution time.

## 5. Conclusion

The measurements demonstrate a substantial difference in CPU execution time between the two implementations.

More efficient algorithms can reduce CPU activity and potentially reduce energy consumption. However, actual energy consumption was not measured in this experiment.

