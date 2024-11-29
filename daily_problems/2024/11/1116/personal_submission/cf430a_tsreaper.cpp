#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN + 5];

int main() {
    scanf("%d%*d", &n);
    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec.push_back({x, i});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) ans[vec[i].second] = i & 1;
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
