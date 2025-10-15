void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s += s[0];

    i64 res = 0;
    i64 f0 = 1, f1 = 0;
    for (int i = 0; i < n; ++ i){
        i64 u0 = f0, u1 = f1;
        if (s[i] == 'A'){
            f0 = u0 + u1;
            f1 = s[i+1] == 'A' ? 0 : u1;
        } else {
            f0 = u1;
            f1 = s[i+1] == 'A' ? u0 : u1;
        }
    }
    res += f0;

    f0 = 0, f1 = 1;
    for (int i = 0; i < n; ++ i){
        i64 u0 = f0, u1 = f1;
        if (s[i] == 'A'){
            f0 = u0 + u1;
            f1 = s[i+1] == 'A' ? 0 : u1;
        } else {
            f0 = u1;
            f1 = s[i+1] == 'A' ? u0 : u1;
        }
    }
    res += f1;

    cout << res << "\n";
}
