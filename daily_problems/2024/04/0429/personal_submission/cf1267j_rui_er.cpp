const int N = 2e6 + 5, inf = 0x3f3f3f3f;
int T, n, a[N], cnt[N], vis[N];
vector<int> vec;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n;
        rep(i, 1, n) {
            cin >> a[i];
            ++cnt[a[i]];
            if(!vis[a[i]]) vec.push_back(a[i]);
            vis[a[i]] = 1;
        }
        int lim = inf, ans = inf;
        for(int i : vec) chkmin(lim, cnt[i] + 1);
        rep(i, 1, lim) {
            int now = 0;
            for(int j : vec) {
                if(cnt[j] % i == 0) now += cnt[j] / i;
                else if(cnt[j] / i + cnt[j] % i < i - 1) {
                    now = -1;
                    break;
                }
                else now += cnt[j] / i + 1;
            }
            if(now != -1) chkmin(ans, now);
        }
        cout << ans << endl;
        // clear
        rep(i, 1, n) cnt[a[i]] = vis[a[i]] = 0;
        rep(i, 1, n) a[i] = 0;
        vec.clear();
    }
    return 0;
}
