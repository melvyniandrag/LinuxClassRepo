#!/usr/bin/env python
"""
Very simple HTTP server in python (Updated for Python 3.7)

Usage:

		./dummy-web-server.py -h
		./dummy-web-server.py -l localhost -p 8000

Send a GET request:

		curl http://localhost:8000

Send a HEAD request:

		curl -I http://localhost:8000

Send a POST request:

		curl -d "foo=bar&bin=baz" http://localhost:8000


Some tips about curl usage
https://gist.github.com/subfuzion/08c5d85437d5d4f00e58

Heres where this code came from 
https://gist.githubusercontent.com/bradmontgomery/2219997/raw/256b09ce3d6639c9fb325eaf92d79fb709f51e32/dummy-web-server.py

And see the comment here:
https://gist.github.com/bradmontgomery/2219997#file-dummy-web-server-py


>> Just one thing to add to it, if you want access to the POSTed data you do so like this:

	def do_POST(self):
					# Doesn't do anything with posted data
					content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
					post_data = self.rfile.read(content_length) # <--- Gets the data itself
					self._set_headers()
					self.wfile.write("<html><body><h1>POST!</h1></body></html>")

"""
import argparse
from http.server import HTTPServer, BaseHTTPRequestHandler


class S(BaseHTTPRequestHandler):
		def _set_headers(self):
				self.send_response(200)
				self.send_header("Content-type", "text/html")
				self.end_headers()

		def _html(self, message):
				"""This just generates an HTML document that includes `message`
				in the body. Override, or re-write this do do more interesting stuff.

				"""
				content = f"<html><body><h1>{message}</h1></body></html>"
				return content.encode("utf8")	# NOTE: must return a bytes object!

		def do_GET(self):
				self._set_headers()
				self.wfile.write(self._html("hi!"))

		def do_HEAD(self):
				self._set_headers()

		def do_POST(self):
				# Doesn't do anything with posted data
				self._set_headers()
				content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
				post_data = self.rfile.read(content_length) # <--- Gets the data itself
				self.wfile.write(self._html("POST!"))
				self.wfile.write(self._html(post_data))


def run(server_class=HTTPServer, handler_class=S, addr="localhost", port=8000):
		server_address = (addr, port)
		httpd = server_class(server_address, handler_class)

		print(f"Starting httpd server on {addr}:{port}")
		httpd.serve_forever()


if __name__ == "__main__":

		parser = argparse.ArgumentParser(description="Run a simple HTTP server")
		parser.add_argument(
				"-l",
				"--listen",
				default="localhost",
				help="Specify the IP address on which the server listens",
		)
		parser.add_argument(
				"-p",
				"--port",
				type=int,
				default=8000,
				help="Specify the port on which the server listens",
		)
		args = parser.parse_args()
		run(addr=args.listen, port=args.port)
