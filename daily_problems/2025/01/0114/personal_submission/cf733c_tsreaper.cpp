#include <bits/stdc++.h>
#define MAXN 500
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int m; scanf("%d", &m);
    vector<pii> ans;
    int j = 1;
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        int sm = 0, last = j;
        while (j <= n && sm < x) sm += A[j], j++;
        if (sm != x) { printf("NO\n"); return 0; }
        int len = j - last;
        if (len == 1) continue;

        int mn = A[last], mx = A[last];
        for (int k = last; k < j; k++) {
            mn = min(mn, A[k]);
            mx = max(mx, A[k]);
        }
        if (mn == mx) { printf("NO\n"); return 0; }

        for (int k = last; k < j; k++) if (A[k] == mx) {
            bool ok = false;
            if (k > last && A[k - 1] < A[k]) ok = true;
            if (k + 1 < j && A[k + 1] < A[k]) ok = true;
            if (ok) {
                int l = k - 1, r = k + 1;
                int now = A[k], pos = i + k - last;
                for (int t = 1; t < len; t++) {
                    if (l >= last && A[l] < now) {
                        ans.push_back({pos, -1});
                        now += A[l];
                        l--; pos--;
                    } else {
                        ans.push_back({pos, 1});
                        now += A[r];
                        r++;
                    }
                }
                break;
            }
        }
    }
    if (j <= n) { printf("NO\n"); return 0; }

    printf("YES\n");
    for (pii p : ans) printf("%d %c\n", p.first, p.second > 0 ? 'R' : 'L');
    return 0;
}
