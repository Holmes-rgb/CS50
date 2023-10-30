# Implements a registration form using a select menu

from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

GRADE = [
    "9th",
    "10th",
    "11th",
    "12th",
    "Staff"
    ]

INTENCITY = [
    "Easy",
    "Medium",
    "Hard"
    ]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS, gradelevel=GRADE, intensitylevel=INTENCITY)


@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    if not request.form.get("firstname") or not request.form.get("lastname") or not request.form.get("email") or request.form.get("sport") not in SPORTS or request.form.get("gradelevel") not in GRADE or request.form.get("intensitylevel") not in INTENCITY or len(request.form.get("phonenumber")) != 10:
        return render_template("failure.html")

    # Confirm registration
    return render_template("success.html")
