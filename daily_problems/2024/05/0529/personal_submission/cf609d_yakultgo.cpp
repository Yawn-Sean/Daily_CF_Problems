#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n), b(n);
    vector<int> day1(n), day2(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        day1[i] = i;
        if (i > 0) {
            if (a[i] > a[i - 1]) {
                day1[i] = day1[i - 1];
                a[i] = a[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        day2[i] = i;
        if (i > 0) {
            if (b[i] > b[i - 1]) {
                day2[i] = day2[i - 1];
                b[i] = b[i - 1];
            }
        }
    }
    vector<array<int, 3>> c(m);
    for (int i = 0; i < m; i++) {
        int t, x;
        cin >> t >> x;
        c[i] = {t, x, i + 1};
    }
    auto check = [&](int x) {
        int dollar = a[x - 1];
        int pound = b[x - 1];
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        for (int i = 0; i < m; i++) {
            if (c[i][0] == 1) {
                pq.push({1LL * c[i][1] * dollar, i});
            } else {
                pq.push({1LL * c[i][1] * pound, i});
            }
        }
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += pq.top().first;
            pq.pop();
        }
        return sum <= s;
    };
    int left = 1, right = n + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    if (left == n + 1) {
        cout << -1 << endl;
    } else {
        int x = left;
        int dollar = a[x - 1];
        int pound = b[x - 1];
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
        for (int i = 0; i < m; i++) {
            if (c[i][0] == 1) {
                pq.push({1LL * c[i][1] * dollar, i + 1, 1});
            } else {
                pq.push({1LL * c[i][1] * pound, i + 1, 2});
            }
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < k; i++) {
            auto [cost, idx, type] = pq.top();
            if (type == 1)
                ans.push_back({idx, day1[x - 1] + 1});
            else
                ans.push_back({idx, day2[x - 1] + 1});
            pq.pop();
        }
        cout << left << endl;
        for (auto [idx, day] : ans) {
            cout << idx << " " << day << endl;
        }
    }
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