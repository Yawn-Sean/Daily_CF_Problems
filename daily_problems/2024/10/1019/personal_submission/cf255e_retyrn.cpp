const int N = 1e6;
int n;

void solve() {
    vector<int> sg(N, 0);
    int l = 0, r = 0;
    map<int, int> mp;
    
    for (int i = 1; i < N; i ++) {
        while (r * r <= i and r < i) {
            mp[sg[r]] ++;
            r ++;
        }
        while (l * l * l * l < i) {
            mp[sg[l]] --;
            l ++;
        }
        while (mp[sg[i]]) sg[i] ++;
    }
    
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    sort(all(a));
    
    mp.clear();
    l = 0, r = 0;
    
    int res = 0;
    for (auto val : a) {
        while ((ll)r * r <= val and r < val) {
            mp[sg[r]] ++;
            r ++;
        }
        while ((ll)l * l * l * l < val) {
            mp[sg[l]] --;
            l ++;
        }
        int x = 0;
        while (mp[x]) x += 1;
        res ^= x;
    }
    
    cout << (res ? "Furlo" : "Rublo") << endl;
}