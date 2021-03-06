#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long n, q, t, k;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    cin >> n >> q;
    vector<vector<long>> jumps(n + 2, vector<long>(35));
    for (int i = 2; i <= n; i++)
        cin >> jumps[i][0];

    jumps[1][0] = -1;

    for (int i = 1; i <= 29; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long curr = j;
            auto first = jumps[j][i - 1];
            if (first > 0)
                jumps[j][i] = jumps[first][i - 1];
            else
                jumps[j][i] = -1;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> n >> k;
        long j = 0;
        double tgt = log2(k);
        while (tgt >= j)
        {
            if ((k >> j & 1) > 0)
                n = jumps[n][j];
            if (n == -1)
                break;
            j += 1;
        }
        cout << n << '\n';
    }
}
