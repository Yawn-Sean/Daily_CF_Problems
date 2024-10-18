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

    int n, q;
    cin >> n >> q;

    int even_move = 0, odd_move = 0, swap = 0;

    auto add = [&] (int &x, int y) {
        x += y;
        if (x >= n) x -= n;
        if (x < 0) x += n;
    };

    while (q --) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            add(odd_move, x);
            add(even_move, x);
            swap ^= x & 1;
        }
        else {
            if (swap) {
                add(even_move, 1);
                add(odd_move, -1);
            }
            else {
                add(even_move, -1);
                add(odd_move, 1);
            }
            swap ^= 1;
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i ++) {
        if (i & 1)
            ans[(i + even_move) % n] = i + 1;
        else
            ans[(i + odd_move) % n] = i + 1;
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}