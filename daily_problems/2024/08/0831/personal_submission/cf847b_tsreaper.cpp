#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> ans;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (ans.empty() || ans.back().back() > x) ans.push_back({x});
        else {
            int head = 0, tail = ans.size() - 1;
            while (head < tail) {
                int mid = (head + tail) >> 1;
                if (ans[mid].back() < x) tail = mid;
                else head = mid + 1;
            }
            ans[head].push_back(x);
        }
    }
    for (auto &vec : ans) {
        for (int x : vec) printf("%d ", x);
        printf("\n");
    }
    return 0;
}
