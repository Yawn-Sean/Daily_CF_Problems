#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, b;
    cin >> n >> b;

    queue<long long> q;
    
    while (n --) {
        long long t, d;
        cin >> t >> d;
        while (!q.empty() && q.front() <= t)
            q.pop();
        if (q.size() > b) cout << -1 << ' ';
        else {
            if (!q.empty()) t = q.back();
            cout << t + d << ' ';
            q.push(t + d);
        }
    }

    return 0;
}