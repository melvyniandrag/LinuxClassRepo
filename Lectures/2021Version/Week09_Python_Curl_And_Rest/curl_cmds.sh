# curl -H "Authorization: token  19f4cdc2343c4745e64aa313c38ea033ca8d00b0" \
#	-d '{ \
#			"name": "fakerepo", \
#			"auto_init": true, \
#			"private": true \
#			"gitignore_template": "nanoc" \
#		}' \
#	https://api.github.com/user/repos

TOKEN=19f4cdc2343c4745e64aa313c38ea033ca8d00b0

curl -i -H "Authorization: token $TOKEN" \
    -d '{ 
        "name": "blog", 
        "auto_init": true, 
        "private": false, 
        "gitignore_template": "nanoc" 
      }' \
    https://api.github.com/user/repos
