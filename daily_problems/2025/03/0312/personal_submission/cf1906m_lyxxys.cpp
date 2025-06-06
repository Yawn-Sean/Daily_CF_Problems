void solve(){
    int n;
    cin >> n;
    int ma = -inf_int;
    i64 all = 0;
    for (int i = 0,x; i < n; ++ i){
        cin >> x;
        all += x;
        fmax(ma, x);
    }

    cout << min(all/3, all-ma) << "\n";
}
