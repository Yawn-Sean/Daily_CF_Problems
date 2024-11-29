int n;

void solve() {
    cin >> n;
    // 不要让两个1碰到一起 导致消失
    vector<int> res(n + 1);
    vector<int> seen(n + 1);
    
    int r = n;
    
    while (r > 0) {
        int len = std::__lg(r) + 1;
        int s = (1 << len) - 1;
        
        int start = s ^ r;
        while (r >= 0 and start <= n and !seen[start]) {
            res[r] = start;
            seen[start] = 1;
            r --;
            start ++;
        }
    }
    
    cout << (ll)n * (n + 1) << endl;
    cout << res << endl;
}