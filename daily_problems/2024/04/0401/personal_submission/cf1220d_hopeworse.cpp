    int n;
    cin >> n;
    vector<int> tong(64), res(n + 1), arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int x = arr[i];
        int len = 0;
        while (!(x & 1)) {
            len++;
            x >>= 1;
        }
        res[i] = len;
        tong[len]++;
    }
    int mx = 0, len = -1;
    for (int i = 0; i < 64; i++) {
        if (tong[i] > mx) {
            mx = tong[i];
            len = i;
        }
    }
    cout << n - mx << endl;
    for (int i = 1; i <= n; i++) {
        if (res[i] != len)cout << arr[i] << " ";
    }
