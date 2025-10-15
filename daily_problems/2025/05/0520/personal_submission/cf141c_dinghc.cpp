#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3000;
constexpr int S = 10;
char id[N][S + 1];
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", id[i], &a[i]);
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&] (int i, int j) -> bool {
        return a[i] < a[j];
    });
    vector<int> ans;
    vector<int> h(n);
    int curr = n;
    for (auto& i : idx) {
        h[i] = curr--;
        if (a[i] > ans.size()) {
            printf("-1");
            return 0;
        }
        vector<int> tmp;
        copy(ans.begin(), ans.begin() + a[i], back_inserter(tmp));
        tmp.push_back(i);
        copy(ans.begin() + a[i], ans.end(), back_inserter(tmp));
        ans.swap(tmp);
    }
    for (auto& i : ans) {
        printf("%s %d\n", id[i], h[i]);
    }
    return 0;
}

