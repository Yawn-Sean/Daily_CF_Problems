void solve(){
    vector <int> pw10(8, 1);
    for (int i = 1; i < 8; ++ i){
        pw10[i] = pw10[i-1] * 10;
    }

    int t;
    cin >> t;
    while (t--){
        i64 k1, k2, k3, k;
        cin >> k1 >> k2 >> k3 >> k;
        
        array <i64,3> ans = {-1, -1, -1};
        i64 lst = 0;
        for (int i = pw10[k1-1]; i <= pw10[k1]-1; ++ i){
            int L = -inf_int, R = inf_int;
            fmax(L, pw10[k3-1]-i), fmax(L, pw10[k2-1]);
            fmin(R, pw10[k3]-1-i), fmin(R, pw10[k2]-1);
            i64 cnt = R-L+1;
            if (cnt < 0) cnt = 0;
            if (lst+cnt >= k){
                i64 move = k-lst;
                ans = {i, L+move-1, i+L+move-1};
                break;
            } else {
                lst += cnt;
            }
        }

        if (ans[0] == -1){
            cout << -1 << "\n";
        } else {
            cout << ans[0] << " + " << ans[1] << " = " << ans[2] << "\n";
        }
    }

}
