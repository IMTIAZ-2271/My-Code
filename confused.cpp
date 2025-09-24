#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> dayP(n),dayT;
    for (auto &x : dayP)
        cin >> x.first >> x.second;
    dayT = dayP;
   
      
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (dayP[i].first * dayP[j].second > dayP[j].first * dayP[i].second)
                {
                    swap(dayP[i],dayP[j]);
                    
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dayP[i]==dayT[j])
                {
                    cout<<j+1<<" ";
                }
                
            }
            
        }
        
   

    return 0;
}