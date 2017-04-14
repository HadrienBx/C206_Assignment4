#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

	//create vars
	char *string = getenv("QUERY_STRING");
	char command[12];
	int pmana=0;
	int pgp=0;
	int temp=0;
	int rmana=0;
	int rgp=0;
	int rocc=0;
	int dropgp=0;
	int pickgp=0;
	int pickmana=0;
	int picksuccess=0;


	//query to vars
	sscanf(string, "command=%[^&]&inventory=%3d%*[^0123456789]%d%*[^0123456789]%3d", command, &pmana, &temp, &pgp);

	//
	if(strstr(command, "PICK") != NULL){
		sscanf(command, "%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d", &pickmana, &temp, &pickgp);
		FILE *resources = fopen("resources.csv", "r+");
	  	fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
	  	fclose(resources);
		if( pickmana <= rmana && pickgp <= rgp && pickmana + pickgp <= 5){
			picksuccess=1;  //enough resources
		}else{
			picksuccess=2;	//not enough resources
		}
		if(picksuccess == 1){
			pgp += pickgp;
			pmana += pickmana;
			rgp -= pickgp;
			rmana -= pickmana;
			FILE *resources = fopen("resources.csv", "r+");
		  	fprintf(resources, "%d,%d,%d", rmana, rgp, rocc);
		  	fclose(resources);
		}
	}

	//print html
  	printf("Content-Type: text/html\n\n");
  	printf("<html lang=\"en\">");
  	printf("\t<head>");
  	printf("\t\t<title>The Game</title>");
  	printf("\t</head>");

  	printf("\t<body style=\"background-color:lightgrey\">");
  	printf("\t\t<div id=\"welcome\" style=\"background-color:white\">");
	if(strcmp(command, "PLAY") == 0){
  		printf("\t\t\t<h1 align=\"center\"> Solve this riddle! </h1>");
	}else if(strstr(command, "foot") != NULL && strstr(command, "step") != NULL ){
  		printf("\t\t\t<h1 align=\"center\"> You won! </h1>");
	}else if(strcmp(command, "QUIT") == 0){
  		printf("\t\t\t<h1 align=\"center\"> Goodbye! </h1>");
	}else if(picksuccess == 1){
		printf("\t\t\t<h1 align=\"center\"> Enjoy your reward! </h1>");
	}else if(picksuccess == 2){
		printf("\t\t\t<h1 align=\"center\"> Not enough resources! </h1>");
	}else{
		printf("\t\t\t<h1 align=\"center\"> Wrong Answer or Invalid Command! </h1>");
	}
  	printf("\t\t</div>");

  	printf("\t\t<div id = \"backgroundINV\">");
  	printf("\t\t\t<center><img src=\"http://cs.mcgill.ca/~hblamp/penthouse.jpg\" width=\"1263\" height=\"400\"></center>");
	printf("\t\t</div>");


	if(strcmp(command, "PLAY") == 0 || (picksuccess == 0 && (strstr(command, "foot") == NULL || strstr(command, "step") == NULL) && strcmp(command, "QUIT") != 0)){
		printf("\t\t<div id=\"Riddle\" align=\"center\">");
		printf("\t\t\t<p><b>The more you take, the more you leave behind. What am I?</b></br></p>");
		printf("\t\t\t<p><b>Hint: Having trouble? Take a walk. Answer in lowercase please! </b></br>");
		printf("\t\t</div>");
  	}else if(strstr(command, "foot") != NULL && strstr(command, "step") != NULL){
		FILE *resources = fopen("resources.csv", "r+");
	  	fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
	  	fclose(resources);
		printf("\t\t<div id=\"Correct\" align=\"center\">");
		printf("\t\t\t<p><b>You got the correct answer!</b></br></p>");
		printf("\t\t\t<p><b>We have %d mana and %d gold.</b></br>", rmana, rgp);
		printf("\t\t\t<p><b>You can take up to 5 units, for example, 3 mana and 2 gold.</b></br>");
		printf("\t\t\t<p><b>Please type your choice in the exact format:\"PICKUP mana,gold\".</b></br>");
		printf("\t\t</div>");
	}else if(picksuccess == 2){
		printf("\t\t<div id=\"pickup unsuccessful\" align=\"center\">");
		printf("\t\t\t<p><b>Invalid pick up request!</b></br></p>");
		printf("\t\t\t<p><b>Please re-type your choice in the exact format:\"PICKUP mana,gold\".</b></br>");
		printf("\t\t</div>");
	}else if(picksuccess == 1){
		printf("\t\t<div id=\"pickup successful\" align=\"center\">");
		printf("\t\t\t<p><b>Transfer successful!</b></br></p>");
		printf("\t\t\t<p><b>Your mana is %d and your gold is %d.</b></br>", pmana, pgp);
		printf("\t\t</div>");
	}else{
		printf("\t\t</br>");
		printf("\t\t</br>");
	}



	if(strcmp(command, "QUIT") != 0 && picksuccess != 1){
    		printf("\t\t<div>");
    		printf("\t\t<form name=\"textbox\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/challenge.cgi\" method=\"get\" align =\"center\" >");
    		printf("\t\t\t<input type=\"text\" name=\"command\">");
    		printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
    		printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
  	}else{		//comand is QUIT or game is over
    		printf("\t\t<form name=\"playgame\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" align =\"center\" >");
    		printf("\t\t\t<input type=\"hidden\" name=\"command\" value=\"REFRESH\">");
    		printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
    		printf("\t\t\t<input type=\"submit\" value=\"Click to go back to room!\">");
  	}

  	printf("\t\t</form>");
  	printf("\t\t</div>");
  	printf("\t\t</br>");
  	printf("\t</body>");
  	printf("</html>");
  	return 1;
}
