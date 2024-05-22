#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD 1001001001001001007LL
#define BASE 233
using namespace std;

int n, ans;
char s1[MAXN + 10], s2[MAXN + 10];

__int128 P[MAXN + 10], H1[MAXN + 10], H2[MAXN + 10];

vector<__int128> calc(char *s, __int128 *H) {
    H[0] = 0;
    for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + s[i]) % MOD;

    vector<__int128> vec;
    for (int i = 1; i <= n; i++) {
        for (int c = 'a'; c <= 'z'; c++) {
            __int128 h = (H[i - 1] * BASE + c) % MOD * P[n + 1 - i] % MOD;
            __int128 t = (H[n] - H[i - 1] * P[n + 1 - i] % MOD + MOD) % MOD;
            h = (h + t) % MOD;
            vec.push_back(h);
        }
    }
    for (int c = 'a'; c <= 'z'; c++) {
        __int128 h = (H[n] * BASE + c) % MOD;
        vec.push_back(h);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    return vec;
}

int main() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
    auto vec1 = calc(s1, H1), vec2 = calc(s2, H2);
    for (int i = 0, j = 0; i < vec1.size(); i++) {
        while (j < vec2.size() && vec2[j] < vec1[i]) j++;
        if (vec1[i] == vec2[j]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
