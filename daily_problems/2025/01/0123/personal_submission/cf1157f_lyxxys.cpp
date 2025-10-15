void solve(){
    const int N = 2e5;
    int n;
    cin >> n;
    vector <int> cnts(N+1);
    for (int i = 0,x; i < n; ++ i){
        cin >> x;
        cnts[x] += 1;
    }
    array<int,2> lr;
    int ma = 0;

    for (int i = 1, j = 0, cur = 0; i <= N; ++ i){
        if (j < i) cur += cnts[++ j];
        while (j+1 <= N && cnts[j+1] && ((i==j&&cnts[j]>0) || (i!=j&&cnts[j]>1))){
            cur += cnts[++ j];
        }
        if (cur > ma){
            ma = cur;
            lr = {i, j};
        }
        cur -= cnts[i];
    }

    vector <int> ans;
    for (int i = lr[0]; i <= lr[1]; ++ i){
        ans.push_back(i);
        cnts[i] -= 1;
    }
    for (int i = lr[1]; i >= lr[0]; -- i){
        while (cnts[i]){
            ans.push_back(i);
            cnts[i] -= 1;
        }
    }

    assert(ans.size() == ma);
    cout << ma << "\n";
    print(ans);
}
