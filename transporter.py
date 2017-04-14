#!/usr/bin/python

import sys
import cgi
import csv
import math
import urllib2
import ctypes
import string

def transporter():

	#read from csv
	f = open('resources.csv', 'rb')
	reader = csv.reader(f)
	for row in reader:
		rdata = row
	f.close()
	rmana = rdata[0]
	rgp = rdata[1]
	rocc = rdata[2]

	#read from form
	form = cgi.FieldStorage()
	if form.getvalue("url"):
		url = form.getvalue("url")
	if form.getvalue("inventory"):
		pinv = form.getvalue("inventory")
	valuser = pinv.split(",")
	pmana = valuser[0]
	pgp = valuser[1]

	#parse for user to print personalized form
	userurl = str(url)
	#jdjame is 1
	if "jdjame" in userurl:
		user_var = 1
	#rke is 2
	elif "rke" in userurl:
		user_var = 2
	#bcumin1 is 3
	elif "bcumin1" in userurl:
		user_var = 3
	#malsha24 is 4
	elif "malsha24" in userurl:
		user_var = 4


	#print
	print "Content-type: text/html\n\n"
	print "<html>"
	print "<head>"
	print "<title> Teleporting </title>"
	print "</head>"
	print "<body>"
	print "</br></br></br></br></br>"
	if int(rocc) == 0 and int(pmana) >= 1:
		npmana = int(pmana) - 1
		nrmana = int(rmana) + 1
		if int(npmana) == 0:
			# => room.cgi => registers pmana=0 => game over screen
			print "<object type=\"text/html\" width=\"0\" height=\"0\" data=\""+url+"/cgi-bin/success.py\" >"
			print "</object>"
			print "<h1 align=\"center\"> Out of Manna! Game Over! </h1></br></br></br>"
			print "<form name=\"gameover\" action=\"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"command\" value=\"EXIT\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\"1,"+pgp+"\" >"
			print "<input type=\"submit\" value=\"Click to Exit!\" >"
			print "</form>"
			print "</br></br></br>"
		else:
			#enter room!
			#MUST CALL success.py somehow!
			f = open('resources.csv', 'r+')
			f.seek(0)
			f.write(str(nrmana))
			f.write(',')
			f.write(rgp)
			f.write(',1')
			#f.truncate()
			f.close()
			print "<object type=\"text/html\" width=\"0\" height=\"0\" data=\""+url+"/cgi-bin/success.py\" >"
			print "</object>"
			print "<h1 align=\"center\"> Teleport Successful! </h1></br></br></br>"
			print "<form name=\"EnterRoom\" action=\"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"command\" value=\"REFRESH\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\""+str(npmana)+","+pgp+"\" >"
			print "<input type=\"submit\" value=\"Click to Enter Room!\" >"
			print "</form>"
			print "</br></br></br>"
	else:
		#room is full

		if user_var == 1:
			#print form for JDJAME
			print "<h1 align=\"center\"> Room Full! </h1></br></br></br>"
			print "<form name=\"roomfull\" action=\""+url+"/comp_206_game/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"command\" value=\"refresh\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\""+pmana+","+pgp+"\" >"
			print "<input type=\"hidden\" name=\"url\" value=\"dummyurl\" >"
			print "<input type=\"submit\" value=\"Click to Go Back!\" >"
			print "</form>"
			print "</br></br></br>"

		elif user_var == 2:
			#print form for RKE
			print "<h1 align=\"center\"> Room Full! </h1></br></br></br>"
			print "<form name=\"roomfull\" action=\""+url+"/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\""+pmana+","+pgp+"\" >"
			print "<input type=\"hidden\" name=\"cmd\" value=\"REFRESH\" >"
			print "<input type=\"submit\" value=\"Click to Go Back!\" >"
			print "</form>"
			print "</br></br></br>"

		elif user_var == 3:
			#print var for BCUMIN1
			print "<h1 align=\"center\"> Room Full! </h1></br></br></br>"
			print "<form name=\"roomfull\" action=\""+url+"/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\""+pmana+","+pgp+"\" >"
			print "<input type=\"hidden\" name=\"user_input\" value=\"REFRESH\" >"
			print "<input type=\"submit\" value=\"Click to Go Back!\" >"
			print "</form>"
			print "</br></br></br>"

		#elif user_var == 4:
			#print form for MALSHA24

		else:
			#OLD NON-specific version
			print "<h1 align=\"center\"> Room Full! </h1></br></br></br>"
			print "<form name=\"roomfull\" action=\""+url+"/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"command\" value=\"REFRESH\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\""+pmana+","+pgp+"\" >"
			print "<input type=\"submit\" value=\"Click to Go Back!\" >"
			print "</form>"
			print "</br></br></br>"

	print "</body>"
	print "</html>"

transporter()
