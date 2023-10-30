from cs50 import get_int
while True:
    # prompts user for proper input
    num = get_int("Height: \n")
    if(num >= 1 and num < 9):
        break

for i in range(num):
    # prints spaces before the hashes
    for j in range(num - (i + 1)):
        print(" ", end='')
    # prints out hashes
    for j in range(i + 1):
        print("#", end='')
    # prints return after line
    print()