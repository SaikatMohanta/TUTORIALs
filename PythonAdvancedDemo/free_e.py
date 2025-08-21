import numpy as np
import matplotlib.pyplot as plt

# Define the parameters
L = 10  # Length of the system
N = 1000  # Number of points
x = np.linspace(0, L, N)  # Positions

# Define the wavefunction
psi = np.sqrt(2/L) * np.sin(np.pi*x/L)

# Plot the wavefunction
plt.plot(x, psi, color='b', label='Wavefunction')
plt.xlabel('Position')
plt.ylabel('Amplitude')
plt.title('Wavefunction of a Free Electron')
plt.legend()
plt.grid(True)
plt.show()

