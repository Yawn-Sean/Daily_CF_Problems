   int n;
    cin >> n;
    map<int,int> mp;
    int sums = 0;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        string s;
        cin >> s;
        for (auto j: s) {
            ans ^= (1 << (j - 'a'));
        }
        for (int j = 0; j < 26; j++) {
            sums += mp[ans ^ (1 << j)];
        }
        sums += mp[ans];
        debug(sums);
        mp[ans]++;
    }
    cout << sums << endl;
