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

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();

    vector<int> suff(n1 + 1, n2);
    for (int i = n1 - 1; i >= 0; i --) {
        suff[i] = suff[i + 1];
        if (suff[i] && s1[i] == s2[suff[i] - 1])
            suff[i] --;
    }

    int pt = 0;
    vector<int> last_c(256, -2);
    
    for (int i = 0; i < n1; i ++) {
        if (pt < n2 && s1[i] == s2[pt]) {
            last_c[s1[i]] = pt;
            pt ++;
        }
        if (suff[i + 1] > last_c[s1[i]] + 1)
            return cout << "No", 0;
    }

    cout << "Yes";

    return 0;
}