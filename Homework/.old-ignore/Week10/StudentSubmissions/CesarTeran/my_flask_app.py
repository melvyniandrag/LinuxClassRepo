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
		<h1>What I learned about sed</h1>
		<p><a href="https://www.grymoire.com/Unix/Sed.html">I learned it all here!</a> 
		<h2>First thing I learned</h2>
		<p> "sed" is a program that makes changes to files </p>
		<h2>Second thing I learned</h2>
		<p> Just like python "#" are used for comments and not used as part of the program </p>
		<h2>Third thing I learned</h2>
		<p> using word boundaries to delete other paths </p>
	</body>
</html>
"""


if __name__ == "__main__":
    app.run()

