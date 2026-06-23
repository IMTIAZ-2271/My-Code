#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 1000009;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> points;
    for (int i = 0; i < 8; ++i)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.first  == b.first){
            return a.second < b.second;
        }
        return a.first < b.first; });
    for (int i = 0; i < 3; i++)
    {
        if (points[i].first != points[0].first || (i > 0 && points[i].second <= points[i - 1].second))
        {
            cout << "ugly" << endl;
            return 0;
        }
    }
    if (!(points[3].first != points[2].first && points[3].second != points[1].second &&
          points[4].first != points[2].first && points[4].second != points[1].second &&
          points[3].first == points[4].first && points[3].second < points[4].second))
    {
        cout << "ugly" << endl;
        return 0;
    }
    for (int i = 5; i < 8; i++)
    {
        if (points[i].first == points[0].first ||
            points[i].first == points[3].first ||
            (i > 5 && points[i].second <= points[i - 1].second) ||
            points[i].second != points[i - 5].second)
        {
            cout << "ugly" << endl;
            return 0;
        }
    }
    cout << "respectable" << endl;

    return 0;
}