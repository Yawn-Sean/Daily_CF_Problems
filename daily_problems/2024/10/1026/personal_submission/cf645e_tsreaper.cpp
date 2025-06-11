#include <bits/stdc++.h>
#define MAXM ((int) 1e6)
#define MAXK 26
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
char s[MAXM + 10];

long long sm, f[MAXK];
vector<int> vec;

void pick(int x) {
    for (int i = 0; i < K; i++) if (vec[i] == x) {
        for (int j = i; j + 1 < K; j++) vec[j] = vec[j + 1];
        vec[K - 1] = x;
        return;
    }
}

int main() {
    scanf("%d%d%s", &n, &K, s + 1);
    for (int i = 0; i < K; i++) vec.push_back(i);

    sm = 1;
    for (int i = 1; s[i]; i++) {
        int c = s[i] - 'a';
        long long t = (sm - f[c] + MOD) % MOD;
        f[c] = sm;
        sm = (sm + t) % MOD;
        pick(c);
    }

    for (int i = 0; i < n; i++) {
        int c = vec[i % K];
        long long t = (sm - f[c] + MOD) % MOD;
        f[c] = sm;
        sm = (sm + t) % MOD;
    }

    printf("%lld\n", sm);
    return 0;
}
