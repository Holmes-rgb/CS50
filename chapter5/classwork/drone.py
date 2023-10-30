# Include relevant libraries
from cs50 import get_string
import math

# A dictionary with the names of locations and their coordinates per the grid
locations = {
    "Hanover High School": (43, 2),
    "Baker Library": (30, 21),
    "Lou's Restaurant and Bakery": (29, 10),
    "Collis Center": (26, 14),
    "Ramountos": (31, 5),
    "Memorial Field": (40, 9),
    "Thompson Arena": (49, 9),
    "Shattuck Observatory": (36, 22),
    "Black Family Visual Arts Center": (33, 10),
    "Ledyard Bridge": (3, 17),
    "Zimmerman Fitness Center": (39, 15),
    "Tuk Tuk Thai Cuisine": (27, 12)
}

# Get two locations to fly between
while True:
    location1 = get_string("What is the first location? \n")

    # Ensure first location is in the dictionary
    if location1 not in locations.keys():
        print("Location not found")
    else:
        break

while True:
    location2 = get_string("What is the second location? \n")

    # Ensure second location is in the dictionary and a different location
    if location2 not in locations.keys():
        print("Location not found")
    elif location2 == location1:
        print("Location is not new")
    else:
        break

# Calculate the distance
sqrdistance = math.sqrt(((locations[location2][0] - locations[location1][0]) ** 2) + ((locations[location2][1] - locations[location1][1]) ** 2))
distance = round(((sqrdistance * 98) / 5280), 3)
# Print the distance
print(distance, "miles")