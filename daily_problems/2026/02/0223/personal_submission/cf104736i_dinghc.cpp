#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1e9+7;
constexpr int A = 26;
constexpr int M = 1e5;
char s[M + 1];

int main() {
    long long N;
    scanf("%s %lld", s, &N);
    int cnts[A]{};
    int ins1 = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        for (int j = idx + 1; j < A; j++) {
            ins1 = (ins1 + cnts[j]) % MOD;
        }
        cnts[idx] += 1;
    }
    int ins2 = 0;
    for (int a = 0; a < A; a++) {
        int k = 0;
        for (int b = a + 1; b < A; b++) {
            k = (k + cnts[b]) % MOD;
        }
        ins2 = (ins2 + 1LL * k * cnts[a] % MOD) % MOD;
    }
    int ans = (1LL * ins1 * (N % MOD) % MOD + 1LL * N % MOD * ((N - 1) % MOD) / 2 % MOD * ins2 % MOD) % MOD;
    printf("%d\n", ans);
    return 0;
}

