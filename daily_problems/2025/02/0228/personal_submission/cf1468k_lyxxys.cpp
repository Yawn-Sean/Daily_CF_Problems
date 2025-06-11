void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector <int> xs(n), ys(n);
    for (int i = 0; i < n; ++ i){
        if (s[i] == 'R') xs[i] = 1;
        else if (s[i] == 'L') xs[i] = -1;
        else if (s[i] == 'U') ys[i] = 1;
        else ys[i] = -1;
    }
    auto chk = [&](int bs, int by)->bool{
        int x = 0, y = 0;
        for (int i = 0; i < n; ++ i){
            if (x+xs[i]==bs && y+ys[i]==by) continue;
            x += xs[i], y += ys[i];
        }
        return x==0&&y==0;
    };
    int ansx = 0, ansy = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++ i){
        x += xs[i], y += ys[i];
        if (chk(x, y)){
            ansx = x, ansy = y;
            break;
        }
    }
    cout << ansx << " " << ansy << "\n";
}
