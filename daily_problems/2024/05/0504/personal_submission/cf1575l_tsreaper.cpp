#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

int n, ans, A[MAXN + 10];

int f[MAXN + 10];

int main() {
    scanf("%d", &n);
    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        int det = i - A[i];
        if (det >= 0) vec.push_back(pii(det, A[i]));
    }
    sort(vec.begin(), vec.end());

    int m = vec.size();
    for (int i = 1; i <= m; i++) f[i] = INF;
    for (int i = 0; i < m; i++) {
        int head = 0, tail = i;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (f[mid] < vec[i].second) head = mid;
            else tail = mid - 1;
        }
        int t = head + 1;
        ans = max(ans, t);
        f[t] = vec[i].second;
    }
    printf("%d\n", ans);
    return 0;
}
