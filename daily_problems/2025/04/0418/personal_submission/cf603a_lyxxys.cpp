void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 1; i < n; ++ i){
        res += s[i] != s[i-1];
    }
    cout << min(res+3, n) << "\n";
}
