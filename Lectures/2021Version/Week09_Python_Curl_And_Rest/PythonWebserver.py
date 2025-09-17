"""
Run this by typing 
"""

import SocketServer
import SimpleHTTPServer
import re

PORT = 9000

class CustomHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
    def do_GET(self):
        if None != re.search('/api/square/*', self.path):
            num = float(self.path.split('/')[-1])
            print self.path.split('/')
            #This URL will trigger our sample function and send what it returns back to the browser
            self.send_response(200)
            self.send_header('Content-type','text/html')
            self.end_headers()
            self.wfile.write(str(num*num)) #call sample function here
            return
        if None != re.search('/api/mult/*', self.path):
            num1 = float(self.path.split('/')[-1])
            num2 = float(self.path.split('/')[-2])
            #This URL will trigger our sample function and send what it returns back to the browser
            self.send_response(200)
            self.send_header('Content-type','text/html')
            self.end_headers()
            self.wfile.write(str(num1*num2)) #call sample function here
            return
        else:
            #serve files, and directory listings by following self.path from
            #current working directory
            SimpleHTTPServer.SimpleHTTPRequestHandler.do_GET(self)
		
	def do_POST(self):
			# Doesn't do anything with posted data
			content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
			post_data = self.rfile.read(content_length) # <--- Gets the data itself
			self._set_headers()
			self.wfile.write("<html><body><h1>POST!</h1></body></html>")
			return

httpd = SocketServer.ThreadingTCPServer(('', PORT),CustomHandler)

print "serving at port", PORT
httpd.serve_forever()
