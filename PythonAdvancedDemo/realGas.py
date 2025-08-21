import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

# Define the number of atoms and the number of frames
num_atoms = 100
num_frames = 500

# Define the limits of the animation
xlim = (-10, 10)
ylim = (-10, 10)
zlim = (-10, 10)

# Define the van der Waals constants
a = 1.4
b = 0.8

# Initialize the positions and velocities of the atoms
positions = np.random.uniform(low=[xlim[0], ylim[0], zlim[0]], high=[xlim[1], ylim[1], zlim[1]], size=(num_atoms, 3))
velocities = np.random.normal(loc=0, scale=0.1, size=(num_atoms, 3))

# Create the figure and 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Create the scatter plot for the atoms
scatter = ax.scatter(positions[:, 0], positions[:, 1], positions[:, 2])

# Update function to be called for each frame
def update(frame):
    global positions, velocities
    
    # Update the positions based on the velocities
    positions += velocities
    
    # Apply van der Waals forces between the atoms
    for i in range(num_atoms):
        for j in range(i + 1, num_atoms):
            dx = positions[j, 0] - positions[i, 0]
            dy = positions[j, 1] - positions[i, 1]
            dz = positions[j, 2] - positions[i, 2]
            distance = np.sqrt(dx ** 2 + dy ** 2 + dz ** 2)
            
            # Calculate the van der Waals force
            force = (a / distance ** 2) - (b / distance ** 3)
            
            # Update the velocities based on the force
            velocities[i] += force * (dx / distance)
            velocities[j] -= force * (dx / distance)
    
    # Check for collisions with the walls and reverse the velocity if a collision occurs
    for i in range(num_atoms):
        for j in range(3):
            if positions[i, j] < xlim[0] or positions[i, j] > xlim[1]:
                velocities[i, j] *= -1
            if positions[i, j] < ylim[0] or positions[i, j] > ylim[1]:
                velocities[i, j] *= -1
            if positions[i, j] < zlim[0] or positions[i, j] > zlim[1]:
                velocities[i, j] *= -1
    
    # Update the scatter plot data with the new positions
    scatter._offsets3d = (positions[:, 0], positions[:, 1], positions[:, 2])

# Set the limits of the 3D plot
ax.set_xlim3d(xlim)
ax.set_ylim3d(ylim)
ax.set_zlim3d(zlim)

# Create the animation
animation = FuncAnimation(fig, update, frames=num_frames, interval=50)

# Show the animation
plt.show()

