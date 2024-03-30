int n;

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        int st = 0;
        for (auto c : s) {
            int u = c - 'a';
            st ^= (1 << u);
        }
        mp[st] += 1; 
    }
    
    ll res = 0;
    for (auto [x, y] : mp) {
        res += (ll)(y - 1) * y;
        for (int i = 0; i < 26; i ++) {
            auto t = (1 << i);
            if (mp.count(x ^ t)) res += (ll)y * mp[x ^ t];
        }
    }
    cout << (res >> 1) << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}