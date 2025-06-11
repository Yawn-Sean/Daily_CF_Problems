#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, K, S, A[MAXN + 10], B[MAXN + 10];
int dayA, dayB, buyA, buyB;

vector<pii> va, vb;
long long fb[MAXN + 10];

bool check(int lim) {
    int X = 2e9, Y = 2e9;
    for (int i = 1; i <= lim; i++) {
        if (X > A[i]) X = A[i], dayA = i;
        if (Y > B[i]) Y = B[i], dayB = i;
    }

    long long rem = S;
    for (int i = 0; ; i++) {
        int head = 0, tail = vb.size();
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (1LL * fb[mid] * Y <= rem) head = mid;
            else tail = mid - 1;
        }
        if (i + head >= K) {
            buyA = i; buyB = head;
            return true;
        }
        if (i == va.size()) return false;
        rem -= 1LL * va[i].first * X;
        if (rem < 0) return false;
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &K, &S);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == 1) va.push_back(pii(y, i));
        else vb.push_back(pii(y, i));
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for (int i = 1; i <= vb.size(); i++) fb[i] = fb[i - 1] + vb[i - 1].first;

    if (!check(n)) { printf("-1\n"); return 0; }
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }

    check(head);
    printf("%d\n", head);
    for (int i = 0; i < buyA; i++) printf("%d %d\n", va[i].second, dayA);
    for (int i = 0; i < buyB; i++) printf("%d %d\n", vb[i].second, dayB);
    return 0;
}
