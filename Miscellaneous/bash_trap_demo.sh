#!/bin/bash
set -e  # exit on any error

TMP=/tmp/mytmp
mkdir -p "$TMP"

#Cleanup temporary folder on exit (normal or error)
trap 'rm -rf "$TMP"' EXIT

#Log any failing command 
# Note LINENO and BASH_COMMAND env vars.
# LINENO holds the trapped line in the script, BASH_COMMAND is the command that was executing during the error.
trap 'echo "Error on line $LINENO: $BASH_COMMAND" >&2' ERR

# Script commands
chmod 644 somefile.txt
cp source.txt dest.txt
echo "All done"
