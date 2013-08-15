import sys

class writer(object):
	def __init__(self):
		self.log = []
	def write(self, data):
		self.log.append(data)
	def __del__(self):
		f = open('err.log', 'w+')
		for line in self.log:
			f.write(line)
		f.close()

sys.stderr = writer()

a = 1/0


