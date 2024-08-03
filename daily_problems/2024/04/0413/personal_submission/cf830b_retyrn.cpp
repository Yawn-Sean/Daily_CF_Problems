int n;
set<int> a[maxn];

void solve() {
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        a[nums[i]].insert(i);
    }
    
    sort(all(nums));
    ll res = n;
    
    int st = 0;
    for (int i = 0; i < n; i ++) {
        int x = nums[i];
        auto it = a[x].lb(st);
        if (it == a[x].end()) {
            res += n - i;
            st = 0;
            it = a[x].begin();
        }
        st = *it;
        a[x].erase(it);
    }
    cout << res << endl;
}