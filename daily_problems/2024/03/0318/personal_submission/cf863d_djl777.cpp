#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 201000, M = 110;
int n, q, m, a[N], b[M];
array<int, 3> qe[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
        cin >> qe[i][0] >> qe[i][1] >> qe[i][2];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = q; i >= 1; i--)
    {
        int t = qe[i][0], l = qe[i][1], r = qe[i][2];
        if (t == 2)
        {
            for (int j = 1; j <= m; j++)
                if (l <= b[j] && b[j] <= r)
                    b[j] = l + r - b[j];
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (l < b[j] && b[j] <= r)
                    b[j]--;
                else if (l == b[j])
                    b[j] = r;
            }
        }
    }

    for (int i = 1; i <= m; i++)
        cout << a[b[i]] << " ";
    cout << "\n";
    return 0;
}