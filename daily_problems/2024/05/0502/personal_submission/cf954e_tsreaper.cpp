#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, T, A[MAXN + 10], B[MAXN + 10];

int main() {
    int n, T; scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    vector<int> L, R;
    long long totL = 0, smL = 0, totR = 0, smR = 0;
    int mn = 1e9, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (B[i] < T) {
            L.push_back(i);
            totL += 1LL * A[i] * B[i];
            smL += A[i];
        } else {
            R.push_back(i);
            totR += 1LL * A[i] * B[i];
            smR += A[i];
        }
        mn = min(mn, B[i]); mx = max(mx, B[i]);
    }

    if (T < mn || T > mx) { printf("0\n"); return 0; }
    if (totL + totR == T * (smL + smR)) {
        printf("%lld\n", smL + smR);
    } else if (totL + totR > T * (smL + smR)) {
        sort(R.begin(), R.end(), [&](int x, int y) {
            return B[x] < B[y];
        });
        totR = 0; smR = 0;
        for (int i = 0; i < R.size(); i++) {
            long long totNxt = totR + 1LL * A[R[i]] * B[R[i]];
            long long smNxt = smR + 1LL * A[R[i]];
            if (totL + totNxt > T * (smL + smNxt)) {
                double x = T * (smL + smR) - totL - totR;
                x /= B[R[i]] - T;
                printf("%.12f\n", smL + smR + x);
                break;
            }
            totR = totNxt; smR = smNxt;
        }
    } else {
        sort(L.begin(), L.end(), [&](int x, int y) {
            return B[x] > B[y];
        });
        totL = 0; smL = 0;
        for (int i = 0; i < L.size(); i++) {
            long long totNxt = totL + 1LL * A[L[i]] * B[L[i]];
            long long smNxt = smL + 1LL * A[L[i]];
            if (totR + totNxt < T * (smR + smNxt)) {
                double x = T * (smL + smR) - totL - totR;
                x /= B[L[i]] - T;
                printf("%.12f\n", smL + smR + x);
                break;
            }
            totL = totNxt; smL = smNxt;
        }
    }
    return 0;
}
