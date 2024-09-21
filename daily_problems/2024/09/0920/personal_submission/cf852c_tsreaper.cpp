#include <bits/stdc++.h>
#define MAXN 50000
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN], ans[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    vector<pii> vec;
    for (int i = 0; i < n; i++) vec.push_back({A[i] + A[(i + 1) % n], i});
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) ans[vec[i].second] = i;
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
