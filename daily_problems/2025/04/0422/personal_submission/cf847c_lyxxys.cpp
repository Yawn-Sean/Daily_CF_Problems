void solve(){
    i64 n, k;
    cin >> n >> k;
    
    if (k > n*(n-1)/2){
        cout << "Impossible\n";
    } else {
        string res;
        
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (k >= (n-1-i)){
                res += "(";
                k -= n-1-i;
                cnt += 1;
            } else {
                res += "()";
            }
        }
        while (cnt--) res += ")";

        cout << res << "\n";
    }
}
