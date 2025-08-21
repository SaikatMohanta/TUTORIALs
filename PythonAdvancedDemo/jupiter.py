import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

# Define the Lane-Emden equation as a system of first-order ODEs
def lane_emden(theta, xi):
    dtheta_dxi = theta[1]
    d2theta_dxi2 = -2 * theta[1] / xi - theta[0]**n
    return [dtheta_dxi, d2theta_dxi2]

# Parameters for Jupiter
n = 1.7  # Polytropic index (for an ideal monoatomic gas, n = 3/2)
xi_max = 2.0  # Maximum scaled radius (adjust as needed)

# Initial conditions
theta0 = 1.0
dtheta0_dxi = 0.0
initial_conditions = [theta0, dtheta0_dxi]

# Generate the scaled radius values
xi_values = np.linspace(1e-6, xi_max, 1000)

# Solve the Lane-Emden equation
theta_solution = odeint(lane_emden, initial_conditions, xi_values)

# Extract the dimensionless density (rho/rho_c) and pressure (p/p_c)
rho_over_rho_c = theta_solution[:, 0]
p_over_p_c = theta_solution[:, 0]**n

# Plot the density profile
plt.figure(figsize=(10, 5))
plt.plot(xi_values, rho_over_rho_c, label=r'$\rho/\rho_c$')
plt.xlabel(r'Scaled Radius $\xi$')
plt.ylabel(r'Dimensionless Density $\rho/\rho_c$')
plt.title('Density Profile of a Gas Planet (Jupiter-like)')
plt.grid()
plt.legend()
plt.show()

# Plot the pressure profile
plt.figure(figsize=(10, 5))
plt.plot(xi_values, p_over_p_c, label=r'$p/p_c$')
plt.xlabel(r'Scaled Radius $\xi$')
plt.ylabel(r'Dimensionless Pressure $p/p_c$')
plt.title('Pressure Profile of a Gas Planet (Jupiter-like)')
plt.grid()
plt.legend()
plt.show()

