#!/usr/bin/python

import sys
import cgi
import csv
import math
import urllib2
import ctypes

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

	#print
	print "Content-type: text/html\n\n"
	print "<html>"
	print "<head>"
	print "<title> Teleporting </title>"
	print "</head>"
	print "<body>"
	#print "</br><p>rmana= ", rmana, " pmana= ", pmana, "</p></br>"
	#print "</br><p>pinv= ", pinv, "</p></br>"

	print "</br></br></br></br></br>"
	if int(rocc) == 0 and int(pmana) >= 1:
		npmana = int(pmana) - 1
		nrmana = int(rmana) + 1
		#print "</br>rmana= ", rmana, " pmana= ", pmana, "</br>"
		#print "</br> url=\"",url,"cgi\" </br>"
		#print "</br> yourl=\""+url+"cgi\" </br>"
		#print "</br>yoovalue=\"",npmana,",",pgp,"\" </br>"
		#print "</br>yoovalue=\"",nrmana,",",rgp,"\" </br>"
		#print "</br>value=\""+npmana+","+pgp+"\" </br>"
		if int(npmana) == 0:
			# => room.cgi => registers pmana=0 => game over screen
			print "<h1 align=\"center\"> Out of Manna! Game Over! </h1></br></br></br>"
			print "<form name=\"gameover\" action=\"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"command\" value=\"EXIT\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\"1,"+pgp+"\" >"
			print "<input type=\"submit\" value=\"Click to Exit!\" >"
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
			print "<h1 align=\"center\"> Teleport Successful! </h1></br></br></br>"
			print "<form name=\"EnterRoom\" action=\"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
			print "<input type=\"hidden\" name=\"command\" value=\"REFRESH\" >"
			print "<input type=\"hidden\" name=\"inventory\" value=\""+str(npmana)+","+pgp+"\" >"
			print "<input type=\"submit\" value=\"Click to Enter Room!\" >"
			print "</br></br></br>"
	else:
		print "<h1 align=\"center\"> Room Full! </h1></br></br></br>"
		print "<form name=\"roomfull\" action=\""+url+"/cgi-bin/room.cgi\" method=\"get\" align=\"center\" >"
		print "<input type=\"hidden\" name=\"command\" value=\"REFRESH\" >"
		print "<input type=\"hidden\" name=\"inventory\" value=\""+pmana+","+pgp+"\" >"
		print "<input type=\"submit\" value=\"Click to Go Back!\" >"
		print "</br></br></br>"
	print "</br></br></br></br></br></br></br><p>rmana= ", rmana, " rgp= ", rgp, " rocc= ", rocc, "</br> url= ", url, " pmana= ", pmana, " pgp", pgp, "</p>"
	print "</body>"
	print "</html>"

transporter()
