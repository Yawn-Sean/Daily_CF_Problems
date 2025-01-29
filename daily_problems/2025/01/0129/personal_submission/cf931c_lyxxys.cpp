void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    int ma = -inf_int, mi = inf_int;
    for (auto &x : A){
        cin >> x;
        fmax(ma, x);
        fmin(mi, x);
    }

    if (ma-mi < 2){
        cout << n << "\n";
        print(A);
        return;
    }

    int c1 = 0, c2 = 0, c3 = 0;
    for (auto &x : A){
        if (x == mi) c1 += 1;
        else if (x == mi+1) c2 += 1;
        else c3 += 1;
    }

    array<int,3> ans;
    int res = -inf_int;
    int d1 = c1, d2 = c2, d3 = c3;
    auto ch_min = [&]()->void{
        int cur = max(d1-c1, 0) + max(d2-c2, 0) + max(d3-c3, 0);
        if (cur > res){
            res = cur;
            ans = {d1, d2, d3};
        }
    };

    while (d2 > 1){
        d2 -= 2;
        d1 += 1, d3 += 1;
    }
    ch_min();
    while (d1 && d3){
        d1 -= 1, d3 -= 1;
        d2 += 2;
        ch_min();
    }

    cout << n-res << "\n";
    bool jg = 0;
    for (int i = 0; i < ans[0]; ++ i){
        if (jg) cout << " ";
        cout << mi;
        jg = 1;
    }
    for (int i = 0; i < ans[1]; ++ i){
        if (jg) cout << " ";
        cout << mi+1;
        jg = 1;
    }
    for (int i = 0; i < ans[2]; ++ i){
        if (jg) cout << " ";
        cout << mi+2;
        jg = 1;
    }
    cout << "\n";
}
