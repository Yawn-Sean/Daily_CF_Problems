const int N = 3e5 + 5;

int n, k, vis[26];
string s;
ll ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    k = set<char>(s.begin(), s.end()).size();
    cout << k << endl;
    n = s.size();
    s = " " + s + " ";
    rep(d, 1, k) {
        int l = 1, r = 1, now = 0;
        while(l <= n) {
            while(r <= n && now + (!vis[s[r] - 'a']) <= d) {
                now += !vis[s[r] - 'a'];
                ++vis[s[r] - 'a'];
                ++r;
            }
            ans[d] += r - l;
            --vis[s[l] - 'a'];
            now -= !vis[s[l] - 'a'];
            ++l;
        }
    }
    rep(d, 1, k) cout << ans[d] - ans[d - 1] << endl;
    return 0;
}
