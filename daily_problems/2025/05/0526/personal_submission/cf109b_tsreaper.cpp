#include <bits/stdc++.h>
#define INF ((int) 1e9 + 7)
using namespace std;

vector<int> vec;

void dfs(int d, int now) {
    if (d >= 1) vec.push_back(now);
    if (d == 9) return;
    dfs(d + 1, now * 10 + 4);
    dfs(d + 1, now * 10 + 7);
}

double calc(int L, int R, int l, int r) {
    int ll = max(L, l), rr = min(R, r);
    if (ll > rr) return 0;
    return 1.0 * (rr - ll + 1) / (R - L + 1);
}

int main() {
    dfs(0, 0);
    vec.push_back(0); vec.push_back(INF);
    sort(vec.begin(), vec.end());

    int l1, r1, l2, r2, K; scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &K);
    double ans = 0;
    if (K > 1) {
        for (int i = 1; i + K < vec.size(); i++) {
            ans += calc(l1, r1, vec[i - 1] + 1, vec[i]) * calc(l2, r2, vec[i + K - 1], vec[i + K] - 1);
            ans += calc(l2, r2, vec[i - 1] + 1, vec[i]) * calc(l1, r1, vec[i + K - 1], vec[i + K] - 1);
        }
    } else {
        for (int i = 1; i + 1 < vec.size(); i++) {
            ans += calc(l1, r1, vec[i - 1] + 1, vec[i] - 1) * calc(l2, r2, vec[i], vec[i + 1] - 1);
            ans += calc(l1, r1, vec[i] + 1, vec[i + 1] - 1) * calc(l2, r2, vec[i - 1] + 1, vec[i]);
            ans += calc(l1, r1, vec[i], vec[i]) * calc(l2, r2, vec[i - 1] + 1, vec[i + 1] - 1);
        }
    }
    printf("%.12f\n", ans);
    return 0;
}
