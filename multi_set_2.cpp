#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int, greater<int>> all_query_ans;
    all_query_ans.insert(1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            int t = *all_query_ans.begin();
            all_query_ans.insert(t * x);
        }
        else
        {
            int t = *all_query_ans.rbegin();
            all_query_ans.insert(t * x);
        }
    }
    int sum = 0;
    for (int p : all_query_ans)
    {
        sum += p;
    }

    cout << sum << endl;
    return 0;
}
