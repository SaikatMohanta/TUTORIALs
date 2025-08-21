# Calculate the mean density to central density ratio
mean_density_ratio = (3 / xi[-1]**3) * np.trapz(theta * xi**2, xi)

# Print the result
print("Mean Density to Central Density Ratio for Jupiter:", mean_density_ratio)

