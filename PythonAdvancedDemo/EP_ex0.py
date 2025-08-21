import numpy as np
import matplotlib.pyplot as plt

# Define the mass of the black hole and the gravitational constant
M = 3.8e33  # Mass of the black hole in kg
G = 6.67430e-11  # Gravitational constant in m^3 kg^−1 s^−2

# Define the coordinates for the plot
r_vals = np.linspace(-1000, 1000, 100)  # Radial distance values
theta_vals = np.linspace(0, np.pi, 100)  # Polar angle values

# Create a meshgrid of coordinates
R, Theta = np.meshgrid(r_vals, theta_vals)

# Calculate the Schwarzschild radius
Rs = 2 * G * M / (299792458 ** 2)  # Speed of light squared

# Calculate the Schwarzschild metric tensor components
g_tt = -(1 - Rs / R)
g_rr = 1 / (1 - Rs / R)
g_theta_theta = R ** 2
g_phi_phi = R ** 2 * np.sin(Theta) ** 2

# Plot the distortion of spacetime
fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(R * np.sin(Theta), R * np.cos(Theta), g_tt, cmap='viridis')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('g_tt')
ax.set_title('Schwarzschild Metric: g_tt Component')
plt.show()

