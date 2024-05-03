const int N = 1e5 + 5;

int n, a[N], cnt[N], ccnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int mx = 0, ans = 0;
    rep(i, 1, n) {
        --ccnt[cnt[a[i]]];
        ++cnt[a[i]];
        ++ccnt[cnt[a[i]]];
        chkmax(mx, cnt[a[i]]);
        if(mx == 1) ans = i;
        else if(mx * ccnt[mx] == i - 1) ans = i;
        else if((mx - 1) * (ccnt[mx - 1] + 1) == i - 1) ans = i;
    }
    cout << ans << endl;
    return 0;
}
