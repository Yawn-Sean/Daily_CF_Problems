void solve(){
    auto fout = [&]()->void{
        cout << -1 << "\n";
    };

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    int m = (n+1)/2;

    int need1 = 0, need2 = 0, all = 0;
    for (int i = 0; i < k; ++ i){
        int u;
        cin >> u;
        (u < y ? need1+=1 : need2+=1);
        all += u;
    }

    if (need1 >= m) return fout();

    int c1 = n - max(m, need2) - need1;
    int c2 = max(m-need2, 0);

    if (all+c1+y*c2 > x) return fout();
    assert(c1+c2 == n-k);

    vector <int> ans;
    while (c1--) ans.push_back(1);
    while (c2--) ans.push_back(y);

    print(ans);
}
