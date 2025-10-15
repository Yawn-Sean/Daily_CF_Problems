
void solve(){
    int n;
    cin >> n;
    string s[n];
    vector<int> v(10, 0), l(10, INF), r(10, -1), u(10, INF), d(10, -1);
    for(int i = 0; i < n; i ++)
        cin >> s[i];
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j++) {
        int x = s[i][j] - '0';
        u[x] = min(u[x], i); 
        d[x] = max(d[x], i);
        l[x] = min(l[x], j); 
        r[x] = max(r[x], j);
      }

    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j ++) {
        int x = s[i][j] - '0';
        v[x] = max(v[x], max(d[x] - i, i - u[x]) * max(n - j - 1, j));
        v[x] = max(v[x], max(r[x] - j, j - l[x]) * max(n - i - 1, i));
      }
    
    for(auto c : v)
        cout << c << ' ';
}
// ٩ (◕‿◕�?) ۶
