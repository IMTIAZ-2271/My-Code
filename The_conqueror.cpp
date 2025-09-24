#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    double radius;
    double population;
} country;
bool cmp(country a, country b)
{
    if (a.radius != b.radius)
        return a.radius < b.radius;
    return a.population > b.population;
}
int main()
{
    double N, K, M;
    cin >> N >> K >> M;
    vector<country> countries(N);
    for (double i = 0.0; i < N; i++)
    {
        double x, y;
        cin >> x >> y >> countries[i].population;
        countries[i].radius = sqrt(pow(x, 2) + pow(y, 2));
    }
    double r = 0.0;
    sort(countries.begin(), countries.end(), cmp);

    double total_population = K;
    for (double i = 0.0; i < N; i++)
    {
        r = countries[i].radius;
        total_population += countries[i].population;
        if (total_population >= M)
        {
            break;
        }
    }
    if (total_population < M)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << fixed << setprecision(4) << r << endl;

    return 0;

}