import csv,sys
titles = {}

# Open CSV file
with open("tv.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)




    # Iterate over CSV, printing each title
    for row in reader:
        title = row["title"].strip().upper()
        if title in titles:
            titles[title] += 1
        else:
            titles[title] = 1

def f(title):
    return titles[title]

for title in sorted(titles, key=f, reverse=True):
    print(title, titles[title])