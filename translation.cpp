#include<iostream>
#include<string>
using namespace std;
int main(){
   string s,t;
   getline(cin,s);
   getline(cin,t);
   string r_t(t.length(), ' ');
   for(int i=0;i<(t.length());i++){
      r_t[i]=t[t.length()-i-1];
   }
   if(s==r_t){
    cout<<"YES";
   }
   else{
    cout<<"NO";
   }
   return 0;
}