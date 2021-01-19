from flask import Flask
app = Flask(__name__)
@app.route("/")
def hello():
    return "I Made Website With  Python + Flask + Linux + Apache2!"
if __name__ == "__main__":
    app.run()

