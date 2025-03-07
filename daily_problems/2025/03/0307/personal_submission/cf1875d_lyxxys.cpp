void solve(){
    int n;
    cin >> n;
    const int bound = n+1;
    vector <int> A(n), cnts(bound+1);
    for (auto &x : A){
        cin >> x;
        if (x <= bound){
            cnts[x] += 1;
        }
    }

    vector <i64> f(bound+1, inf_i64);
    for (int i = 0; i <= bound; ++ i){
        int c = i+1;
        if (!cnts[i]){
            int x = i ? f[i-1] : 0;
            for (int j = i; j <= bound; ++ j){
                f[j] = x;
            }
            break;
        }
        for (int j = 0; j <= i; ++ j){
            i64 k = max(0ll, cnts[j]-1ll);
            if (j == 0) fmin(f[i], k*c);
            else fmin(f[i], f[j-1]+k*c+j);
        }
    }

    cout << f[bound] << "\n";
}
