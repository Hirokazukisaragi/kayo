#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 256
int main(int argc,char *argv[]){
  int filenum = argc;
  FILE *rfp,*wfp;
  int i = 1;
  char buf[MAX_BUF];
  char delim[1];
  delim[0] = 0xCC;
  char outputname[] = "compressed.ball";
  wfp = fopen(outputname,"w+");
  while(i < filenum){
    rfp = fopen(argv[i],"r");
    while(!feof(rfp)){
      fread(buf,1,sizeof(char),rfp);
      fwrite(buf,1,sizeof(char),wfp);
    }
    fwrite(delim,1,sizeof(char),wfp);
    fclose(rfp);
    i++;
  }
  fclose(wfp);
  return 0;
}
