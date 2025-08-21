import pygame
import math

# Initialize Pygame
pygame.init()

# Set up the window dimensions
width, height = 1200, 700
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Gravitational Interaction Simulation")

# Define colors
BLACK = (0, 0, 1)

# Define the class for the massive bodies
class Body:
    def __init__(self, x, y, mass):
        self.x = x
        self.y = y
        self.mass = mass
        self.radius = math.sqrt(mass / math.pi)

    def draw(self):
        pygame.draw.circle(window, BLACK, (int(self.x), int(self.y)), int(self.radius))

# Define the gravitational constant
G = 0.0001

# Define the bodies
body1 = Body(50, 3000, 5000)
body2 = Body(150, 3000, 2000)
body3 = Body(300, 300, 1800)

# Define the initial velocities of the bodies
body1.vx, body1.vy = 0, 0
body2.vx, body2.vy = 0, 0
body3.vx, body3.vy = 0, 0

# Define the animation loop
running = True
while running:
    window.fill((255, 255, 255))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Calculate the gravitational forces acting on each body
    dx1 = body2.x - body1.x
    dy1 = body2.y - body1.y
    distance1 = math.sqrt(dx1 ** 2 + dy1 ** 2)
    fx1 = G * body1.mass * body2.mass * dx1 / (distance1 ** 3)
    fy1 = G * body1.mass * body2.mass * dy1 / (distance1 ** 3)

    dx2 = body3.x - body1.x
    dy2 = body3.y - body1.y
    distance2 = math.sqrt(dx2 ** 2 + dy2 ** 2)
    fx2 = G * body1.mass * body3.mass * dx2 / (distance2 ** 3)
    fy2 = G * body1.mass * body3.mass * dy2 / (distance2 ** 3)

    dx3 = body3.x - body2.x
    dy3 = body3.y - body2.y
    distance3 = math.sqrt(dx3 ** 2 + dy3 ** 2)
    fx3 = G * body2.mass * body3.mass * dx3 / (distance3 ** 3)
    fy3 = G * body2.mass * body3.mass * dy3 / (distance3 ** 3)

    # Update the velocities of the bodies
    body1.vx += fx1 / body1.mass + fx2 / body1.mass
    body1.vy += fy1 / body1.mass + fy2 / body1.mass

    body2.vx += -fx1 / body2.mass + fx3 / body2.mass
    body2.vy += -fy1 / body2.mass + fy3 / body2.mass

    body3.vx += -fx2 / body3.mass - fx3 / body3.mass
    body3.vy += -fy2 / body3.mass+ fy3 / body3.mass

    # Update the positions of the bodies
    body1.x += body1.vx
    body1.y += body1.vy

    body2.x += body2.vx
    body2.y += body2.vy

    body3.x += body3.vx
    body3.y += body3.vy

    # Draw the bodies
    body1.draw()
    body2.draw()
    body3.draw()

    # Update the display
    pygame.display.update()

# Quit Pygame
pygame.quit()

