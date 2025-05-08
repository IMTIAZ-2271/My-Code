#include<stdio.h>
int main(){
   int n;
   scanf("%d",&n);
   int i;
   int te=0;
   for(i=1;i<=n;i++){
    int k;
    scanf("%d",&k);
    int sum=0,rsum=0,alsum=0,ct=0,el=0;
    int j;
    for(j=1;j<=k;j++){
        int a;
        scanf(" %d",&a);
        sum+=a;
        if(j%2==1){alsum+=a;}
        else{alsum-=a;}
    }
    printf("\n");
    int t=sum;
    while(t!=0){
        rsum=rsum*10+(t%10);
        t/=10;
    }
    int f;
    for(f=2;f*f<sum;f++){
        if(sum%f==0){
            break;
        }
    }
    if(f*f>sum){
        ct+=1;
        el+=5;
    }
       if(rsum==sum){
        ct+=1;
        el+=3;
        }
            if(alsum%7==0){
              ct+=1;
              el+=4;
            }
                  if(alsum==0){
                    ct+=1;
                    el+=2;
                  }
                  
        if(ct==4){printf("Row %d: ULTRA - Energy Level %d\n",i,el);}
        else if(ct==3){printf("Row %d: HIGH - Energy Level %d\n",i,el);}
        else if(ct==2){printf("Row %d: MEDIUM - Energy Level %d\n",i,el);}
        else if(ct==1){printf("Row %d: LOW - Energy Level %d\n",i,el);}
        else{ printf("Row %d: INACTIVE - Energy Level %d\n",i,el);}
        
        te+=el; 
    }
    printf("Total Energy: %d",te);
    
return 0;
   } 





