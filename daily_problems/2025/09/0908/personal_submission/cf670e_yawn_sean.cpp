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

    int n, m, p;
    cin >> n >> m >> p;

    string s;
    cin >> s;

    vector<int> s1, s2;

    for (auto &c: s) {
        if (c == '(') s1.emplace_back(1);
        else s1.emplace_back(-1);
    }

    while (s1.size() > p) {
        int x = s1.back(); s1.pop_back();
        s2.emplace_back(x);
    }
    
    cin >> s;

    for (auto &c: s) {
        if (c == 'R') {
            int x = s2.back(); s2.pop_back();
            s1.emplace_back(x);
        }
        else if (c == 'L') {
            int x = s1.back(); s1.pop_back();
            s2.emplace_back(x);
        }
        else {
            int x = s1.back(); s1.pop_back();
            if (x == 1) {
                while (x) {
                    x += s2.back();
                    s2.pop_back();
                }
            }
            else {
                while (x) {
                    x += s1.back();
                    s1.pop_back();
                }
            }

            if (s2.size()) {
                x = s2.back(); s2.pop_back();
                s1.emplace_back(x);
            }
        }
    }

    while (!s2.empty()) {
        s1.emplace_back(s2.back());
        s2.pop_back();
    }

    for (auto &c: s1) cout << (c == 1 ? '(' : ')');

    return 0;
}