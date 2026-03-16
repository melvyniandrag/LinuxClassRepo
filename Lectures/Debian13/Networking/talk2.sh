echo "give me your name"

read name

echo "hello, ${name}"

while read MESSAGE; do
        echo "[$name]: $MESSAGE"
done | nc 167.172.159.73 5000 | sed "s/<user[0-9]\+> //g"
