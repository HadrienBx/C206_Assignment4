#!/usr/bin/env python
import math
import cgi
import csv
import urllib2
import ctypes

def transporter (player_inventory, url):
	
	# get and reads csv, check if the number on index 2 is 0 or 1
	f = open("resources.csv","r")
	csv_f = csv.reader(f) 
	form = cgi.FieldStorage()
	url = form.getvalue('url')
	user_inventory = form.getvalue('inventory')
	value = user_inventory.split(",")
	manna = value[0]
	gold = value[1]
	for line in csv_f:
		room_status = line[2]

		# if room is occupied
		if (room_status == 1):
			print "Content-type: text/html\r\n"
 			print "<html>"
 			print '<body align = "center">'
			print '<p> The room you tried to enter is occupied!</br>'
 			print "Manna is %s </br>" %(manna)
			
			#TODO jesus christ i hope this works
 			print '<form name = "return" action = "' + url +'"' + ' method ="post">'
			print '<input type = "hidden" name = "inventory" value ="' + manna + ',' + gold + '"
			print '<input type ="submit" value = "return">
			print '</form>'
			print "</p>
 			print "</body>"
 			print "</html>" 

			# if number is 1, calls the url and goes back to prev room
			# response = urllib2.urlopen(url)
			# html = response.read() 

			# change occupancy field by changing csv field to 0
			
			# fo = open ('resources.csv', 'w+')

		elif (room_status == 0): #room is available
			 
			 print "Content-Type: text/html\n\n";
			 print "<html>";
			 print "\t<head>";
			 print "\t\t<title>Room Name</title>";
			 print "\t</head>";
			 print "\t<body>";
			 print "\t\t<img src=\"penthouse.jpg\" align=\"top\" width=\"1263\" height=\"500\" />";
			 print "\t\t<form name=\"textbox\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" >");
			 print "\t\t\t<input type=\"text\" name=\"command\">";
			 print "\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp;
			 print "\t\t\t<input type=\"submit\" value=\"Submit\">";
			 
			 print "\t\t</form>";
			 print "\t\t<p>%s.</p>",command
			 print "\t\t<p>%d</p>",pmana
			 print "\t\t<p>%d</p>",pgp
			 print "\t\t<p>%d</p>",dropgp
			 print "\t\t<p>%d</p>",rmana
			 print "\t\t<p>%d</p>",rgp
			 print "\t\t<p>%d</p>",rocc
			 print "\t</body>"
			 print "</html>"

			# changing their occupancy field in their resources.csv


			f2 = open(their resources.cv url)
			csv_f2 = csv.reader(csv_f2)
			fileout = open ('resources.csv', 'w+')
			for line in f:
				values = line.split(',')
				token[2] = '"0"'
				fo.write(','.join(token))
			f.close()
			fo.close()

		

	f.close()
	fo.close()
