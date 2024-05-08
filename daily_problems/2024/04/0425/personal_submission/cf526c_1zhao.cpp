void solve() {
    long long c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;
    
    long long res = 0;
    for(long long i=0; i*i<=c; i++) {
        if(c >= i*w1) res = max(res, i*h1 + (c - i*w1) / w2 * h2);
        if(c >= i*w2) res = max(res, i*h2 + (c - i*w2) / w1 * h1);
    }
    cout << res << endl;
}    
