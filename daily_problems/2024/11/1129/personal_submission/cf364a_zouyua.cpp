int main()
{
    ll sum;
    string s; cin >> sum >> s;
    map<ll, ll> mp;
    int n = s.size();
    for(int i = 0; i < n; i ++) {
        ll val = 0;
        for(int j = i; j < n; j ++) {
            val += (s[j] - '0');
            mp[val] ++;
        }
    }
    if(sum == 0) {
        ll k = n * (n + 1) / 2;
        cout << k * k - (k - mp[0]) * (k - mp[0]) << endl;
        return 0;
    }
    ll res = 0;
    for(auto &[u, v] : mp) {
        //cout << u << ' ' << v << endl;  
        if(u == 0) continue;
        if(sum % u == 0 && mp.count(sum / u)) {
            res += v * mp[sum / u];
        }
    }
    cout << res << endl;
    return 0;
}
