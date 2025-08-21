from vpython import *
import random
import math

# Set up the scene
scene = canvas(width=800, height=600)

# Set the number of photons
num_photons = 100

# Set the size of the box
box_size = 10

# Set the animation properties
dt = 0.01  # Time step
c = 1.0  # Speed of light (scaled for visualization)

# Create a list to store the photons
photons = []

# Create the photons
for _ in range(num_photons):
    photon = sphere(pos=vector(0, 0, 0),
                    radius=0.05, color=color.red)
    theta = random.uniform(0, 2 * math.pi)
    phi = random.uniform(0, math.pi)
    photon.velocity = vector(math.sin(phi) * math.cos(theta),
                             math.sin(phi) * math.sin(theta),
                             math.cos(phi))
    photons.append(photon)

# Create an animation loop
while True:
    rate(100)  # Number of animation updates per second

    # Update the positions of the photons
    for photon in photons:
        photon.pos += photon.velocity * c * dt

        # Scale the photon's position for visualization
        scaled_pos = photon.pos * (box_size/2)

        # Handle boundary conditions
        if abs(scaled_pos.x) > box_size/2 or abs(scaled_pos.y) > box_size/2 or abs(scaled_pos.z) > box_size/2:
            photon.pos = vector(0, 0, 0)  # Reset photon position
            theta = random.uniform(0, 2 * math.pi)
            phi = random.uniform(0, math.pi)
            photon.velocity = vector(math.sin(phi) * math.cos(theta),
                                     math.sin(phi) * math.sin(theta),
                                     math.cos(phi))  # Generate new random velocity

