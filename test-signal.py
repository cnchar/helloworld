import signal, os, time

is_breaked = False

def handler(signum, frame):
	global is_breaked
	is_breaked = True
	print ('handler %d' % signum)

signal.signal(signal.SIGTERM, handler)

while not is_breaked:
    time.sleep(1)

print "exit main"
