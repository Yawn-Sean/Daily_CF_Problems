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
    int n, q;
    cin >> n >> q;
    int p_x = 0, read = 0;
    vector<int> que, tail(n + 1, -1), cnt(n + 1, 0);
    rep(i, 1, q) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            que.push_back(x);
            ++cnt[x];
        } else if(op == 2){
            read += cnt[x];
            cnt[x] = 0;
            tail[x] = que.size() - 1;
        } else {
            while(p_x < x) {
                if(tail[que[p_x]] < p_x) {
                    cnt[que[p_x]]--;
                    ++read;
                }
                ++p_x;
            }
        }
        cout << (que.size() - read) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
