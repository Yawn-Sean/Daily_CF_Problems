
    int n,m,a,b,x,y;
    cin >> n >> m >> x >> y >> a >> b;
    int tt = gcd(a, b);
    a /= tt, b /= tt;
    int p = a * min(n / a, m / b);
    int q = b * min(n / a, m / b);
    int ansx = min(max(x - (p + 1) / 2, 0LL), n - p);
    int ansy = min(max(y - (q + 1) / 2, 0LL), m - q);
    printf("%lld %lld %lld %lld\n",ansx, ansy, ansx + p, ansy + q);

// ٩ (◕‿◕�?) ۶
