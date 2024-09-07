#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

int main() {
    int n, xa, xb; scanf("%d%d%d", &n, &xa, &xb);
    vector<pll> vec;
    for (int i = 1; i <= n; i++) {
        int k, b; scanf("%d%d", &k, &b);
        vec.push_back({1LL * k * xa + b, 1LL * k * xb + b});
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++) if (vec[i].second < vec[i - 1].second) { printf("YES\n"); return 0; }
    printf("NO\n"); return 0;
}
