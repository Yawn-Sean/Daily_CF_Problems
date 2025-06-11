int main()
{
    string s; cin >> s;
    for(auto & x: s) x = tolower(x);
    int n = s.size();
    s = " " + s;
    vector<int> pre(n + 10), lsh;
    //cout << s << endl;
    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1];
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u') pre[i] --;
        else pre[i] += 2;
        lsh.pb(pre[i]);
    }
    lsh.pb(0);
    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
    auto get = [&](int x) {
        return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
    };
    BIT bit(4e6+10);
    bit.update(get(0), 0);
    int cnt = 0, len = 0;
    for(int i = 1; i <= n; i ++) {
        int pos = bit.query(get(pre[i]));
        //cout << i << ' ' << pos << endl;
        if(i - pos > len) {
            len = i - pos;
            cnt = 1;
        } else if(i - pos == len) cnt ++;
        bit.update(get(pre[i]), i);
    }
    if(len == 0) cout << "No solution" << endl;
    else cout << len << ' ' << cnt << endl;
    return 0;
}
