#include <bits/stdc++.h>
#define MAXN ((int) 4e5)
using namespace std;

int n, A[MAXN + 5];

long long gao(int x) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) if (A[i] != n / 2 && A[i] != n / 2 + 1) vec.push_back(A[i]);

    vector<int> goal;
    for (int i = 0; i < n - 2; i++) goal.push_back(i & 1 ^ x);

    long long ret = 0;
    for (int i = 0, j = 0; i < n - 2; i++) if (goal[i] == 1) {
        while (j < n - 2 && vec[j] < n / 2) j++;
        ret += abs(i - j);
        j++;
    }
    return ret;
}

void solve() {
    scanf("%d", &n);

    int x, y;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == n / 2) x = i;
        if (A[i] == n / 2 + 1) y = i;
    }

    long long ans1 = 0;
    for (int i = 1; i <= n / 2; i++) ans1 -= i * 2;
    for (int i = n / 2 + 1; i <= n; i++) ans1 += i * 2;

    long long ans2 = gao(1);
    ans2 += x - 1;
    ans2 += n - y;
    if (x > y) ans2--;

    long long ans3 = gao(0);
    ans3 += n - x;
    ans3 += y - 1;
    if (x < y) ans3--;

    printf("%lld %lld\n", ans1 - 1, min(ans2, ans3));
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
