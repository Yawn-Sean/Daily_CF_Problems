int T, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> s;
        int x = 1, y = 1, flg = 0;
        char lst = 0;
        for(char c : s) {
            if(c == 'R') ++x;
            else ++y;
            if(lst && c != lst) flg = 1;
            lst = c;
        }
        if(!flg) cout << n << endl;
        else {
            x = n - x;
            y = n - y;
            int p = 1;
            while(s[p] == s[p - 1]) ++p;
            ll ans = p;
            rep(i, p, s.size() - 1) {
                ++ans;
                if(s[i] == 'R') ans += y;
                else ans += x;
            }
            ans += 1LL * (x + 1) * (y + 1);
            cout << ans << endl;
        }
    }
    return 0;
}
