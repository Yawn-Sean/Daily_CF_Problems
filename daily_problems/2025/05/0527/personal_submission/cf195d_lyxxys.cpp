void solve(){
    map <fint,i64> M;
    
    int n;
    cin >> n;
    for (int i = 0, ki, bi; i < n; ++ i){
        cin >> ki >> bi;
        if (ki == 0) continue;
        M[fint(-bi, ki)] = 1;
    }

    cout << M.size() << "\n";
}
