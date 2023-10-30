# import libraries
from cs50 import SQL, get_string

# Open a connection to the database
db = SQL("sqlite:///shows.db")

# Prompt user for title
title = get_string("Get me a title!")

# Canoncalize input
title = title.upper().strip()

# Search for title using query that will provide the count
popularity = db.execute("SELECT COUNT(title) AS counter FROM shows WHERE title = ?",title)

# Print popularity of title
print(popularity[0]["counter"])