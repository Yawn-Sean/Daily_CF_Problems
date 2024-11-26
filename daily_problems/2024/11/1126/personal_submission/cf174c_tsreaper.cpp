#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];
vector<pii> ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    vector<int> vec;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = A[i - 1] + 1; j <= A[i]; j++) vec.push_back(i);
        for (int j = A[i - 1]; j > A[i]; j--) ans.push_back({vec.back(), i - 1}), vec.pop_back();
    }

    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
