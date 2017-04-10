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

  //room resource to vars
  FILE *resources = fopen("resources.csv", "r+");
  fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
  fclose(resources);

  //if win pgp=100
  if(pgp >= 100){
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("\t<head>");
    printf("\t\t<title>Goodbye!</title>");
    printf("\t</head>");
    printf("\t<body>");
    printf("\t\t<img src=\"https://i.ytimg.com/vi/vJaAy3jmEx8/maxresdefault.jpg\" align=\"top\" width=\"1263\" height=\"800\" />");
    printf("\t</body>");
    printf("</html>");
    return 1;

  }

  //if EXIT command OR mana = 0
  if(strcmp(command, "EXIT") == 0 || pmana <= 0){
    if(strcmp(command, "EXIT") == 0){
      FILE *resources = fopen("resources.csv", "r+");
      //fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
      rgp += pgp;
      rmana += pmana;
      //rewind(resources);
      fprintf(resources, "%d,%d,0", rmana, rgp);
      fclose(resources);
    }
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("\t<head>");
    printf("\t\t<title>Goodbye!</title>");
    printf("\t</head>");
    printf("\t<body>");
    printf("\t\t<img src=\"https://i.ytimg.com/vi/vJaAy3jmEx8/maxresdefault.jpg\" align=\"top\" width=\"1263\" height=\"800\" />");
    printf("\t</body>");
    printf("</html>");
    return 1;
  }

  //if DROP command
  if(strstr(command, "DROP+") != NULL){
    sscanf(command, "%*[^0123456789]%3d", &dropgp);
    if((pmana > 0) && (pgp >= dropgp)){
      FILE *resources = fopen("resources.csv", "r+");
      //fscanf(resources, "%3d%*[^0123456789]%3d%*[^0123456789]%d", &rmana, &rgp, &rocc);
      rgp += dropgp;
      pgp -= dropgp;
      pmana += dropgp/2;
      //rewind(resources);
      fprintf(resources, "%d,%d,%d", rmana, rgp, rocc);
      fclose(resources);
    }
  }


  //print html
  printf("Content-Type: text/html\n\n");
  printf("<html lang=\"en\">");
  printf("\t<head>");
  printf("\t\t<title>The Name</title>");
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


  if(strcmp(command, "PLAY") != 0){
    printf("\t\t<div>");
    printf("\t\t<form name=\"textbox\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\" method=\"get\" align =\"center\" >");
    printf("\t\t\t<input type=\"text\" name=\"command\">");
    printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
    printf("\t\t\t<input type=\"submit\" value=\"Submit\">");
  }else{
    printf("\t\t<form name=\"playgame\" action=\"https://www.cs.mcgill.ca/~hblamp/cgi-bin/challen.cgi\" method=\"get\" align =\"center\" >");
    printf("\t\t\t<input type=\"hidden\" name=\"command\" value=\"PLAY\">");
    printf("\t\t\t<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pmana, pgp);
    printf("\t\t\t<input type=\"submit\" value=\"Click To Play!\">");
  }
  //if invalid command
  if(strcmp(command, "REFRESH") != 0 && strcmp(command, "EXIT") != 0 && strcmp(command, "PLAY") != 0 && strcmp(command, "QUIT") != 0 && strstr(command, "DROP+") == NULL){
  printf("\t\t\t</br><b>You did not enter a valid command!</b>");
  }
  printf("\t\t</form>");
  printf("\t\t</div>");
  printf("\t\t</br>");

  printf("\t\t<div id=\"Directions\">");
  printf("\t\t\t<form name = \"South\" action =\"http://www.cs.mcgill.ca/~naharo/cgi-bin/transporter.py\" method=\"post\" align =\"center\">");
  printf("\t\t\t\t<input type = \"hidden\" name = \"inv\" value =\"%d,%d\">", pmana, pgp);
  printf("\t\t\t\t<input type = \"hidden\" name = \"url\" value = \"http://www.cs.mcgill.ca/~hblamp/cgi-bin/room.cgi\">");
  printf("\t\t\t\t<input type = \"submit\" value = \"South\">");
  printf("\t\t\t</form>");
  printf("\t\t</div>");
  printf("\t\t</br>");


  printf("\t\t<p>%s. pmana,pgp=%d,%d rmana,rgp,rocc=%d,%d,%d</p>",command, pmana, pgp, rmana, rgp, rocc);
  printf("\t</body>");
  printf("</html>");
  return 1;
}
