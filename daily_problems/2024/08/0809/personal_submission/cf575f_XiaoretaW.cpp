int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);    
    
    int n, x; cin >> n >> x;
    int curL = x, curR = x;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (curR < l) {
            ans += l - curR;
            curL = curR;
            curR = l;
        } else if (curL > r) {
            ans += curL - r;
            curR = curL;
            curL = r;
        } else {
            setmax(curL, l);
            setmin(curR, r);
        }
    }
    cout << ans << '\n';

    return 0;
}
