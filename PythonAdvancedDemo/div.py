import numpy as np
from mayavi import mlab

# Define the dimensions of the grid
x, y, z = np.mgrid[-5:5:20j, -5:5:20j, -5:5:20j]

# Define the vector field components (example: divergence of a dipole)
vx = x / (x**2 + y**2 + z**2)**(3/2)
vy = y / (x**2 + y**2 + z**2)**(3/2)
vz = z / (x**2 + y**2 + z**2)**(3/2)

# Calculate the divergence of the vector field
divergence = np.gradient(vx)[0] + np.gradient(vy)[1] + np.gradient(vz)[2]

# Create the 3D figure and visualization
figure = mlab.figure(size=(800, 600))
mlab.quiver3d(x, y, z, vx, vy, vz, scalars=divergence, colormap='bwr')

# Set the visualization properties
mlab.axes()
mlab.colorbar(title='Divergence')
mlab.view(azimuth=45, elevation=45, distance=10)

# Animate the figure
mlab.animate()

# Display the animation
mlab.show()

