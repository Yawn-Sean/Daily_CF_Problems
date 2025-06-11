#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pis> vec;
    for (int i = 1; i <= n; i++) {
        string x;
        int y; cin >> x >> y;
        vec.push_back({y, x});
    }
    sort(vec.begin(), vec.end());

    vector<int> ord;
    for (int i = 0; i < n; i++) {
        if (vec[i].first > i) { printf("-1\n"); return 0; }
        vector<int> nxt;
        for (int j = 0; j < vec[i].first; j++) nxt.push_back(ord[j]);
        nxt.push_back(i);
        for (int j = vec[i].first; j < i; j++) nxt.push_back(ord[j]);
        ord = nxt;
    }

    for (int i = 0; i < n; i++) vec[ord[i]].first = (int) 1e9 - i;
    for (int i = 0; i < n; i++) cout << vec[i].second << " " << vec[i].first << "\n";
    return 0;
}
