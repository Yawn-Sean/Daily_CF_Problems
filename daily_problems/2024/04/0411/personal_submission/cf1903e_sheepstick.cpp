#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    int stx, sty; cin >> stx >> sty;
    int st = (stx & 1) ^ (sty & 1);

    vector<vector<int>> parity(2);
    vector<int> done(n + 1, 0);
    for (int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        parity[(x ^ y) & 1].push_back(i);
    }

    int cnt = 0;
    if ((int)parity[st].size() >= (int)parity[st ^ 1].size()){ 
        cout << "First" << endl;
        for (int i = st ^ 1, j = 0; j < 2; i = 1 ^ i, j++){
            for (auto x : parity[i]) if (!done[x]){
                cout << x << endl;
                done[x] = 1;
                if (++cnt == n) break;
                cin >> x;
                if (x == -1) return;
                done[x] = 1;
                if (++cnt == n) break;
            }
        } 
    }
    else {
        cout << "Second" << endl;
        int x;
        cin >> x;
        done[x] = 1;
        ++cnt;
        for (int i = st, j = 0; j < 2; i = 1 ^ i, j++){
            for (auto x : parity[i]) if (!done[x]){
                cout << x << endl;
                done[x] = 1;
                if (++cnt == n) break;
                cin >> x;
                if (x == -1) return;
                done[x] = 1;
                if (++cnt == n) break;
            }
        } 
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}