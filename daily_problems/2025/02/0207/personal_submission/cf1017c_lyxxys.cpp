void solve(){
    int n;
    cin >> n;
    int ma = inf_int, rare, L, cnt;  // L 是划分的长度，i 枚举个数 
    for (int i = 1; i <= n; ++ i){
        int x = i + n/i;
        x += ((n%i)+i-1) / i;
        if (ma > x){
            ma = x;
            L = n/i, cnt = i;
            rare = n%i;
        }
    }
    vector <int> ans;
    L += rare/cnt;
    rare %= cnt;
    // cout << L << " " << cnt << " " << rare << "\n";

    for (int i = n-L+1-(rare>0); i <= n; ++ i){
        ans.push_back(i);
    }
    int l = n-L+1-(rare>0)-L, r = n-L+1-(rare>0);
    if (rare > 0) rare -= 1;

    while (l >= 1){
        l -= rare > 0;
        for (int i = l; i < r; ++ i){
            ans.push_back(i);
        }
        r -= rare > 0;
        if (rare) rare -= 1;
        l -= L, r -= L;
    }

    assert(ans.size() == n);

    print(ans);
}

