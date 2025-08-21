import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the parameters for the black hole
M = 1.989e30  # Mass of the black hole in kg
c = 299792458  # Speed of light in m/s
G = 6.67430e-11  # Gravitational constant in m^3/kg/s^2

# Define the grid in spherical coordinates
theta_vals = np.linspace(0, np.pi, 100)
phi_vals = np.linspace(0, 2 * np.pi, 100)
theta, phi = np.meshgrid(theta_vals, phi_vals)

# Calculate the Schwarzschild radius
r_schwarz = (2 * G * M) / (c ** 2)

# Calculate the radial distance from the black hole
r = np.linspace(r_schwarz, 10 * r_schwarz, 100)

# Calculate the spacetime metric components (Schwarzschild metric)
t = r_schwarz + (r * (c ** 2 / (2 * G * M))) * np.log(r / r_schwarz - 1)
x = r * np.sin(theta) * np.cos(phi)
y = r * np.sin(theta) * np.sin(phi)
z = r * np.cos(theta)

# Plot the spacetime curvature
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, z, cmap='viridis')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Spacetime Curvature outside a Non-Rotating Black Hole')
plt.show()

