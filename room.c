#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//if(strcmp(command, "DROP") == 0){
//if (strstr(command, "DROP+") != NULL){

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


  //query to vars
  sscanf(string, "command=%[^&]&inventory=%3d%*[^0123456789]%d%*[^0123456789]%3d", command, &pmana, &temp, &pgp);

  //if DROP command
  if(strstr(command, "DROP+") != NULL){
    sscanf(command, "%*[^0123456789]%3d", &dropgp);
    if((pmana > 0) && (pgp >= dropgp)){
      FILE *resources = fopen("resources.csv", "r+");
      fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
      rgp += dropgp;
      pgp -= dropgp;
      pmana += dropgp/2;
      rewind(resources);
      fprintf(resources, "%d,%d,%d", rmana, rgp, rocc);
      fclose(resources);
      return 0;
    }
  }

  //if EXIT command
  if(strcmp(command, "EXIT") == 0){
    FILE *resources = fopen("resources.csv", "r+");
    fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
    rgp += pgp;
    rmana += pmana;
    rewind(resources);
    fprintf(resources, "%d,%d,0", rmana, rgp);
    fclose(resources);
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("\t<head>");
    printf("\t\t<title>Goodbye!</title>");
    printf("\t</head>");
    printf("\t<body>");
    printf("\t\t<img src=\"https://i.ytimg.com/vi/vJaAy3jmEx8/maxresdefault.jpg\" align=\"top\" width=\"1263\" height=\"800\" />");
    printf("\t</body>");
    printf("</html>");
  }



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
  printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
  printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
  if(strcmp(command, "REFRESH") != 0){
  printf("\t\t\t</br><b>You did not enter a valid command!</b>");
  }
  printf("\t\t</form>");
  printf("\t\t<p>%s.</p>",command);
  printf("\t\t<p>%d</p>",pmana);
  printf("\t\t<p>%d</p>",pgp);
  printf("\t\t<p>%d</p>",dropgp);
  printf("\t\t<p>%d</p>",rmana);
  printf("\t\t<p>%d</p>",rgp);
  printf("\t\t<p>%d</p>",rocc);
  printf("\t</body>");
  printf("</html>");
  return 1;
}
