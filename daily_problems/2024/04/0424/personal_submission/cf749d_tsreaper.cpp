#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, q, A[MAXN + 10][2];

int main() {
    scanf("%d", &n);
    unordered_map<int, vector<int>> bids;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &A[i][0], &A[i][1]);
        bids[A[i][0]].push_back(i);
    }

    vector<int> vec;
    unordered_map<int, int> mp;
    set<int> best;
    for (int i = n; i > 0; i--) {
        if (mp.count(A[i][0])) continue;
        vec.push_back(A[i][0]);
        mp[A[i][0]] = i;
        best.insert(i);
    }

    scanf("%d", &q);
    while (q--) {
        unordered_set<int> st;
        int len; scanf("%d", &len);
        while (len--) {
            int x; scanf("%d", &x);
            st.insert(x);
        }

        int who = 0;
        for (int x : vec) if (st.count(x) == 0) { who = x; break; }
        if (who == 0) { printf("0 0\n"); continue; }

        for (int x : st) best.erase(mp[x]);
        best.erase(mp[who]);
        auto &b = bids[who];
        int t = best.empty() ? 0 : *prev(best.end());
        int idx = *upper_bound(b.begin(), b.end(), t);
        printf("%d %d\n", who, A[idx][1]);
        for (int x : st) best.insert(mp[x]);
        best.insert(mp[who]);
    }
    return 0;
}
