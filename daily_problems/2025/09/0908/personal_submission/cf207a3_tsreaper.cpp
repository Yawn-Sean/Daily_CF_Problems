#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;
typedef pair<int, int> pii;

int n, ans, A[MAXN + 5][5];

int main() {
    scanf("%d", &n);

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", &A[i][j]);
        tot += A[i][0];

        int last = A[i][1], tmp = 0;
        for (int j = 2; j <= A[i][0]; j++) {
            int nxt = (1LL * last * A[i][2] + A[i][3]) % A[i][4];
            if (nxt < last) tmp++;
            last = nxt;
        }
        ans = max(ans, tmp);
    }

    printf("%d\n", ans);
    if (tot > 2e5) return 0;

    set<array<int, 3>> st;
    for (int i = 1; i <= n; i++) st.insert({A[i][1], i, 1});

    int last = 0;
    vector<pii> vec;
    while (!st.empty()) {
        auto it = st.lower_bound(array<int, 3>{last, 0, 0});
        if (it == st.end()) it = st.begin();

        int v = (*it)[0], who = (*it)[1], idx = (*it)[2];
        st.erase(it);
        vec.push_back({v, who});
        last = v;
        if (idx < A[who][0]) {
            int nxt = (1LL * v * A[who][2] + A[who][3]) % A[who][4];
            st.insert(array<int, 3>{nxt, who, idx + 1});
        }
    }
    for (pii p : vec) printf("%d %d\n", p.first, p.second);
    return 0;
}
