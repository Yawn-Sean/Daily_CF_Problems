#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, ans;
vector<int> vec[MAXN];

int count(int id, int l, int r) {
    return upper_bound(vec[id].begin(), vec[id].end(), r) - lower_bound(vec[id].begin(), vec[id].end(), l);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k; scanf("%d", &k);
        while (k--) {
            int x; scanf("%d", &x);
            vec[i].push_back(x);
        }
        sort(vec[i].begin(), vec[i].end());
    }

    for (int i = 0; i < n; i++) for (int j = 1; j < vec[i].size(); j++) {
        int x = count((i - 1 + n) % n, vec[i][j - 1], vec[i][j]);
        int y = count((i + 1) % n, vec[i][j - 1], vec[i][j]);
        if (x != y) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
