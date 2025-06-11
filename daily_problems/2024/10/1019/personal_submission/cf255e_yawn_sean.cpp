#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M = 1e6;
    vector<int> sg(M, 0);

    int l = 0, r = 0;
    map<int, int> cnt;

    for (int i = 1; i < M; i ++) {
        while (l * l * l * l < i) {
            cnt[sg[l]] --;
            l ++;
        }
        while (r * r <= i && r < i) {
            cnt[sg[r]] ++;
            r ++;
        }
        while (cnt[sg[i]]) sg[i] ++;
    }

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    sort(nums.begin(), nums.end());

    int res = 0;
    cnt.clear();
    l = 0, r = 0;

    for (auto &v: nums) {
        while (1ll * l * l * l * l < v) {
            cnt[sg[l]] --;
            l ++;
        }
        while (1ll * r * r <= v && r < v) {
            cnt[sg[r]] ++;
            r ++;
        }
        int x = 0;
        while (cnt[x]) x ++;
        res ^= x;
    }

    cout << (res ? "Furlo" : "Rublo");

    return 0;
}