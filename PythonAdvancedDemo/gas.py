from vpython import *
import random

# Set up the scene
scene = canvas(width=800, height=600)

# Set the number of atoms
num_atoms = 100

# Set the size of the box
box_size = 10

# Create a list to store the atoms
atoms = []

# Create the atoms
for _ in range(num_atoms):
    atom = sphere(pos=vector(random.uniform(-box_size/2, box_size/2),
                             random.uniform(-box_size/2, box_size/2),
                             random.uniform(-box_size/2, box_size/2)),
                  radius=0.2, color=color.red)
    atom.velocity = vector(random.uniform(-1, 1),
                           random.uniform(-1, 1),
                           random.uniform(-1, 1))
    atoms.append(atom)

# Set the animation properties
dt = 0.01  # Time step

# Create an animation loop
while True:
    rate(100)  # Number of animation updates per second

    # Update the positions of the atoms
    for atom in atoms:
        atom.pos += atom.velocity * dt

        # Handle boundary conditions
        if atom.pos.x > box_size/2 or atom.pos.x < -box_size/2:
            atom.velocity.x *= -1
        if atom.pos.y > box_size/2 or atom.pos.y < -box_size/2:
            atom.velocity.y *= -1
        if atom.pos.z > box_size/2 or atom.pos.z < -box_size/2:
            atom.velocity.z *= -1

