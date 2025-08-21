from vpython import *
import random
import math

# Set up the scene
scene = canvas(width=800, height=600)

# Set the number of particles
num_particles = 250

# Set the size of the box
box_size = 18

# Set the animation properties
dt = 0.01  # Time step
scale_factor = 0.01  # Scaling factor for particle motion

# Create a list to store the particles
particles = []

# Create the particles
for _ in range(num_particles):
    particle = sphere(pos=vector(random.uniform(-box_size/2, box_size/2),
                                random.uniform(-box_size/2, box_size/2),
                                random.uniform(-box_size/2, box_size/2)),
                      radius=0.012, color=color.red)
    particle.velocity = vector(random.uniform(-1, 1),
                               random.uniform(-1, 1),
                               random.uniform(-1, 1))
    particles.append(particle)

# Create an animation loop
while True:
    rate(100)  # Number of animation updates per second

    # Update the positions of the particles
    for particle in particles:
        particle.pos += particle.velocity * scale_factor

        # Scale the particle's position for visualization
        scaled_pos = particle.pos * (box_size/2)

        # Handle boundary conditions
        if abs(scaled_pos.x) > box_size/2 or abs(scaled_pos.y) > box_size/2 or abs(scaled_pos.z) > box_size/2:
            particle.pos = vector(0, 0, 0)  # Reset particle position
            particle.velocity = vector(random.uniform(-1, 1),
                                       random.uniform(-1, 1),
                                       random.uniform(-1, 1))  # Generate new random velocity

