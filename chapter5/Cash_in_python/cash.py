from cs50 import get_float
while True:
    # prompts user for proper input
    change = get_float("How much change is owed? \n")
    if(change >= 0):
        break
    
cents = round(change * 100)
coins = 0

quarters = int(cents / 25)
dime = int((cents % 25) / 10)
nickels = int(((cents % 25) % 10) / 5)
pennies = int(((cents % 25) % 10) % 5)

coins = coins + quarters
if dime > 0:
    coins = coins + dime
if nickels > 0:
    coins = coins + nickels
if pennies > 0:
    coins = coins + pennies

print(coins)