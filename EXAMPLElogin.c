/* Note: this is the source file for login.cgi. It must compile to login.cgi and be placed in cgi-bin/ .
You then need to change permissions - chmod +755 login.cgi. You should also compile it on your web server. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	// Printf statements that create the formatting for the generated document
	printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
	printf("<html>\n");

	// Head
	printf( "<html>");
	printf( "<head>");

	printf( "<title>Welcome to HackBook! </title>");

	printf("<body style=\"background-color:lightgrey\">");
	printf("<div id=\"header\" style=\"background-color:white\">");
	printf("<h1 align=\"center\"  id=\"name\">HackBook</h1>");
	printf("<p align=\"center\" id=\"tagline\">The Social Network for Hackers</p>");

	printf(" </div>");

	printf("</head>");

	// Body
	printf("<body>\n");

	// Variables to hold the login information the user is going to give us
	char gLogin[50];
	char gPwd[50];

	// Out user credentials go in bufferedString, stored in the form user=blah&pwd=blahh
	char bufferedString[500];

	// Expect bufferedString in the form user=blah&pwd=blahh;
	char currentChar;

	// stdin is assumed to be the HTML input
	fgets(bufferedString, 200, stdin);
	
	/****** This next bit of code is to analyze bufferedString and extract a username and pasword *******/

	// current space in bufferedString
	int i = 0;

	// Look for the username
	while (currentChar != '='){
		currentChar = bufferedString[i];
		i++;
	}

	// Read the username
	// j helps us place it in the right place in gLogin
	int j = 0;
	while (currentChar != '&'){
		currentChar = bufferedString[i];
		if (currentChar != '&'){
			// Concat
       		gLogin[j] = currentChar;
        	gLogin[j+1] = '\0';
        	j++;
		}

		i++;

	}

	// Look for the password
	while (currentChar != '='){
		currentChar = bufferedString[i];
		i++;
	}

	// Read the password
	// j helps us place it in the right place in gLogin
	j = 0;
	while (currentChar != '\0'){
		currentChar = bufferedString[i];
		if (currentChar != '\0'){
			// Concat
       		gPwd[j] = currentChar;
        	gPwd[j+1] = '\0';
        	j++;
		}
		i++;
	}

	//printf("<p> Attempting login with credentials: %s, %s</p>", gLogin, gPwd);

	// Read from the file members.csv to check if the credentials were correct

	// Variables to hold each line
	char name[50];
	char login[50];
	char pwd[50];
	int loggedIn = 0;

	// The file
	FILE* fp = fopen("members.csv", "r");
	char buffer [500];

	// Use fgets to read line by line
	while (fgets(buffer, sizeof buffer, fp) != NULL) {

		// sscanf to parse the line and get the relevent login information
		sscanf(buffer, "%s %s %s", name, login, pwd);

		// Check if the user gave us good login info
		if ( (strcmp(gLogin, login ) == 0 ) && (strcmp(gPwd, pwd) == 0) ){
			printf("<p> Sucessful login, welcome: %s \n</p>", name);
			printf("<form name = \"test\" action = \"../cgi-bin/feedpage.py\" method=\"post\">\n"  );
			printf("<input type = \"hidden\" name=\"user\" value=\"%s\">\n", gLogin);
			printf("<input type = \"submit\" value = \"Click here to continue\">\n");
			printf("</form>");
			loggedIn = 1;
		}

	}

	fclose(fp);

	if (loggedIn == 0){
		printf("<p>Incorrect username or password!</p>");

	}
// End body of generated document
printf("</body>\n");

// End generated document
printf("</html>");
return 0;

