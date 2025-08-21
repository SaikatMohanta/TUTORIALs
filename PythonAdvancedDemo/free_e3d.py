import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the dimensions of the grid
x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
z = np.linspace(-5, 5, 100)

# Create a 3D grid
X, Y, Z = np.meshgrid(x, y, z)

# Calculate the probability density
psi = np.sqrt(X**2 + Y**2 + Z**2)

# Create the 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the probability density
ax.scatter(X, Y, Z, c=psi, cmap='jet', s=1)

# Set the plot labels and title
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D Quantum System - Free Electron')

# Show the plot
plt.show()

