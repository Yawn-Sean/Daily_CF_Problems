#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n; scanf("%d", &n);
    unordered_map<int, unordered_map<int, vector<pii>>> mp;
    for (int i = 1; i <= n; i++) {
        int A[3];
        long long sm = 0;
        for (int j = 0; j < 3; j++) scanf("%d", &A[j]), sm += A[j];

        for (int j = 0; j < 3; j++) for (int k = j + 1; k < 3; k++) {
            int x = A[j], y = A[k];
            if (x > y) swap(x, y);
            auto &vec = mp[x][y];
            if (!vec.empty() && vec.back().second == i) continue;
            vec.push_back({sm - x - y, i});
        }
    }

    vector<int> ans;
    int best = 0;
    for (auto &e1 : mp) for (auto &e2 : e1.second) {
        int x = e1.first, y = e2.first;
        auto &vec = e2.second;
        if (vec.size() == 1) {
            int t = min({x, y, vec[0].first});
            if (t > best) best = t, ans = {vec[0].second};
        } else {
            sort(vec.begin(), vec.end(), greater<pii>());
            int t = min({x, y, vec[0].first + vec[1].first});
            if (t > best) best = t, ans = {vec[0].second, vec[1].second};
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
