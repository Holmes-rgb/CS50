# TODO
import csv
from cs50 import SQL

db = SQL("sqlite:///students.db")


with open("characters.csv", "r") as file:
    reader = csv.dictreader(file)

    for row in reader:
        fullname = row["name"].split(" ")
        if len(fullname) == 2:
            first = fullname[0]
            middle = None
            last = fullname[1]
            
        else:
            first = fullname[0]
            middle = fullname[1]
            last = fullname[2]
        
        db.execute("INSERT INTO students (first, middle, last) VALUES(?, ?, ?, ?, ?)",first, middle, last, row["house"], row["birth"])
