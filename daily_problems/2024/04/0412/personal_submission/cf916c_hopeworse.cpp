//link  : https://codeforces.com/contest/916/submission/256185665
void solve() {
    int n, m;
    cin >> n >> m;
    //999983
    vector<set<int>> mp(n + 1);
    int as = 1000000000;
//    cout << 999983 << " " << (m - n + 1) * 1e9 + 999983 << endl;
    printf("999983 999983\n" );
    for (int i = 1; i < n - 1; i++) {
        cout << i << " " << i + 1 << " " << 1 << endl;
    }
    cout << n - 1 << " " << n << " " << 999983 - n + 2 << endl;
    m -= n - 1;
    int i = 1;
    int j = i + 1;
    while (m) {
        j++;
        if (j == n + 1) {
            i++;
            j = i + 2;
        }
        printf("%lld %lld %lld\n", i, j, as);
        m--;
    }
 
 
}
