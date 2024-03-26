#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n, 0);
    stack<int> st;
    set<int> s;
    for (int i = 0; i < 2 * n; ++i) {
        char op;
        cin >> op;
        if (op == '+') { // 放物品
            st.emplace(i); // i 这个时候放了物品
        } else {
            cin >> a[i];
            if (st.empty()) { // 没有物品可以买了
                cout << "NO";
                return ;
            }
            a[st.top()] = a[i]; // 最近一次放物品的位置放的这个时候买的物品
            st.pop();
            a[i] = -a[i]; // 标记为卖的位置
        }
    }
    for (int ai : a) {
        if (ai > 0) { // 这个时候放了这个物品
            s.insert(ai);
        } else {
            if (*s.begin() < -ai) { // 买的位置不对
                cout << "NO" << endl;
                return;
            }
            s.erase(s.begin());
        }
    }
    cout << "YES" << endl;
    for (int ai : a) {
        if (ai > 0) {
            cout << ai << " ";
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
