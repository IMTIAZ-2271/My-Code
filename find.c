#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
   if(argc != 2){
    return 1;
   }
   FILE* fp=fopen(argv[1],"r+");
   if(!fp){
    return 2;
   }
   int sum = 0;
   int t;
   while(fscanf(fp,"%d",&t)==1){
    if(t%2 == 1){
        sum += t;
    }
   }
   printf("%d\n",sum);
return 0;
}