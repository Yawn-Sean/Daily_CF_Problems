#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int m;
    cin >> m;
    int lim = 1e5;
    
    vector<int> prefix, notes;
    vector<i64> lens = {0};

    for (int i = 0; i < m; i++) {
        int tp;
        cin >> tp;
        if(tp==1) {
            int x;;
            cin >> x;
            if (prefix.size() < lim) {
                prefix.push_back(x);
            }
            notes.push_back(-x);
            lens.emplace_back(lens.back() + 1);
        } else {
            int l, c;
            cin >> l >> c;
            for (int i = 0; i < l * c && prefix.size() < lim; i++) {
                prefix.push_back(prefix[i % l]);
            }
            notes.push_back(l);
            lens.emplace_back(lens.back() + l * c);
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        i64 pos;
        cin >> pos;
        int p = lower_bound(lens.begin(), lens.end(), pos) - lens.begin() - 1;
        cout << (notes[p] < 0 ? -notes[p] : prefix[(pos - 1 - lens[p]) % notes[p]]) << ' ';
    }
    return 0;
}
