void solve(){
    vector <i64> cnts(20), fact(21, 1);
    for (int i = 1; i < 21; ++ i){
        fact[i] = fact[i-1] * i;
    }

    int t;
    cin >> t;
    while (t--){
        fill(cnts.begin(), cnts.end(), 0);

        i64 k;
        cin >> k;
        i64 u = k, dv = 2;
        vector <int> A;
        while (u){
            A.push_back(u%dv), u /= dv;
            dv += 1;
        }
        for (auto &x : A){
            cnts[x] += 1;
        }
        for (int i = 1; i < 20; ++ i){
            cnts[i] += cnts[i-1];
        }

        int l = A.size();
        i64 ans1 = 1, ans2 = 0;
        for (int i = 0; i < l; ++ i){
            int bound = i+1;
            ans1 *= cnts[bound]-i;
        }
        for (int i = 0; i < 20; ++ i){
            int v = !i ? cnts[i] : cnts[i]-cnts[i-1];
            ans1 /= fact[v];
        }

        if (cnts[0]){
            for (int i = 0; i < 20; ++ i){
                cnts[i] -= 1;
            }
            ans2 = 1;
            for (int i = 0; i < l-1; ++ i){
               int bound = i+1;
               ans2 *= cnts[bound]-i; 
            }
            for (int i = 0; i < 20; ++ i){
                int v = !i ? cnts[i] : cnts[i]-cnts[i-1];
                ans2 /= fact[v];
            }
        }

        cout << ans1-ans2-1 << "\n";
    }
}
