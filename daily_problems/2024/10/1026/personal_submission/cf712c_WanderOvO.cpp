int x, y;

void meibao() {
    cin >> x >> y;
    int res = 0;
    int a[4] = {0, y, y, y};
    while (true) {
        sort(a + 1, a + 4);
        if (a[1] == x && a[3] == x) {
            break;
        }
        a[1] = min(x, a[3] + a[2] - 1);
        res++;
    }
    cout << res << "\n";
}   
