void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> A(n), B(m);
    int ma1 = 0, ma2 = 0;
    i64 tot1 = 0, tot2 = 0;
    for (auto &x : A){
        cin >> x;
        tot1 += x;
        fmax(ma1, x);
    }
    for (auto &x : B){
        cin >> x;
        tot2 += x;
        fmax(ma2, x);
    }
    
    i64 ans1 = 0, ans2 = 0;
    for (auto &x : A){
        ans1 += min(1ll*x, tot2);
    }
    ans1 += max(tot2-ma1, 0ll);

    for (auto &x : B){
        ans2 += min(1ll*x, tot1);
    }
    ans2 += max(tot1-ma2, 0ll);

    cout << min(ans1, ans2) << "\n";
}
