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

    vector<int> ar = {0};
    for (int i = 0; i < 5; i ++)
        for (int j = (1 << i) - 1; j >= 0; j --)
            ar.emplace_back(ar[j] | (1 << 2 * i));
    
    vector<pair<int, int>> pos(1024);
    for (int i = 0; i < 32; i ++)
        for (int j = 0; j < 32; j ++)
            pos[ar[i] ^ (ar[j] * 2)] = {i + 1, j + 1};
    
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - 1; j ++)
            cout << (ar[j] ^ ar[j+1]) * 2 << ' ';
        cout << '\n';
        }
    
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n; j ++)
            cout << (ar[i] ^ ar[i+1]) << ' ';
        cout << '\n';
        }
    
    cout.flush();

    int msk = 0;
    while (q --) {
        int v;
        cin >> v;
        msk ^= v;
        cout << pos[msk].first << ' ' << pos[msk].second << '\n';
        cout.flush();
    }

    return 0;
}