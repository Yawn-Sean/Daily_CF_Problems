#include <bits/stdc++.h>
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

long long gao(int a, int &cnt2, int &cnt3) {
    long long ret = a;
    while (ret % 2 == 0) ret /= 2, cnt2++;
    while (ret % 3 == 0) ret /= 3, cnt3++;
    return ret;
}

pii calc(int a, int b, int cnt2, int cnt3) {
    while (cnt3 > 0 && a % 3 == 0) a = a / 3 * 2, cnt3--;
    while (cnt3 > 0 && b % 3 == 0) b = b / 3 * 2, cnt3--;
    while (cnt2 > 0 && a % 2 == 0) a /= 2, cnt2--;
    while (cnt2 > 0 && b % 2 == 0) b /= 2, cnt2--;
    return pii(a, b);
}

int main() {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    int cnt2[2] = {0}, cnt3[2] = {0};
    long long x = gao(a, cnt2[0], cnt3[0]) * gao(b, cnt2[0], cnt3[0]);
    long long y = gao(c, cnt2[1], cnt3[1]) * gao(d, cnt2[1], cnt3[1]);
    if (x != y) { printf("-1\n"); return 0; }

    int best = INF;
    pii ans1, ans2;
    for (int i = 0; i <= cnt3[0]; i++) for (int j = 0; j <= cnt2[0] + i; j++) {
        int rem2 = cnt2[0] + i - j, rem3 = cnt3[0] - i;
        int det3 = cnt3[1] - rem3;
        if (det3 < 0) continue;
        int det2 = cnt2[1] + det3 - rem2;
        if (det2 < 0) continue;
        if (i + j + det2 + det3 < best) {
            best = i + j + det2 + det3;
            ans1 = calc(a, b, j, i);
            ans2 = calc(c, d, det2, det3);
        }
    }
    
    if (best < INF) {
        printf("%d\n", best);
        printf("%d %d\n%d %d\n", ans1.first, ans1.second, ans2.first, ans2.second);
    } else {
        printf("-1\n");
    }
    return 0;
}
