#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    long long L;
    scanf("%d%lld", &N, &L);
    vector<long long> x(N + 1, 0);
    for (int i = 1; i < N; i++) {
        scanf("%lld", &x[i]);
    }
    x[N] = L;
    vector<pair<long long, long long>> l(N);
    for (int i = 2, j = 1; i < N; i++) {
        while (x[j] < x[i] / 2) {
            j += 1;
        }
        if (x[j] * 2 - x[i] < x[i] - x[j - 1] * 2) {
            l[i] = make_pair(x[j], x[i] - x[j]);
        } else {
            l[i] = make_pair(x[i] - x[j - 1], x[j - 1]);
        }
    }
    vector<pair<long long, long long>> r(N);
    for (int i = N - 2, j = N - 1; i >= 0; i--) {
        while ((L - x[j]) <= (L - x[i]) / 2) {
            j -= 1;
        }
        if ((L - x[j]) * 2 - (L - x[i]) < (L - x[i]) - (L - x[j + 1]) * 2) {
            r[i] = make_pair((L - x[j]), (L - x[i]) - (L - x[j]));
        } else {
            r[i] = make_pair((L - x[i]) - (L - x[j + 1]), (L - x[j + 1]));
        }
    }
    long long ans = 1e15;
    for (int i = 2; i < N - 1; i++) {
        auto& [lmx, lmn] = l[i];
        auto& [rmx, rmn] = r[i];
        ans = min(ans, max(lmx, rmx) - min(lmn, rmn));
    }
    printf("%lld\n", ans);
    return 0;
}

