# Data from your output

n_values = [10,20,30,40,50,60,70,80,90,100]

ratio = [716,3373.76,2040.73,7790.96,995.765,8492.56,6124.15,18150.7,4228.95,2898.54]
profit = [333.443,323.924,88.6599,1208.51,346.26,831.239,175.005,971.302,928.89,131.462]
weight = [716,2850.09,2040.73,6945.98,878.266,7191.43,6124.15,15609.2,3400.36,1636.18]

import matplotlib.pyplot as plt

plt.figure()
plt.plot(n_values, ratio)
plt.plot(n_values, profit)
plt.plot(n_values, weight)

plt.xlabel("Number of Items (n)")
plt.ylabel("Profit")
plt.title("Comparison of Ratio, Profit and Weight Methods")
plt.legend(["Ratio Method", "Profit Method", "Weight Method"])

plt.show()
