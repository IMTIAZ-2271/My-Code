#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        map<long long, long long> gcdfreq;
        for (int i = 0; i < nums.size(); ++i)
        {
            long long g = __gcd(nums[i], k);
            gcdfreq[g]++;
        }
        vector<long long> GCDs;
        for (auto it : gcdfreq)
        {
            GCDs.push_back(it.first);
        }
        long long ans = 0;
        for (int i = 0; i < GCDs.size(); i++)
        {
            for (int j = i; j < GCDs.size(); j++)
            {
                if (GCDs[i] * GCDs[j] % k == 0)
                {
                    if (GCDs[i] == GCDs[j])
                    {
                        long long temp = gcdfreq[GCDs[i]];
                        ans += (temp * (temp - 1)) / 2;
                    }
                    else
                    {
                        long long g1 = gcdfreq[GCDs[i]];
                        long long g2 = gcdfreq[GCDs[j]];
                        ans += g1 * g2;
                    }
                }
            }
        }
        return ans;
    }
};