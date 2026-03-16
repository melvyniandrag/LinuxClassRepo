#!/usr/bin/env bash
# Usage:  bash chat_client.sh -s "192.1.1.2" -p 5000 -u "melvyn drag"
# OR if you mkae it executable ( wait for the lecture on changing permissions )
# Usage: ./chat_client.sh -s "192.1.1.2" -p 5000 -u "melvyn drag"

server=""
username=""
port=""

# s: means s taks an argument
# p: means p taks an argument
# u: means u taks an argument
while getopts "s:u:p:" opt; do
  case ${opt} in
    s ) server=$OPTARG ;;
    u ) username=$OPTARG ;;
    p ) port=$OPTARG ;;
    \? ) echo "Usage: cmd [-s server_ip] [-p port] [-u user_name]" >&2; exit 1 ;;
  esac
done

# Would be nice to do:
# make the options mandatory!


echo "Chat Server IP: $server"
echo "Chat Server Port: $port"
echo "User: $username"

while read MESSAGE; do
        echo "[$username]: $MESSAGE"
done | ncat $server $port | sed "s/<user[0-9]\+> //g"