import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Function to update the plot for each frame
def update(frame):
    ax.clear()
    ax.set_xlim([-5, 5])
    ax.set_ylim([-5, 5])
    ax.set_aspect('equal')

    # Define two complex numbers
    z1 = np.exp(1j * frame / 10)
    z2 = 2 * np.exp(1j * frame / 20)

    # Plot the complex numbers
    ax.arrow(0, 0, z1.real, z1.imag, color='r', label='z1', head_width=0.2, head_length=0.2)
    ax.arrow(0, 0, z2.real, z2.imag, color='b', label='z2', head_width=0.2, head_length=0.2)

    # Perform complex number operations
    z_sum = z1 + z2
    z_diff = z1 - z2
    z_prod = z1 * z2
    z_div = z1 / z2

    # Plot the results of complex number operations
    ax.arrow(0, 0, z_sum.real, z_sum.imag, color='g', label='z1 + z2', head_width=0.2, head_length=0.2)
    ax.arrow(0, 0, z_diff.real, z_diff.imag, color='m', label='z1 - z2', head_width=0.2, head_length=0.2)
    ax.arrow(0, 0, z_prod.real, z_prod.imag, color='c', label='z1 * z2', head_width=0.2, head_length=0.2)
    ax.arrow(0, 0, z_div.real, z_div.imag, color='y', label='z1 / z2', head_width=0.2, head_length=0.2)

    # Display legend
    ax.legend(loc='upper left')

# Create a figure and axes
fig, ax = plt.subplots()

# Create the animation
ani = FuncAnimation(fig, update, frames=np.arange(0, 100, 1), interval=100)

# Display the animation
plt.show()

