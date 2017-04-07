#include <stdlib.h>
#include <stdio.h>

int main(void){

  char *string = getenv("QUERY_STRING");
  char command[12];
  int mana;
  int gp;
  int temp;

  sscanf(string, "command=%[^&]&inventory=%3d%*[^0123456789]%d%*[^0123456789]%3d", command, &mana, &temp, &gp);




  //print html
  printf("Content-Type: text/html\n\n");
  printf("<html>");
  printf("\t<head>");
  printf("\t\t<title>Room Name</title>");
  printf("\t</head>");
  printf("\t<body>");
  printf("\t\t<img src=\"penthouse.jpg\" align=\"top\" width=\"1263\" height=\"500\" />");
  printf("\t\t<form name=\"textbox\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" >");
  printf("\t\t\t<input type=\"text\" name=\"command\">");
  printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gp);
  printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
  printf("\t\t</form>");
  printf("\t\t<p>%s</p>",command);
  printf("\t\t<p>%d</p>",mana);
  printf("\t\t<p>%d</p>",gp);
  printf("\t</body>");
  printf("</html>");

  return 1;
}
