#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin >> input;
    string target = "SNAKE";
    int power = 0;
    int max = (int)input.size() / 5;
    // vector<vector<int>> count_pos(6);
    while (max)
    {
        int tarcnt = max;
        int k = 0;
        int cnt = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (target[k] == input[i])
            {
                cnt++;
                if (cnt == tarcnt)
                {
                    k++;
                    cnt = 0;
                }
            }
        }
        if (k == 5)
        {
            power = max;
            break;
        }
        else
        {
            max--;
        }
    }
    cout << power << endl;

    return 0;
}