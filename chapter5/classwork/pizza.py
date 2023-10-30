import csv
Veggie = Pepperoni = Hawaiian = BBQ_Chicken = Margherita = 0

preferences = {"Veggie": Veggie,
"Pepperoni": Pepperoni,
"Hawaiian": Hawaiian,
"BBQ Chicken": BBQ_Chicken,
"Margherita": Margherita}


with open('Pizza_responce.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)
   for row in reader:
        preferences[row[1]] += 1
 
# Print counts
for house in preferences:
    print(f"{house}: {preferences[house]}")
