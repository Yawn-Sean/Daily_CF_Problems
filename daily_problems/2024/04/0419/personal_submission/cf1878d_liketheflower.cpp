// https://codeforces.com/contest/1878/submission/257247170
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> l(k), r(k), lr_sum(k, 0);
    for (int i = 0; i < k; i++){
        cin >> l[i];
        l[i] --;
        lr_sum[i] += l[i];
    }
    for (int i = 0; i < k; i++){
        cin >> r[i];
        r[i] --;
        lr_sum[i] += r[i];
    }
    
    int q; cin >> q;
    vector<int> xs(q);
    for (int i = 0; i < q; i++){
        cin >> xs[i];
        xs[i] --;
    }
    vector<int> group(n, -1);
    for (int i = 0; i < k; ++i){
        for (int val = l[i]; val <= r[i]; ++val){
            group[val] = i;
        }
    }
    vector<int> diff(n + 1, 0);
    int low = 0, high = 0;
    for (auto x: xs){
        int this_sum = lr_sum[group[x]];
        low = x;
        high = this_sum - x;
        if (low > high){
            swap(low, high);
        }
        diff[low] ^= 1;
        diff[high + 1] ^= 1;
    }
    vector<int> changed(n, 0);
    int curr_status = 0;
    for (int i = 0; i < n;++i){
        curr_status ^= diff[i];
        changed[i] = curr_status;
    }
    string ret = s;
    for (int i = 0; i < n; ++i){
        if (changed[i]){
            int j = lr_sum[group[i]] - i;
            ret[i] = s[j];
        }
    }
    cout << ret << endl;
}
