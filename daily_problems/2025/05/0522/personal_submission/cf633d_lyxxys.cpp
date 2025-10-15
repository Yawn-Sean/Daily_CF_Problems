void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    map <int,int> mps;
    for (auto &x : A){
        cin >> x;
        mps[x] += 1;
    }

    int res = mps[0];
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i == j || (A[i]==0 && A[j]==0)) continue;
            vector <int> curs = {A[i], A[j]};
            mps[A[i]] -= 1, mps[A[j]] -= 1;

            while (true){
                int x = curs.end()[-1] + curs.end()[-2];
                if (!mps[x]) break;
                curs.push_back(x);
                mps[x] -= 1;
            }

            for (auto &x : curs){
                mps[x] += 1;
            }
            res = max(res, (int)curs.size());
        }
    }

    cout << res << "\n";
}
