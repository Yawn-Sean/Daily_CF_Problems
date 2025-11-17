#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(const vector<int>& S, const vector<int>& T){
    cout << "? " << S.size();
    for (int x : S) cout << ' ' << x + 1;
    cout << ' ' << T.size();
    for (int x : T) cout << ' ' << x + 1;
    cout << '\n' << flush;
    int res; if (!(cin >> res)) exit(0);
    return res;
}

void answer(int x){
    cout << "! " << x << '\n' << flush;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; if (!(cin >> t)) return 0;
    while (t--){
        int n; cin >> n;
        vector<int> all(n);
        for (int i = 0; i < n; ++i) all[i] = i;

        int total_edge = query(all, all);
        vector<ll> degs(n, 0);

        if (n >= 2){
            for (int i = 0; i < n - 1; ++i){
                vector<int> tmp; tmp.reserve(n - 1);
                for (int j = 0; j < n; ++j) if (j != i) tmp.push_back(j);
                int v = query(tmp, tmp);
                degs[i] = (ll)total_edge - v;
            }
            ll sum = 0;
            for (int i = 0; i < n - 1; ++i) sum += degs[i];
            degs[n - 1] = (ll)total_edge * 2 - sum;
        } else { // n == 1
            degs[0] = (ll)total_edge * 2;
        }

        int idx = -1;
        for (int i = 0; i < n; ++i) if (degs[i] == 1){ idx = i + 1; break; }
        if (idx == -1) answer(-1);
        else answer(idx);
    }
    return 0;
}
