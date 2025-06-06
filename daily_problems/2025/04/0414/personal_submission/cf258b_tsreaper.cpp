#include <bits/stdc++.h>
#define MAXP 10
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
long long ans;

vector<int> A;
int f[MAXP + 5][MAXP + 5], g[MAXP + 5], tmp[MAXP + 5];

int dp(int pos, int cnt, bool full) {
    if (pos < 0) return cnt == 0 ? 1 : 0;
    if (!full && f[pos][cnt] >= 0) return f[pos][cnt];

    int ret = 0;
    int R = (full ? A[pos] : 9);
    for (int i = 0; i <= R; i++)
        ret += dp(pos - 1, cnt - (i == 4 || i == 7 ? 1 : 0), full && i == R);
    if (!full) f[pos][cnt] = ret;
    return ret;
}

long long dfs(int dep, int rem) {
    if (dep == 6) {
        long long ret = 1;
        for (int i = 0; i <= A.size(); i++) for (int j = 0; j < tmp[i]; j++)
            ret = ret * (g[i] - j) % MOD;
        return ret;
    }

    long long ret = 0;
    for (int i = 0; i < rem; i++) {
        tmp[i]++;
        ret = (ret + dfs(dep + 1, rem - i)) % MOD;
        tmp[i]--;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    memset(f, -1, sizeof(f));

    for (int x = n; x; x /= 10) A.push_back(x % 10);
    for (int i = 0; i <= A.size(); i++) g[i] = dp(A.size() - 1, i, true);
    g[0]--;
    for (int i = 1; i <= A.size(); i++) ans = (ans + dfs(0, i) * g[i]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
