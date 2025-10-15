#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    priority_queue<pair<int,int>> pq;
    for (auto& [k, v]: cnt) {
        pq.push({v, k});
    }

    vector<tuple<int,int,int>> ans;
    while (pq.size() >= 3) {
        auto p1 = pq.top();
        pq.pop();
        auto p2 = pq.top();
        pq.pop();
        auto p3 = pq.top();
        pq.pop();

        int r1 = p1.second, r2 = p2.second, r3 = p3.second;
        vector<int> v{r1, r2, r3};
        sort(v.begin(), v.end());
        ans.emplace_back(v[2], v[1], v[0]);

        p1.first -= 1;
        p2.first -= 1;
        p3.first -= 1;
        if (p1.first > 0) {
            pq.push(p1);
        }
        if (p2.first > 0) {
            pq.push(p2);
        }
        if (p3.first > 0) {
            pq.push(p3);
        }
    }

    cout << ans.size() << endl;
    for (auto& [a, b, c]: ans) {
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}
