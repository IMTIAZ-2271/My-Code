#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
     map<int, int> groups;
     for(int x:deck){
        groups[x]++;
     }

      map<int,int>::iterator it = groups.begin();
     int g = it->second;
     while(it!=groups.end()){
        g = __gcd(g,it->second);
        it++;
     }

     return g >= 2;

    }
};