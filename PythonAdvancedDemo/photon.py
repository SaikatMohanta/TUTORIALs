import numpy as np
import matplotlib.pyplot as plt

# Constants
hbar = 1.055e-34  # Reduced Planck's constant (J s)
c = 3e8  # Speed of light (m/s)
L = 1e-6  # Length of space to simulate (m)
dx = 1e-9  # Spatial step size (m)
dt = dx / (2 * c)  # Time step size (s)

# Create the spatial grid
x = np.arange(-L/2, L/2, dx)
N = len(x)

# Define the wave packet parameters
k0 = 5e6  # Central wave number (1/m)
sigma = 1e-7  # Standard deviation of the wave packet (m)

# Initialize the wave function
psi = np.exp(-0.5 * ((x - 0) / sigma) ** 2) * np.exp(1j * k0 * x)
psi /= np.sqrt(np.sum(np.abs(psi) ** 2) * dx)  # Normalize the wave function

# Define the potential function
V = np.zeros(N)

# Simulate the time evolution
t = 0
t_max = 5e-15  # Maximum simulation time (s)
while t < t_max:
    # Update the wave function using the finite difference method
    psi_new = np.zeros(N, dtype=np.complex128)
    for i in range(1, N - 1):
        psi_new[i] = psi[i] - 1j * dt * (hbar / (2 * dx ** 2)) * (psi[i+1] - 2 * psi[i] + psi[i-1]) + 1j * dt * V[i] * psi[i]
    psi = psi_new

    # Reflect wave function at boundaries (free ends)
    psi[0] = psi[-1] = 0

    # Update the time
    t += dt

# Plot the probability density
prob_density = np.abs(psi) ** 2
plt.plot(x, prob_density)
plt.xlabel('Position (m)')
plt.ylabel('Probability Density')
plt.title('Wave Function of a Photon')
plt.show()

