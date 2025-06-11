void solve(){
    i64 w, m, k;
    cin >> w >> m >> k;
    auto count = [&](i64 x)->int{
        int res = 0;
        while (x){
            x /= 10;
            res += 1;
        }
        return res;
    };
    vector <i64> p10(19, 1);
    for (int i = 1; i < 19; ++ i){
        p10[i] = p10[i-1] * 10;
    }
 
    i64 cnt = count(m), cur = 0, i, res = 0;
    for (i = cnt; true; ++ i){
        __int128_t iw = i==cnt ? p10[i]-m : p10[i]-p10[i-1];
        iw *= (i * k);
        if (cur+iw > w) break;
        cur += iw;
 
        res += i==cnt ? p10[i]-m : p10[i]-p10[i-1];
    }
 
    res += (w - cur) / (i*k);
 
    cout << res << "\n";
}
