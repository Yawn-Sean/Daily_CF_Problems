    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i];

    int gcds = 0;
    int n1 = 0;

    int mins = inf;
    for (auto i: arr) {
        if (i == 1)n1++;
        gcds = gcd(gcds, i);
    }
    if (n1) {
        cout << n - n1 << endl;
    }
    else if (gcds != 1)cout << -1 << endl;
    else {
        for (int l = 1; l <= n; l++) {
            gcds = 0;
            for (int r = l; r <= n; r++) {
                gcds = gcd(gcds, arr[r]);
                if (gcds == 1) {
                    mins = min(mins, r - l);
                    break;
                }
            }
        }
        cout << mins + n - 1;
    }
