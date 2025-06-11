#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, A[MAXN + 10];
long long ans;

vector<int> vec[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        vec[A[i] % m].push_back(i);
    }

    int goal = n / m;
    vector<int> now;
    for (int pos = 0; pos < m * 2; pos++) {
        int i = pos % m;
        while (vec[i].size() > goal) {
            now.push_back(vec[i].back());
            vec[i].pop_back();
            ans -= pos;
        }
        while (now.size() > 0 && vec[i].size() < goal) {
            int idx = now.back(); now.pop_back();
            vec[i].push_back(idx);
            ans += pos;
            A[idx] += (i - A[idx] % m + m) % m;
        }
    }
    assert(now.empty());

    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
