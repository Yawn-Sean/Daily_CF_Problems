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

    vector<int> s1(8), s2(8);
    for (auto &v: s1) cin >> v;
    for (auto &v: s2) cin >> v;

    function<bool(vector<int>, vector<int>)> is_in = [&] (vector<int> square1, vector<int> square2) -> bool {
        int xl = 100, xr = -100, yl = 100, yr = -100;
        for (int i = 0; i < 8; i ++) {
            if (i & 1) yl = min(yl, square2[i]), yr = max(yr, square2[i]);
            else xl = min(xl, square2[i]), xr = max(xr, square2[i]);
        }
        for (int i = 0; i < 8; i += 2)
            if (square1[i] >= xl && square1[i] <= xr && square1[i+1] >= yl && square1[i+1] <= yr)
                return true;
        return square1[0] + square1[4] >= xl * 2 && square1[0] + square1[4] <= xr * 2 && square1[1] + square1[5] >= yl * 2 && square1[1] + square1[5] <= yr * 2;
    };

    if (is_in(s2, s1)) cout << "YES";
    else {
        for (int i = 0; i < 8; i += 2) {
            s1[i] += s1[i+1];
            s1[i+1] = s1[i] - s1[i+1] * 2;
            s2[i] += s2[i+1];
            s2[i+1] = s2[i] - s2[i+1] * 2;
        }
        cout << (is_in(s1, s2) ? "YES" : "NO");
    }

    return 0;
}