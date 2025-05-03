/*
 https://codeforces.com/problemset/problem/599/C
 C. Day at the Beach
 Solver: nhant
 2025-05-03 15:59:58
 https://codeforces.com/problemset/submission/599/318193368, O(nlog(n)) 77 ms, O(n) 100 KB
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> h(n), ord(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        ord[i] = i;
    }
    // comparator with only h[i] < h[j] is NOT enough since we need the equal entries
    // to maintain its original ordering as well.
    sort(ord.begin(), ord.end(), [&](int i, int j) { return h[i] < h[j] || (h[i] == h[j] && i < j); });
    int res = 0, last = -1;
    for (int i = 0; i < n; i++) {
        int l = min(i, ord[i]), r = max(i, ord[i]);
        if (last < l) {
            res++;
        }
        last = max(last, r);
    }
    cout << res << '\n';
}
