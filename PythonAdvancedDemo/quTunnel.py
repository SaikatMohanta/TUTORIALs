import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Define the dimensions of the grid
x = np.linspace(1.5e-15, 0.8e-15, 100)

# Define the Coulomb potential function
def coulomb_potential(x):
    return -1 / np.abs(x)

# Define the wavefunction
def wavefunction(x, t):
    k = 1.0  # Wavevector
    omega = 1.0  # Angular frequency
    psi_real = np.cos(k*x - omega*t)
    psi_imag = np.sin(k*x - omega*t)
    return psi_real, psi_imag

# Set up the figure and axes
fig, ax = plt.subplots()
line, = ax.plot(x, np.zeros_like(x))

# Animation update function
def update(frame):
    t = frame * 0.1  # Time parameter
    psi_real, psi_imag = wavefunction(x, t)
    psi_squared = np.abs(psi_real + 1j*psi_imag)**2  # Probability density
    V = coulomb_potential(x)  # Coulomb potential

    # Plot the wavefunction and potential
    line.set_data(x, psi_squared + V)
    ax.set_ylim(min(psi_squared + V), max(psi_squared + V))
    ax.set_title(f'Time: {t:.1f}')
    return line,

# Create the animation
animation = FuncAnimation(fig, update, frames=200, interval=50, blit=True)

# Show the animation
plt.show()

