#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char *string = getenv("QUERY_STRING");
	char command[12];
	int pmana=0;
  	int pgp=0;
  	int temp=0;

	sscanf(string, "command=%[^&]&inventory=%3d%*[^0123456789]%d%*[^0123456789]%3d", command, &pmana, &temp, &pgp);printf("Content-Type: text/html\n\n");
		 
		 if (strcmp(command, "PLAY") == 0){
		 	  printf("<html lang=\"en\">");
			  printf("\t<head>");
			  printf("\t\t<title>The Game</title>");
			  printf("\t</head>");
			  //solve the riddle
			  printf("\t\t<title>Solve this riddle: The more you take, the more you leave behind. What am I?</title>")
			  printf("\t\t<form name=\"textbox\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/challenge.cgi\" method=\"get\" >");
			  printf("\t\t\t<input type=\"text\" name=\"command\">");
			  printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
			  printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
			  printf("\t\t</form>");

			  printf("\t<body style=\"background-color:lightgrey\">");
			  printf("\t\t<div id=\"welcome\" style=\"background-color:white\">");
			  printf("\t\t\t<h1 align=\"center\"> Welcome to </br> the Game </h1>");
			  printf("\t\t</div>");
			  printf("\t\t<div id = \"backgroundINV\">");
			  printf("\t\t\t<center><img src=\"http://cs.mcgill.ca/~hblamp/penthouse.jpg\" width=\"1263\" height=\"400\"></center>");
			  printf("\t\t\t<div id=\"RoomPlayerInventory\" align=\"center\">");
			  printf("\t\t\t\t<p><b> &emsp; &emsp; &emsp; Room Contains:</b> &emsp; &emsp; &emsp; &emsp; &emsp;<b> Player Inventory:</b></br>");
			  printf("\t\t\t\tGold: %d &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; Gold: %d </br> Mana: %d &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; Mana: %d </p>", rgp, pgp, rmana, pmana);
			  printf("\t\t\t</div>");
			  printf("\t\t</div>");
			  printf("\t\t</br></br>");



			  if(strcmp(answer, "footsteps") == 0){ //player gets it right
			  	printf("\t\t<title>You won! We have %d mana and %d gold. You can take at most 5 units of something.</title>", pmana, pgp);
			    	
			    	//player input how many mana and gold they want
			    printf("\t\t<form name=\"textbox\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" >");
			  	printf("\t\t\t<input type=\"text\" name=\"command\">");
			  	printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
			  	printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
			  	printf("\t\t</form>");
			  	

			   }
			   else{ //player gets it wrong
			    printf("\t\t<title>The answer is wrong. You lose</title>");
			   }

			  
	
    !QUIT
	if(strcmp(command, "QUIT") == 0){ //if quit then repull page
		same thing with hidden value REFRESH and link back to hadrien's part

		//takes player back to room
		printf("Content-Type: text/html\n\n");
  		printf("<html lang=\"en\">");
  		printf("\t<head>");
  		printf("\t\t<title>Room Name</title>");
 		printf("\t</head>");

  		printf("\t<body style=\"background-color:lightgrey\">");
  		printf("\t\t<div id=\"welcome\" style=\"background-color:white\">");
  		printf("\t\t\t<h1 align=\"center\"> Welcome to </br> the Room </h1>");
  		printf("\t\t</div>");

  		printf("\t\t<div id = \"backgroundINV\">");
  		printf("\t\t\t<center><img src=\"http://cs.mcgill.ca/~hblamp/penthouse.jpg\" width=\"1263\" height=\"400\"></center>");
  		printf("\t\t\t<div id=\"RoomPlayerInventory\" align=\"center\">");
  		printf("\t\t\t\t<p><b> &emsp; &emsp; &emsp; Room Contains:</b> &emsp; &emsp; &emsp; &emsp; &emsp;<b> Player Inventory:</b></br>");
  		printf("\t\t\t\tGold: %d &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; Gold: %d </br> Mana: %d &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; Mana: %d </p>", rgp, pgp, rmana, pmana);
  		printf("\t\t\t</div>");
  		printf("\t\t</div>");
  		printf("\t\t</br></br>");

  		printf("\t\t<div id=\"Directions\">");
  		printf("\t\t\t<form name = \"North\" action =\"http://www.cs.mcgill.ca/~malsha24/cgi-bin/transporter.py\" method=\"post\" align =\"center\">");
  		printf("\t\t\t\t<input type = \"submit\" value = \"North\">");
  		printf("\t\t\t\t<input type = \"hidden\" name = \"inventory\" value =\"%d,%d\">", pmana, pgp);
  		printf("\t\t\t\t<input type = \"hidden\" name = \"url\" value = \"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\">");
  		printf("\t\t\t</form>");
  		printf("\t\t</br>");
  		printf("\t\t\t<form name = \"West\" action =\"http://www.cs.mcgill.ca/~hblamp/cgi-bin/transporter.cgi\" method=\"post\" align =\"left\">");
  		printf("\t\t\t\t<input type = \"submit\" value = \"West\">");
  		printf("\t\t\t\t<input type = \"hidden\" name = \"inventory\" value =\"%d,%d\">", pmana, pgp);
  		printf("\t\t\t\t<input type = \"hidden\" name = \"url\" value = \"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\">");
  		printf("\t\t\t</form>");
  		printf("\t\t\t<form name = \"East\" action =\"http://cgi.cs.mcgill.ca/jdjame/comp_206_game/transporter.py\" method=\"post\" align =\"right\">");
  		printf("\t\t\t\t<input type = \"submit\" value = \"East\">");
  		printf("\t\t\t\t<input type = \"hidden\" name = \"inventory\" value =\"%d,%d\">", pmana, pgp);
  		printf("\t\t\t\t<input type = \"hidden\" name = \"url\" value = \"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\">");
  		printf("\t\t\t</form>");
  		printf("\t\t</div>");

    	
	}

