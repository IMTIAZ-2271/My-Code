#include <iostream>
#include<string>
using namespace std;
 
int main() {
  int n,k=0;
  cin>>n;
  char s[n];
  cin.ignore();
  cin>>s;
  for(int i=0;i<n;i++){
    if(s[i] =='A'){
       k++;
    }
  }
  if(k == (n - k)){
    cout<<"Friendship";
  }
  else if(k>(n-k)){
    cout<<"Anton";
  }
  else{
    cout<<"Danik";
  }

return 0;
}