from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "I Made Website With  Python + Flask + Linux + Apache2!"

@app.route("/returnsHTML")
def secondEndPoint():
    return """
<html>
	<body>
		<h1>What I learned about Linux this year:</h1>
		<h2>First thing I learned</h2>
		<p> TODO FILL ME IN </p>
		<h2>Second thing I learned</h2>
		<p> TODO FILL ME IN </p>
		<h2>Third thing I learned</h2>
		<p> TODO FILL ME IN </p>
	</body>
</html>
"""


if __name__ == "__main__":
    app.run()

