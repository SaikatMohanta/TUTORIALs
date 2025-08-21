import numpy as np
import matplotlib.pyplot as plt

# Define the parameters for the simulation
H0 = 70  # Hubble constant (km/s/Mpc)
Omega_DM = 0.3  # Dark matter density parameter
Omega_Lambda = 0.7  # Vacuum energy density parameter
t0 = 0  # Initial time (in Gyr)
t_end = 14  # End time (in Gyr)
delta_t = 0.01  # Time step (in Gyr)

# Define the scale factor
a = np.arange(1, t_end / delta_t + 1) * delta_t

# Calculate the energy density parameter Omega_R (radiation density parameter)
Omega_R = 1 - Omega_DM - Omega_Lambda

# Calculate the Hubble parameter H(t)
H = H0 * np.sqrt(Omega_DM * a ** -3 + Omega_R * a ** -4 + Omega_Lambda)

# Calculate the comoving radial distance (r(t))
r = np.cumsum(1 / (a * H))

# Plot the expansion of the universe
plt.plot(a, r)
plt.xlabel('Scale factor (a)')
plt.ylabel('Comoving radial distance (r)')
plt.title('Expansion of a Dark Matter-Filled Universe')
plt.grid(True)
plt.show()

