import csv
 
answer = input("What is your favorite food? ").lower()

with open("foods.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        if [i for i in range(len(row)) if answer in row[i]]:
            name = row[0]
            print(f"You have the same favorite food as {name}!")
