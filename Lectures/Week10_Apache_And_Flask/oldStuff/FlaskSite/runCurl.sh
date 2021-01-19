 #curl -X POST -F 'inputOne=hello' \
 #        -F 'inputTwo=world' \
 #        localhost:80


 curl -X PUT -H 'Content-Type: application/json' \
        -d '{"name": "Melvyn","age": 30}' \
        localhost/professor
