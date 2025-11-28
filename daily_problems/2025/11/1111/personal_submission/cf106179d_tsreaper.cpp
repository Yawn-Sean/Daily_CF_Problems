#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int mid = n / 2;
    vector<int> L, R;
    for (int i = 1; i <= mid; i++) L.push_back(A[i]);
    sort(L.begin(), L.end());
    for (int i = mid + 1; i <= n; i++) R.push_back(A[i]);
    sort(R.begin(), R.end());

    if (L.back() < R[0] || L[0] > R.back()) {
        printf("1\n%d", n);
        for (int i = 1; i <= n; i++) printf(" %d", A[i]);
        printf("\n");
        return;
    }

    int kl, kr;
    for (int i = 1; i <= mid; i++) if (L[i - 1] > R[mid - i]) {
        kl = L[i - 1];
        kr = R[mid - i];
        break;
    }
    printf("2\n");
    vector<int> vec;
    for (int i = 1; i <= mid; i++) if (A[i] < kl) vec.push_back(A[i]);
    for (int i = mid + 1; i <= n; i++) if (A[i] > kr) vec.push_back(A[i]);
    printf("%d", vec.size());
    for (int x : vec) printf(" %d", x);
    printf("\n");
    vec.clear();
    for (int i = 1; i <= mid; i++) if (A[i] >= kl) vec.push_back(A[i]);
    for (int i = mid + 1; i <= n; i++) if (A[i] <= kr) vec.push_back(A[i]);
    printf("%d", vec.size());
    for (int x : vec) printf(" %d", x);
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
