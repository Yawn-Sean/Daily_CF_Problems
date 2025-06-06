void solve(){
    int n;
    cin >> n;

    vector <int> p(n);
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        x -= 1;
        p[x] = i;
    }

    int res = 0;
    for (int i = 0, j = -1; i < n; ++ i){
        while (i > j || j+1 < n && p[j+1] > p[j]){
            j += 1;
        }
        fmax(res, j-i+1);
    }

    cout << n - res << "\n";
}
