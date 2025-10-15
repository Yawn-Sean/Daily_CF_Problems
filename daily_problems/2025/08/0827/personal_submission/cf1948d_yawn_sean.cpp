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

    int t;
    cin >> t;

    while (t --) {
        string s;
        cin >> s;

        int n = s.size(), ans = 0;
        vector<int> lcp(n + 1, 0);

        for (int i = n - 1; i >= 0; i --) {
            for (int j = i + 1; j < n; j ++) {
                lcp[j] = ((s[j] == s[i] || s[i] == '?' || s[j] == '?') ? lcp[j + 1] + 1 : 0);
                if (lcp[j] >= j - i) ans = max(ans, j - i);
            }
        }
        
        cout << ans * 2 << '\n';
    }

    return 0;
}