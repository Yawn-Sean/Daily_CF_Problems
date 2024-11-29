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

    int n, h;
    cin >> n >> h;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;

    int inf = 1e8;
    int mi1 = inf, mi2 = inf, mi3 = inf, ma1 = 0, ma2 = 0;

    for (auto &v: nums) {
        if (v <= mi1) {
            swap(mi2, mi3);
            swap(mi1, mi2);
            mi1 = v;
        }
        else if (v <= mi2) {
            swap(mi2, mi3);
            mi2 = v;
        }
        else if (v < mi3) {
            mi3 = v;
        }

        if (v >= ma1) {
            swap(ma1, ma2);
            ma1 = v;
        }
        else if (v > ma2) {
            ma2 = v;
        }
    }

    int f1 = (ma1 + ma2) - (mi1 + mi2), f2 = max(ma1 + ma2, mi1 + ma1 + h) - min(mi2 + mi3, mi1 + mi2 + h);

    if (f1 <= f2) {
        cout << f1 << '\n';
        for (int i = 0; i < n; i ++)
            cout << "1 ";
    }
    else {
        cout << f2 << '\n';
        bool flg = true;
        for (int i = 0; i < n; i ++) {
            if (flg && nums[i] == mi1) {
                flg = false;
                cout << "2 ";
            }
            else cout << "1 ";
        }
    }

    return 0;
}