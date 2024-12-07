int check_p(int n) {
    if (n == 1) return 0;
    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
 
int p_next(int n) {
    n++;
    while (!check_p(n)) n++;
    return n;
}
int p_prev(int n) {
    while (!check_p(n)) n--;
    return n;
}

void Solve() {
    int n;cin >> n;
    int p2 = p_next(n);
    int p1 = p_prev(n);
    //(p1-2)/2p1+(n-p1+1)*(p2*p1)
    int p = p2 * (p1 - 2) + 2 * n - 2 * p1 + 2;
    int q = 2 * p1 * p2;
    int g = gcd(p, q);
    p /= g, q /= g;
    cout << p << "/" << q << endl;
}
