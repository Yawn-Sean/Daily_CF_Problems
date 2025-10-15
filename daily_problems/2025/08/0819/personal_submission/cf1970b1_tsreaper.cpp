#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN + 5][3];

int main() {
    scanf("%d", &n);

    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec.push_back({x, i});
    }
    sort(vec.begin(), vec.end(), greater<pii>());

    int same = -1;
    for (int i = 0; i + 1 < n; i++) if (vec[i].first == vec[i + 1].first) { same = i; break; }

    if (vec.back().first == 0) {
        for (int i = 0, j = 1; i < n; i++) {
            int d = vec[i].first, idx = vec[i].second;
            if (d > 0) {
                ans[idx][0] = i + 1;
                ans[idx][1] = j;
                ans[idx][2] = vec[i + 1].second;
                if (j + d - 1 <= n) j += d - 1;
                else j -= d - 1;
            } else {
                ans[idx][0] = i + 1;
                ans[idx][1] = j;
                ans[idx][2] = idx;
            }
        }
    } else if (same >= 0) {
        int j = 1;

        for (int i = 0; i <= same; i++) {
            int d = vec[i].first, idx = vec[i].second;
            ans[idx][0] = i + 1;
            ans[idx][1] = j;
            ans[idx][2] = vec[i + 1].second;
            if (j + d - 1 <= n) j += d - 1;
            else j -= d - 1;
        }

        int idx = vec[same + 1].second;
        ans[idx][0] = same + 2;
        ans[idx][1] = j;
        ans[idx][2] = vec[same].second;

        for (int i = same + 2; i < n; i++) {
            int d = vec[i].first, idx = vec[i].second;
            if (j + d - 1 <= n) j += d - 1;
            else j -= d - 1;
            ans[idx][0] = i + 1;
            ans[idx][1] = j;
            ans[idx][2] = vec[i - 1].second;
        }
    } else if (n >= 3) {
        pii p = vec[n - 3];
        vec[n - 3] = vec[n - 2];
        vec[n - 2] = vec[n - 1];
        vec[n - 1] = p;

        for (int i = 0, j = 1; ; i++) {
            int d = vec[i].first, idx = vec[i].second;
            ans[idx][0] = i + 1;
            ans[idx][1] = j;
            if (i == n - 1) {
                ans[idx][2] = vec[i - 2].second;
                break;
            } else {
                ans[idx][2] = vec[i + 1].second;
                if (j + d - 1 <= n) j += d - 1;
                else j -= d - 1;
            }
        }
    } else {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i][2], "\n "[i < n]);
    return 0;
}
