#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for(int i = start; i <= end; ++i)
#define erp(i, end, start) for(int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26, -1);
    int p, q;
    for(int i = 0; i < 27; ++i) {
        int v = s[i] - 'A';
        if(cnt[v] != -1) {
            p = cnt[v];
            q = i;
            break;
        }
        cnt[v] = i;
    }
    if(p + 1 == q) {
        cout << "Impossible" << endl;
        return;
    }
    // 处理环
    vector<string> ch(2, string(13, ' '));
    int d = abs(p - q) + 1, r = p;
    int x0 = 13 - d / 2;
    rep(i, x0, 12) {
        ch[0][i] = s[r];
        ++r;
    }
    int x1 = x0 + (d % 2 == 0);
    erp(i, 12, x1) {
        ch[1][i] = s[r];
        ++r;
    }
    --x0; --x1;
    --p; ++q;
    if(x0 != x1) {
        if(p >= 0) {
            ch[1][x1] = s[p];
            --p;
            --x1;
        } else if(q < n) {
            ch[1][x1] = s[q];
            --x1;
            ++q;
        }
    }
    while(p >= 0 && q < n) {
        ch[0][x0] = s[p];
        ch[1][x0] = s[q];
        --p; ++q;
        --x0;
    }
    while(x0 >= 0) {
        if(p >= 0) {
            ch[0][x0] = s[p];
            ch[1][x0] = s[p - 1];
            p -= 2;
        } else {
            ch[0][x0] = s[q];
            ch[1][x0] = s[q + 1];
            q += 2;
        }
        --x0;
    }
    rep(i, 0, 1) cout << ch[i] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
