from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    activities = [
                {"name":"Archery", "size":12, "requirements": True, "description":"Open for people trying to shoot for their silver, gold or platinum"},
        {"name":"Arts", "size":21, "requirements": False, "description":"Start a new bracelet or work on your bead projects"},
        {"name":"Boating", "size":18, "requirements": True, "description":"Kayaking up Snake River this afternoon! Must be at least a bobcat to sign up"},
        {"name":"Drama", "size":15, "requirements": False, "description":"Practicing the play and maybe playing some park bench at the end. "},
        {"name":"Field sports", "size":30, "requirements": False, "description":"Street Hockey and Dodgeball"},
        {"name":"Swimming", "size":10, "requirements": True, "description":"Swimming across the lake today, must be in level 5 swimming to sign up. Get ready for a workout!"}
        ]
    return render_template("index.html", activities=activities)
