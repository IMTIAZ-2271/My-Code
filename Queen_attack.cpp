#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> board(11, vector<int>(11));

bool queen_is_not_attacking(int row, int column)
{
    int queen_count_in_range = 0;
    for (int i = 1; i <= n; i++)
    {
        queen_count_in_range += board[row][i];
    }
    if (queen_count_in_range > 1)
    {
        return false;
    }
    queen_count_in_range = 0;
    for (int i = 1; i <= n; i++)
    {
        queen_count_in_range += board[i][column];
    }
    if (queen_count_in_range > 1)
    {
        return false;
    }
    queen_count_in_range = 0;

    vector<int> dx = {1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int current_x = row, current_y = column;
        while (current_x <= n && current_y <= n && current_x >= 1 && current_y >= 1)
        {
            if (board[current_x][current_y] == 1)
            {
                queen_count_in_range++;
            }
            current_x += dx[i];
            current_y += dy[i];
        }
        if (queen_count_in_range > 1)
        {
            return false;
        }
        queen_count_in_range = 0;
    }
    return true;
}

bool queen_attack(int row)
{
    if (row > n)
        return true;

    bool ans = false;
    int queen_count = 0;
    int column = 0;
    for (int i = 1; i <= n; i++)
    {
        queen_count += board[row][i];
        if (board[row][i] == 1)
        {
            column = i;
        }
    }
    if (queen_count > 1)
    {
        return false;
    }
    else if (queen_count == 1)
    {
        if (board[row][column] == 1 && queen_is_not_attacking(row, column))
        {
            return queen_attack(row + 1);
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            board[row][i] = 1;
            if (queen_is_not_attacking(row, i))
            {
                ans |= queen_attack(row + 1);
            }
            board[row][i] = 0;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (queen_attack(1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}