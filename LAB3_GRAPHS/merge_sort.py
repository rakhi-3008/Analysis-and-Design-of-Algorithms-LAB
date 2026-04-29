import matplotlib.pyplot as plt
import math

# Given data
n = [10, 100, 1000, 10000, 100000]
time_ns = [9.83, 68.66, 715.65, 6412.54, 67649.2]

# Theoretical complexities
n_linear = n
n_square = [x*x for x in n]
log_n = [math.log2(x) for x in n]
n_log_n = [x * math.log2(x) for x in n]

# Plot
plt.loglog(n, time_ns, marker='o', label="Actual Time")
plt.loglog(n, n_linear, linestyle='--', label="O(n)")
plt.loglog(n, n_square, linestyle='--', label="O(n²)")
plt.loglog(n, log_n, linestyle='--', label="O(log n)")
plt.loglog(n, n_log_n, linestyle='--', label="O(n log n)")

plt.text(2000, 5000000000, 
         "Log–log plot shows growth rate clearly", 
         fontsize=9)

plt.xlabel("Input size (n)")
plt.ylabel("Average time (log scale)")
plt.title("Time Complexity Comparison for Merge Sort")

plt.legend()
plt.grid(True, which="both")

plt.show()
