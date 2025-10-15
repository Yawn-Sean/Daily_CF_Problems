#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, A[MAXN + 5];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    vector<int> vec = {1};
    for (int i = 2; i <= n; i++) if (A[i] > A[vec.back()]) vec.push_back(i);

    ans = 1;
    for (int i = 0; i + 1 < vec.size(); i++) ans = ans * (vec[i + 1] - vec[i] + 1) % MOD;
    printf("%lld\n", ans);
    return 0;
}
