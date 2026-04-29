import matplotlib.pyplot as plt
import math

# Given data
n = [10, 100, 1000, 10000]
time_ns = [0, 10, 547, 48636 ]  # 0 ko 1 se replace (log issue avoid)

# Theoretical complexities
n_linear = n
n_square = [x*x*0.002 for x in n]
log_n = [math.log2(x) for x in n]

# Plot
plt.loglog(n, time_ns, marker='o', label="Actual Time (Linear Search)")
plt.loglog(n, n_linear, linestyle='--', label="O(n)")
plt.loglog(n, n_square, linestyle='--', label="O(n²)")
plt.loglog(n, log_n, linestyle='--', label="O(log n)")

plt.text(2000, 5000000000, 
         "Log–log plot shows growth rate clearly", 
         fontsize=9)
plt.xlabel("Input size (n)")
plt.ylabel("Average time (log scale)")
plt.title("Time Complexity Comparison for Selection Sort")

plt.legend()
plt.grid(True, which="both")

plt.show()
