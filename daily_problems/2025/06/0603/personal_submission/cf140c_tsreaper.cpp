#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n; scanf("%d", &n);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }

    priority_queue<pii> pq;
    for (auto &p : cnt) pq.push({p.second, p.first});
    vector<array<int, 3>> ans;
    while (pq.size() >= 3) {
        pii p[3];
        for (int i = 0; i < 3; i++) p[i] = pq.top(), pq.pop();
        sort(p, p + 3, [&](pii &a, pii &b){
            return a.second > b.second;
        });
        array<int, 3> arr;
        for (int i = 0; i < 3; i++) {
            arr[i] = p[i].second;
            if (p[i].first > 1) pq.push({p[i].first - 1, p[i].second});
        }
        ans.push_back(arr);
    }

    printf("%d\n", ans.size());
    for (auto &arr : ans) printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}
