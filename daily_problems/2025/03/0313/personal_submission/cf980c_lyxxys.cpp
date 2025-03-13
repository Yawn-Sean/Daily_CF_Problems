void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> own(256, -1), lazy(256);
    vector <int> A(n), ans;
    for (auto &x : A){
        cin >> x;
    }

    for (auto &x : A){
        if (own[x] != -1){
            ans.push_back(own[x]);
        } else {
            int reco = 256;
            for (int i = x; i >= x-k+1; -- i){
                if (i < 0 || own[i] != -1){
                   reco = i;
                   break; 
                }
            }
            
            if (reco == 256){
                int u = x-k+1;
                for (int j = x; j >= x-k+1; -- j){
                    own[j] = u;
                }
                ans.push_back(u);
                lazy[x] = k;
            } else {
                int used = reco < 0 ? 0 : lazy[reco];
                int u;
                if (used+x-reco <= k){
                    u = reco < 0 ? 0 : own[reco];
                    lazy[x] = used+x-reco;
                } else {
                    u = reco+1;
                    lazy[x] = x-reco;
                }
                for (int j = reco+1; j <= x; ++ j){
                    own[j] = u;
                }
                ans.push_back(u);
            }
        }
    }

    print(ans);
}
