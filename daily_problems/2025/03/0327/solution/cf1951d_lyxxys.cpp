void solve(){
    i64 n, k;
    cin >> n >> k;

    if (n == k){
        cout << "YES\n";
        cout << "1\n1\n";
    } else if (n > 2*(k-1)){
        cout << "YES\n";
        cout << 2 << "\n";
        cout << n-(k-1) << " " << 1 << "\n";
    } else {
        cout << "NO\n";
    }
}
