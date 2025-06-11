/*
submission: https://codeforces.com/contest/570/submission/268870286
*/

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    map<int, int> cnt; 
    for (int i = 0 ; i < n ; i ++ ) {
        int j = i;
        while (j < n && s[j] == '.') j ++;
        if (i != j) {
            cnt[i] = j - 1;
        }
        i = j;
    }
    int ans = 0;
    for (auto u = cnt.begin(); u != cnt.end(); ++ u) {
        ans += u->second - u->first;
    }
    for (int i = 0; i < q; i ++ ) {
        int idx;
        char op;
        cin >> idx >> op;
        idx --;
        if (s[idx] == '.' && op != '.') {
            auto u = prev(cnt.upper_bound(idx));
            cnt.erase(u);
            int l = u->first, r = u->second;
            ans -= r - l;
            if (idx - 1 >= l) {
                cnt[l] = idx - 1;
                ans += idx - 1 - l;
            } 
            if (idx + 1 <= r) {
                cnt[idx + 1] = r;
                ans += r - idx - 1;
            }
        } else if (s[idx] != '.' && op == '.') {
            auto u = cnt.upper_bound(idx);

            auto v = cnt.end();
            if (u != cnt.begin()) v = prev(u);
            
            int new_l = idx, new_r = idx; 
            if (u != cnt.end() && u->first == idx + 1) {
                ans -= u->second - u->first;
                new_r = u->second;
                cnt.erase(u);
            } 
            if (v != cnt.end() && v->second == idx - 1) {
                ans -= v->second - v->first;
                new_l = v->first;
                cnt.erase(v);
            }
            ans += new_r - new_l;
            cnt[new_l] = new_r;
        }
        s[idx] = op;
        cout << ans << "\n";
    }
}
