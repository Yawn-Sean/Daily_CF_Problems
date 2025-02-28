int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    // 从后往前贪心
    vector<int> ans(n);
    vector<int> flag(n, 1);
    
    ll sum = a[n - 1];
    ans[n - 1] = 1;
    
    for (int i = n - 2; i >= 0; i --) {
        if (sum >= a[i]) {
            sum -= a[i];
            ans[i] = -1;
        }
        else {
            sum = a[i] - sum;
            ans[i] = 1;
            flag[i+1] = -1;
        }
    }
    
    int f = 1;
    string s;
    for (int i = 0; i < n; i ++) {
        f *= flag[i];
        if (ans[i] == f) {
            s += '+';
        }
        else s += '-';
    }
    cout << s << endl;
}