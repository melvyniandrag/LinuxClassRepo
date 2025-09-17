"""
Code stolen here:

https://gist.github.com/bradmontgomery/2219997#file-dummy-web-server-py

and then modified to be more directly relatable to our lecture.
"""

from http.server import HTTPServer, BaseHTTPRequestHandler

class MyFirstServer(BaseHTTPRequestHandler):
		def _set_headers(self):
				self.send_response(200)
				self.send_header("Content-type", "text/html")
				self.end_headers()

		def _html(self, message):
				content = "<html>\n\t<body>\n\t\t<h1>{}</h1>\n\t\t<p> Hi </p>\n\t</body>\n</html>\n".format(message)
				return content.encode("utf8")	# NOTE: must return a bytes object!

		def do_GET(self):
				self._set_headers()
				self.wfile.write(self._html("Received GET!"))

		def do_POST(self):
				content_length = int(self.headers['Content-Length'])
				post_data = self.rfile.read(content_length)
					
				self._set_headers()
				self.wfile.write(self._html("Received POST!" + post_data.decode("utf8")))

if __name__ == "__main__":
		addr = "127.0.0.1"
		#addr = "localhost"
		port = 8000
		server_address = (addr, port)
		httpd = HTTPServer(server_address, MyFirstServer)

		print("Starting httpd server on {}:{}".format(addr, port))
		httpd.serve_forever()
