void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n);
    for (int i = 0; i < n; ++ i){
        char ch;
        cin >> ch;
        if (ch == '(') A[i] = 1;
        else A[i] = -1;
    }

    vector<array<int,2>> ans;
    auto swaps = [&](int l, int r)->void{
        if (l > r) swap(l, r);
        swap(A[l], A[r]);
        ans.push_back({l+1, r+1});
        if (r-l > 2){
            ans.push_back({l+2, r});
        }
    };

    vector <int> tars(n);
    int big = n - (2*k-2);

    for (int i = 0; i < big/2; ++ i){
        tars[i] = 1;
    }
    for (int i = big/2; i < big; ++ i){
        tars[i] = -1;
    }
    for (int i = big, flg = 1; i < n; ++ i){
        tars[i] = flg;
        flg = -flg;
    }

    vector <int> curs1, curs2;
    for (int i = 0; i < n; ++ i){
        if (tars[i] == A[i]) continue;

        if (A[i] == 1) curs1.push_back(i);
        else curs2.push_back(i);
    }

    assert(curs1.size() == curs2.size());

    for (int i = 0; i < curs1.size(); ++ i){
        swaps(curs1[i], curs2[i]);
    }

    cout << ans.size() << "\n";
    for (auto &[u, v] : ans){
        cout << u << " " << v << "\n";
    }
}
