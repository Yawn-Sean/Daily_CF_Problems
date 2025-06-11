#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

long long X, Y;
int n, m;
char s1[MAXN + 5], s2[MAXN + 5];

int g;
long long ans;

void gao(int base) {
    vector<int> vec;
    for (int i = 0; i < m / g; i++)
        vec.push_back(s2[(base + 1LL * i * (n - m)) % m] - 'a');

    long long cnt[26] = {0};
    for (int x : vec) cnt[x]++;
    for (int i = 0; i < 26; i++) cnt[i] *= X / vec.size();

    int rem = X % vec.size();
    int tmp[26] = {0};
    for (int i = 0; i < rem; i++) tmp[vec[i]]++;
    for (int i = 0; ; i++) {
        int idx = (base + 1LL * i * (n - m)) % n;
        for (int j = 0; j < 26; j++) if (j != s1[idx] - 'a') ans += cnt[j] + tmp[j];
        if (i + 1 == n / g) break;
        tmp[vec[i % vec.size()]]--; tmp[vec[(i + rem) % vec.size()]]++;
    }
}

int main() {
    scanf("%lld%lld%s%s", &X, &Y, s1, s2);
    n = strlen(s1); m = strlen(s2);
    if (n < m) swap(X, Y), swap(n, m), swap(s1, s2);

    g = gcd(n, m);
    for (int i = 0; i < g; i++) gao(i);
    printf("%lld\n", ans);
    return 0;
}
