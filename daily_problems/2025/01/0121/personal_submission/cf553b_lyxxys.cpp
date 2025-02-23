void solve(){
    int n;
    i64 k;
    cin >> n >> k;
    vector <i64> fibs = {1, 1};
    while (fibs.size() < 53){
        int j = fibs.size();
        fibs.push_back(fibs[j-1]+fibs[j-2]);
    }
    cout << fibs[50] << "\n";
    k -= 1;
    vector <int> ans;
    while (ans.size() < n){
        int l = ans.size();
        if (k >= fibs[n-1-l]){
            ans.push_back(l+1);
            ans.push_back(l);
            k -= fibs[n-1-l];
        } else {
            ans.push_back(l);
        }
    }

    print(ans);
}
