#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXK ((int) 1e5)
using namespace std;

int n, K, A[MAXN + 10];
long long ans;

vector<int> pos[MAXK + 10];

int main() {
    scanf("%d%d", &K, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), pos[A[i]].push_back(i);

    long long base = 0;
    for (int i = 2; i <= n; i++) base += abs(A[i] - A[i - 1]);

    ans = 1e18;
    for (int i = 1; i <= K; i++) if (!pos[i].empty()) {
        vector<int> vec;
        long long det = 0;
        for (int x : pos[i]) {
            if (x > 1 && A[x - 1] != i) vec.push_back(A[x - 1]), det -= abs(A[x - 1] - i);
            if (x < n && A[x + 1] != i) vec.push_back(A[x + 1]), det -= abs(A[x + 1] - i);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++) det += abs(vec[vec.size() / 2] - vec[i]);
        ans = min(ans, base + det);
    }
    printf("%lld\n", ans);
    return 0;
}
