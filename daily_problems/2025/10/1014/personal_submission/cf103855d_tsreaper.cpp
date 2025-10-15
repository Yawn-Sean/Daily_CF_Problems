#include  <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;
typedef pair<long long, int> pli;

int n, X[MAXN + 5], Y[MAXN + 5], A[MAXN + 5];
long long ans;

unordered_map<int, vector<int>> cols;
unordered_map<int, long long> mpX, mpY;

void gao() {
    cols.clear(); mpX.clear(); mpY.clear();
    for (int i = 1; i <= n; i++) {
        cols[X[i]].push_back(i);
        mpX[X[i]] += A[i];
        mpY[Y[i]] += A[i];
    }

    vector<pli> vec;
    for (auto &p : mpX) vec.push_back({p.second, p.first});
    sort(vec.begin(), vec.end(), greater<pli>());
    long long tmp = 0;
    for (int i = 0; i < vec.size() && i < 3; i++) tmp += vec[i].first;
    ans = max(ans, tmp);

    multiset<long long> ms;
    for (auto &p : mpY) ms.insert(p.second);
    for (auto &p : cols) {
        auto &pos = p.second;
        for (int idx : pos) {
            long long t = mpY[Y[idx]];
            ms.erase(ms.find(t));
            ms.insert(t - A[idx]);
        }

        long long tmp = mpX[p.first];
        auto it = ms.rbegin();
        for (int i = 0; it != ms.rend() && i < 2; i++, it++) tmp += *it;
        ans = max(ans, tmp);

        for (int idx : pos) {
            long long t = mpY[Y[idx]];
            ms.erase(ms.find(t - A[idx]));
            ms.insert(t);
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d%d%d", &X[i], &Y[i], &A[i]);
    gao();

    for (int i = 1; i <= n; i++) swap(X[i], Y[i]);
    gao();

    printf("%lld\n", ans);
    return 0;
}
