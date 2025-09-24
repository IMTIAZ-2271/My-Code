#include <bits/stdc++.h>
using namespace std;




int main()
{
    int n;
    cin >> n;
    vector<pair<long long int, int>> days;
    vector<pair<long long int, int>> priority;
    for (int i = 0; i < n; i++)
    {
        long long int x, y;
        cin >> x >> y;
        days.push_back({x, i + 1});
        priority.push_back({y, i + 1});
    }
    sort(days.begin(), days.end());
    sort(priority.begin(), priority.end(), [](const pair<long long int, int> &a, const pair<long long int, int> &b)
         { return a.first > b.first; });

    auto it1 = days.begin();
    auto it2 = priority.begin();

    vector<pair<int, int>> diff_vec;

    int k=1;
    unordered_map<int,int>mp;

    while (it1 != days.end())
    {
        int difference = abs(it1->second - it2->second);
        diff_vec.push_back({difference, it2->second});

        ++it1;
        ++it2;
    }
    sort(diff_vec.begin() , diff_vec.end());

    for (auto &it : diff_vec)
    {
        cout <<it.first<<" "<< it.second << endl;
    }
    return 0;
}