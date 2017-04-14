#!/usr/bin/python

import sys
import cgi
import csv
import math
import urllib2
import ctypes

def success():

	f = open('resources.csv', 'rb')
	reader = csv.reader(f)
	for row in reader:
		rdata = row
	f.close()
	rmana = rdata[0]
	rgp = rdata[1]
	rocc = rdata[2]

	f = open('resources.csv', 'r+')
	f.seek(0)
	f.write(rmana)
	f.write(',')
	f.write(rgp)
	f.write(',0')
	#f.truncate()
	f.close()

	print "Content-type: text/html\n\n"
	print "<html>"
	print "<head>"
	print "<title> Teleporting </title>"
	print "</head>"
	print "<body>"
	print "</body>"
	print "</html>"

success()
