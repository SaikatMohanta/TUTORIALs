import numpy as np
import matplotlib.pyplot as plt

def wave_function(r, theta, phi):
    # Wave function for a hydrogen atom
    a0 = 1  # Bohr radius
    psi = (1 / (81 * np.sqrt(6 * np.pi))) * (np.exp(-r / (3 * a0)) / a0) * np.sin(theta) * np.exp(1j * phi)
    return np.abs(psi)**2

# Define the grid
r_vals = np.linspace(0, 10, 100)
theta_vals = np.linspace(0, np.pi, 100)
phi_vals = np.linspace(0, 2 * np.pi, 100)

# Calculate the wave function values for each point on the grid
prob_dist = np.zeros((len(r_vals), len(theta_vals), len(phi_vals)))
for i, r in enumerate(r_vals):
    for j, theta in enumerate(theta_vals):
        for k, phi in enumerate(phi_vals):
            prob_dist[i, j, k] = wave_function(r, theta, phi)

# Plot the probability distribution
R, Theta = np.meshgrid(r_vals, theta_vals)
X = R * np.sin(Theta)
Y = R * np.cos(Theta)
Z = np.sum(prob_dist, axis=2)

fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Probability')
ax.set_title('Hydrogen Atom Probability Distribution')
plt.show()

