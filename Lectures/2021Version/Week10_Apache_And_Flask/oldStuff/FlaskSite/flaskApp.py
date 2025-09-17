"""
This is a simple web application.
The site can:
    1. handle regular GET requests
    2. handle POST requests with form data
    3. handle a RESTFul GET
    4. handle a RESTful POST
"""

from flask import Flask, request
from flask_restful import Resource, Api

app = Flask(__name__)
api = Api(app)

#
# Example 1
#

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        input1 = request.form['inputOne']
        input2 = request.form['inputTwo']
        return 'You POSTed:' + input1 + " and " + input2 + "\n"
    else:
        return 'Hello,World!'

#
# Example 2
#
students = []

class Student(Resource):
    def get(self, name):
        for s in students:
            if s['name'] == name:
                return s, 200
        return {"student": None}, 404

    def post(self, name):
        new_student = {'name': name }
        students.append( new_student )
        return new_student, 201

api.add_resource( Student, '/student/<string:name>')

#
# Example 3
#
professor = {'name': None, 'age': None}

class Professor(Resource):
    def get(self):
        return professor, 200

    def put(self):
        data = request.get_json()
        professor['name']  = data['name']
        professor['age'] = data['age']
        return professor, 201

api.add_resource( Professor, '/professor')

app.run(host='0.0.0.0', port=80)
