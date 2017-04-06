#include <stdlib.h>
#include <stdio.h>

int main(void){

  char *string = getenv("QUERY_STRING");
  int cmd;
  int inv;

  sscanf(string, "cmd=%d&inv=%d", &cmd, &inv);




  //print html
  printf("Content-Type: text/html\n\n");
  printf("<html>");
  printf("\t<head>");
  printf("\t\t<title>Room Name</title>");
  printf("\t</head>");
  printf("\t<body>");
  printf("\t\t<img src=\"penthouse.jpg\" align=\"top\" width=\"1263\" height=\"500\" />");
  printf("\t\t<form name=\"textbox\" action=\"www.cs.mcgill.ca/~hblamp/cgi-bin/a.cgi\" method=\"get\" >");
  printf("\t\t\t<input type=\"text\" name=\"cmd\">");
  printf("\t\t\t<input type=\"hidden\" name=\"inv\" val=\"6\">");
  printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
  printf("\t\t</form>");
  printf("\t\t<p>%d,%d</p>",cmd,inv);
  printf("\t</body>");
  printf("</html>");

  return 1;
}
