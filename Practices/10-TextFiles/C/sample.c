#include <stdio.h>
#include <stdlib.h>

int main(){
  //Exmaple message to write
  char *str = "Your IP address is: 192.168.1.1";

  //fopen method to open a file in a specific destination
  FILE *fpread = fopen("files/text.txt", "r+w");
  FILE *fpwrite = fopen("files/output.txt","rt");


  //Verify that the file was open
  if(fpread == NULL || fpwrite == NULL){
    printf("Error Opening file\n");
    exit(1);
  }

  //Read the file's content
  int ch;
  do{
    ch = fgetc(fpread);
    putchar(ch);
  }while(ch != EOF);
  printf("\n");

  //Write to file
  fputs(str,fpwrite);

  //Read new file
  char newline[100];
  while(fgets(newline, 100, fpwrite) != NULL)
    puts(newline);
  printf("\n");

  //Close the file
  fclose(fpread);
  fclose(fpwrite);

  return 0;
}
