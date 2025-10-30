import math

height, velocity, acceleration = map(int, input().split())
height -= 5500

time = (-velocity + math.sqrt(velocity*velocity + 2*acceleration*height)) / acceleration
print(round(time))