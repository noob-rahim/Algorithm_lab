import matplotlib.pyplot as plt
import numpy as np

# Data
input_sizes = [100, 500, 1000, 1500, 2000]
bubble_sort_steps = [4950, 124750, 499500, 1124750, 1999000]
selection_sort_steps = [4950, 124750, 499500, 1124750, 1999000]
insertion_sort_steps = [1638, 12750, 49500, 111750, 199000]

# Set up the bar positions
bar_width = 0.25
x = np.arange(len(input_sizes))

# Create the bar plots
plt.bar(x, bubble_sort_steps, width=bar_width, label='Bubble Sort', color='b')
plt.bar(x + bar_width, selection_sort_steps, width=bar_width, label='Selection Sort', color='g')
plt.bar(x + 2 * bar_width, insertion_sort_steps, width=bar_width, label='Insertion Sort', color='r')

# Labeling the graph
plt.xlabel('Input Size')
plt.ylabel('Number of Steps')
plt.title('Sorting Algorithm Steps Comparison')
plt.xticks(x + bar_width, input_sizes)
plt.legend()

# Show the graph
plt.tight_layout()
plt.show()
