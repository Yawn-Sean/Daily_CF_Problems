void solve(){
    int n, k, a, b, c, d;
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    
    if (k <= n || n == 4)
        return void(cout << -1 << "\n");
    
    vector <int> ans1(n), ans2 = {c, a};
    ans1[0] = a, ans1[1] = c, ans1[n-2] = d, ans1[n-1] = b;
    for (int i = 1, j = 1; i <= n; ++ i){
        if (i == a || i == b || i == c || i == d) continue;
        ans1[++ j] = i;   
    }
    for (int i = 2; i < n-2; ++ i){
        ans2.push_back(ans1[i]);
    }
    ans2.push_back(b);
    ans2.push_back(d);
    
    print(ans1);
    print(ans2);
}

