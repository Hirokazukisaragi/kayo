#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
  FILE *rfp;
  FILE *wfp;
  int buf;
  char fname[1024] = "out";
  int i = 0;
  char name[128];
  char bflag = 0;
  int nf = 0;
  rfp = fopen("compressed.ball","r");
  while(1){
    strcpy(fname,"out");
    sprintf(name,"%d",i);
    strcat(fname,name);
    wfp = fopen(fname,"w+");
    while(1){
      buf = fgetc(rfp);
      if(feof(rfp)){
	bflag++;
	break;
      }
      if(buf == 0xCC){
	nf++;
	break;
      }
      fputc(buf,wfp);
    }
    if(nf){
      nf=0;
      i+=1;
      fclose(wfp);
      continue;
    }
    if(bflag){
      fclose(wfp);
      break;
    }
    i+=1;
  }
  fclose(rfp);
  return 0;
}
