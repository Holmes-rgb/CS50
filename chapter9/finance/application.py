# Luke Holmes

# Sources:
# https://www.sqlitetutorial.net/sqlite-python/insert/
# https://getbootstrap.com/docs/5.0/content/tables/
# https://www.w3schools.com/html/html_form_input_types.asp
# https://www.programiz.com/python-programming/datetime/current-datetime
# https://stackoverflow.com/questions/20457038/how-to-round-to-2-decimals-with-python
# https://www.w3schools.com/python/ref_string_isnumeric.asp


import os
from datetime import datetime
from datetime import date

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # get the stocks that have been bought
    stocks = db.execute("SELECT * FROM stocks WHERE id = ?", session["user_id"])

    # slect the cash that the user has
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

    # get the dictionary out of the list
    cash = cash[0]

    # get the key out of the dictionary
    cash = cash["cash"]

    # set total value of stocks to 0
    stotal = 0
    # run through each stock price and multiply it by the number of that stock
    for stock in stocks:
        stotal += (lookup(stock['symbol']))['price'] * stock['number']
        stock['price'] = (lookup(stock['symbol']))['price']

    # return all of the calculated data to the html
    return render_template("index.html", stocks=stocks, cash=cash, stotal=stotal)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # if the use clicked the buy button
    if request.method == "POST":
        # ensure that a symbol has been entered
        if not request.form.get("symbol"):
            return apology("must provide ticker symbol", 400)

        # ensure that a number of shares has been entered
        if not request.form.get("shares"):
            return apology("must provide # of shares", 400)

        # ensure that the symbol is valid
        if not lookup(request.form.get("symbol")):
            return apology("must provide enter valid symbol", 400)

        # see if the # of shares is a number
        if not request.form.get("shares").isnumeric():
            return apology("must provide valid # of shares", 400)

        # ensure that the number of shares in greater than 0
        if (float(request.form.get("shares")) < 0):
            return apology("must provide positive # of shares", 400)

        if not float(request.form.get("shares")):
            return apology("must provide valid # of shares", 400)

        # get the symbol from the form
        stock = lookup(request.form.get("symbol"))
        # get the cash that the user has
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        # escape the weird format
        cash = cash[0]
        cash = cash["cash"]

        # calculate new amount of cash
        cash = cash - (stock["price"] * float(request.form.get("shares")))

        # make sure that new amount of cash is more than 0
        if (cash < 0):
            return apology("You do not have enough money", 400)

        else:
            # update database with new amount of cash
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

            # insert the new stock in to the database
            db.execute("INSERT INTO stocks(id, symbol, time, price, number) VALUES(?, ?, ?, ?, ?)",
                       session["user_id"], stock["symbol"], datetime.now(), stock["price"], request.form.get("shares"))
            return redirect("/")

    else:
        # if buy button was not pressed render the page
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # if button clicked
    if request.method == "POST":

        # make sure symbol was entered
        if not request.form.get("symbol"):
            return apology("must provide Ticker Symbol", 400)

        # make sure symbol is valid
        if not lookup(request.form.get("symbol")):
            return apology("must provide valid Ticker Symbol", 400)

        # returne page with quote information passed to it
        return render_template("quoted.html", name=lookup(request.form.get("symbol")))

    else:
        # if button not clicked render quote page
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure that the confirmation was entered
        elif not request.form.get("confirmation"):
            return apology("must re-enter password", 400)

        # Ensure that the confirmation matches the password
        elif request.form.get("confirmation") != request.form.get("password"):
            return apology("must passwords must match", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username and password does not exist
        if len(rows) >= 1:
            return apology("username taken", 400)

        # Add new user to the database
        db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", request.form.get(
            "username"), generate_password_hash(request.form.get("password")))

        # Remember which user has logged in
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
