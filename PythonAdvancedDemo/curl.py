import numpy as np
from mayavi import mlab

# Define the dimensions of the grid
x, y, z = np.mgrid[-5:5:20j, -5:5:20j, -5:5:20j]

# Define the vector field components (example: curl of a dipole)
vx = y / (x**2 + y**2 + z**2)**(3/2) - 3 * (x * (x * z) + y * (y * z) + z**3) / (x**2 + y**2 + z**2)**(5/2)
vy = -x / (x**2 + y**2 + z**2)**(3/2) + 3 * (x**3 + y**3 + z * (x**2 + y**2)) / (x**2 + y**2 + z**2)**(5/2)
vz = 3 * z**2 / (x**2 + y**2 + z**2)**(5/2) - 1 / (x**2 + y**2 + z**2)**(3/2)

# Calculate the curl of the vector field
curl_x = np.gradient(vz, y, axis=1) - np.gradient(vy, z, axis=2)
curl_y = np.gradient(vx, z, axis=2) - np.gradient(vz, x, axis=0)
curl_z = np.gradient(vy, x, axis=0) - np.gradient(vx, y, axis=1)

# Create the 3D figure and visualization
figure = mlab.figure(size=(800, 600))
mlab.quiver3d(x, y, z, curl_x, curl_y, curl_z, colormap='bwr')

# Set the visualization properties
mlab.axes()
mlab.colorbar(title='Curl')
mlab.view(azimuth=45, elevation=45, distance=10)

# Animate the figure
mlab.animate()

# Display the animation
mlab.show()

