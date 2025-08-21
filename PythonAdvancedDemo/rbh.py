import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the parameters for the rotating black hole
M = 1.989e30  # Mass of the black hole in kg
a = 0.5 * M  # Spin parameter (angular momentum per unit mass)
c = 299792458  # Speed of light in m/s
G = 6.67430e-11  # Gravitational constant in m^3/kg/s^2

# Define the grid in spherical coordinates
theta_vals = np.linspace(0, np.pi, 100)
phi_vals = np.linspace(0, 2 * np.pi, 100)
theta, phi = np.meshgrid(theta_vals, phi_vals)

# Calculate the Kerr radius
r_kerr = G * M / (c ** 2)

# Calculate the radial distance from the black hole
r = np.linspace(r_kerr, 10 * r_kerr, 100)

# Calculate the spacetime metric components (Kerr metric)
t = r + (r_kerr * (r / (r ** 2 + a ** 2) - 1))
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
ax.set_title('Spacetime Curvature outside a Rotating Black Hole')
plt.show()

