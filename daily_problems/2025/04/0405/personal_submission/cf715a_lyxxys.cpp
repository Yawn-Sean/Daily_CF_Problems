void solve(){
    int n;
    cin >> n;

    cout << 2 << "\n";
    for (i64 i = 2; i <= n; ++ i){
        cout << i*(i+1)*(i+1) - (i-1) << "\n";
    }
}
