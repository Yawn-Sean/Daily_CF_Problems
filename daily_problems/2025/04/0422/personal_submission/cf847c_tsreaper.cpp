#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n;
long long K;

int cnt[MAXN + 5];

int main() {
    scanf("%d%lld", &n, &K);
    
    long long sm = 1LL * (n - 1) * n / 2;
    if (sm < K) { printf("Impossible\n"); return 0; }
    
    for (int i = 0; i < n; i++) cnt[i] = 1;
    for (int i = n - 1; i > 0 && sm > K; i--) {
        cnt[i] = 0;
        long long det = sm - K;
        if (det < i) cnt[i - det]++, sm -= det;
        else cnt[0]++, sm -= i;
    }

    string ans1, ans2;
    for (int i = 0; cnt[i] > 0; i++) {
        for (int j = 1; j < cnt[i]; j++) ans1 += "()";
        ans1 += "("; ans2 += ")";
    }
    reverse(ans2.begin(), ans2.end());
    ans1 += ans2;
    printf("%s\n", ans1.c_str());
    return 0;
}
