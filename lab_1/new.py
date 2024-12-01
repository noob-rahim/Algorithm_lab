import matplotlib.pyplot as plt
import numpy as np

# Data
input_sizes = [1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000]
recursive_calls = [1999, 9999, 19999, 29999, 39999, 49999, 59999, 69999]
iterative_steps = [1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000]

# Bar positions
bar_width = 0.35
x = np.arange(len(input_sizes))

# Create bars
bars1 = plt.bar(x - bar_width/2, recursive_calls, bar_width, label='Recursive Calls', color='blue')
bars2 = plt.bar(x + bar_width/2, iterative_steps, bar_width, label='Iterative Steps', color='orange')

# Add labels and title
plt.xlabel('Input Size')
plt.ylabel('Number of Calls')
plt.title('Input Size vs. Number of Calls')
plt.xticks(x, input_sizes)
plt.legend()

# Show the chart
plt.tight_layout()
plt.show()
