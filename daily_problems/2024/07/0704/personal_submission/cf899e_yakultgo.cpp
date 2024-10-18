#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int pre[N], nex[N], cnt[N];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(pre, -1, sizeof(pre));
    memset(nex, -1, sizeof(nex));
    vector<int> cnt(n);
    auto cmp = [&](pair<int, int> &t1, pair<int, int> &t2) {
        if (t1.first == t2.first) return t1.second > t2.second;
        return t1.first < t2.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        nex[i] = j;
        pre[j] = i;
        cnt[i] = j - i;
        pq.push({cnt[i], i});
        i = j;
    }
    set<int> st;
    int ans = 0;
    while (pq.size()) {
        auto [c, i] = pq.top();
        pq.pop();
        if (st.count(i)) continue;
        ans++;
        st.insert(i);
        // 判断i的前一个和后一个是否相等
        if (pre[i] != -1 && nex[i] != -1 && a[pre[i]] == a[nex[i]]) {
            int j = pre[i], k = nex[i];
            pq.push({cnt[j] + cnt[k], j});
            st.insert(k);
            cnt[j] += cnt[k];
            nex[j] = nex[k];
            if (nex[k] != -1) pre[nex[k]] = j;
        } else {
            if (pre[i] != -1) nex[pre[i]] = nex[i];
            if (nex[i] != -1) pre[nex[i]] = pre[i];
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}