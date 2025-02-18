#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <numeric>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 2000;
int mem[26][N];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> num(n);
    for (int i = 0; i < n; i++) num[i] = s[i] - 'a';
    for (int c = 0; c < 26; c++) {
        for (int lim = 1; lim <= n; lim++) {
            int r = 0, used = 0;
            for (int i = 0; i < n; i++) {
                while (r < n) {
                    if (num[r] == c) {
                        r++;
                        continue;
                    }
                    if (used == lim) {
                        break;
                    }
                    r++;
                    used++;
                }
                mem[c][lim] = max(mem[c][lim], r - i);
                if (num[i] != c) used--;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int m; string qu;
        cin >> m >> qu;
        int c = qu[0] - 'a';
        cout << mem[c][m] << "\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    solve();
}
