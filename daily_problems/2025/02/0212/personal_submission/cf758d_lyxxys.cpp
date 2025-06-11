void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector <int> nums;
    for (auto &ch : s){
        nums.push_back(ch-'0');
    }

    int m = nums.size();
    i64 res = 0, ba = 1;

    int i = m-1;
    while (i >= 0){
        i64 cur = nums[i], b = 10;
        while (i-1 >= 0 && cur < n){
            if (nums[i-1] == 0){
                f64 bj = b, j = i-1;
                while (j-1 >= 0){
                    j -= 1, bj *= 10;
                    if (nums[j] || cur+bj >= n) break;
                }
                if (!nums[j] || cur+bj >= n || cur+nums[j]*bj >= n) break;

                cur += nums[j]*bj;
                i = j, b = bj*10;
            } else {
                if (cur + nums[i-1]*b < n){
                    i -= 1;
                    cur += nums[i]*b;
                    b *= 10;
                } else break;
            }
        }
        res += cur * ba;
        i -= 1;
        if (i >= 0) ba *= n;
    }

    cout << res << "\n";
}
