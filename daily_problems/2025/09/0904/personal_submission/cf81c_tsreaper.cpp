#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, a, b, ans[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &a, &b);
    
    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec.push_back({x, i});
    }

    for (int i = 1; i <= n; i++) ans[i] = 2;
    if (a < b) {
        for (auto &p : vec) p.second *= -1;
        sort(vec.begin(), vec.end(), greater<pii>());
        for (int i = 0; i < a; i++) ans[-vec[i].second] = 1;
    } else if (a > b) {
        sort(vec.begin(), vec.end());
        for (int i = 0; i < a; i++) ans[vec[i].second] = 1;
    } else if (a == b) {
        for (int i = 1; i <= a; i++) ans[i] = 1;
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
