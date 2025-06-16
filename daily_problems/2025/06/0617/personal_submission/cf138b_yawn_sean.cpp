#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<int> cnt1(10, 0);
    for (auto &c: s) cnt1[c - '0'] ++;
    vector<int> cnt2 = cnt1;

    int val = min(cnt1[0], cnt2[0]), chosen = -1;

    for (int i = 1; i < 10; i ++) {
        if (cnt1[i] && cnt2[10 - i]) {
            cnt1[i] --, cnt2[10 - i] --;

            int cur = 1;
            for (int x = 0; x < 10; x ++)
                cur += min(cnt1[x], cnt2[9 - x]);
            cur += min(cnt1[0] - min(cnt1[0], cnt2[9]), cnt2[0] - min(cnt2[0], cnt1[9]));
            if (cur > val) val = cur, chosen = i;

            cnt1[i] ++, cnt2[10 - i] ++;
        }
    }

    vector<int> v1, v2;
    if (chosen != -1) {
        cnt1[chosen] --, cnt2[10 - chosen] --;
        v1.emplace_back(chosen), v2.emplace_back(10 - chosen);

        for (int i = 0; i < 10; i ++) {
            while (cnt1[i] && cnt2[9 - i]) {
                v1.emplace_back(i);
                v2.emplace_back(9 - i);
                cnt1[i] --, cnt2[9 - i] --;
            }
        }

        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
    }

    int c0 = min(cnt1[0], cnt2[0]);
    cnt1[0] -= c0, cnt2[0] -= c0;

    for (int i = 0; i < 10; i ++)
        while (cnt1[i]) cout << i, cnt1[i] --;
    for (auto &v: v1) cout << v;
    for (int i = 0; i < c0; i ++) cout << 0; cout << '\n';

    for (int i = 0; i < 10; i ++)
        while (cnt2[i]) cout << i, cnt2[i] --;
    for (auto &v: v2) cout << v;
    for (int i = 0; i < c0; i ++) cout << 0; cout << '\n';

    return 0;
}