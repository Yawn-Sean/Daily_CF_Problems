int main(void){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    auto get = [&](ll x){
        x = ((x % n) + n) % n;
        return (x ? x : n);
    };
    ll cnt1 = 0, cnt2 = 0;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            cnt1 += x, cnt2 += x;
        }
        else {
            if(!(cnt1 % 2)) {
                cnt1++, cnt2--;
            }
            else {
                cnt2++, cnt1--;
            }
        }
    }
    //cout << cnt1 << ' ' << cnt2 << "\n";
    for(int i = 1; i <= n; i += 2){
        ans[i] = get(ans[i] + cnt1);
        ans[i + 1] = get(ans[i + 1] + cnt2);
    }
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i++){
        res[ans[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << ' ';
    }
}
