/*
sum((u[i] - v[i]) / (v[i] * u[i])) = sum(1 / v[i] - 1 / u[i])
裂项
*/

LL n;

bool check(LL n) {
    LL r = sqrt(n);
    for (int i = 2; i <= r; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

PLL sub(PLL f1, PLL f2) {
    PLL res;
    res.y = lcm(f1.y, f2.y);
    res.x = (res.y / f1.y) * f1.x - (res.y / f2.y) * f2.x;
    LL g = gcd(res.x, res.y);
    assert(g != 0);
    res.x /= g;
    res.y /= g;
    return res;
}

PLL add(PLL f1, PLL f2) {
    PLL res;
    res.y = lcm(f1.y, f2.y);
    res.x = (res.y / f1.y) * f1.x + (res.y / f2.y) * f2.x;
    LL g = gcd(res.x, res.y);
    assert(g != 0);
    res.x /= g;
    res.y /= g;
    return res;
}

void meibao() {
    cin >> n;
    if (n == 2) {
        cout << "1/6\n";
        return;
    }
    LL u = -1, v = -1;
    for (int i = n; i > 0; i--) {
        if (check(i)) {
            v = i;
            break;
        }
    }
    for (int i = n + 1; ; i++) {
        if (check(i)) {
            u = i;
            break;
        }
    }
    assert(u != -1 && v != -1);
    PLL f1 = {1, 2}, f2 = {1, v}, f3 = {1, u};
    PLL res = sub(f1, f2);
    // cout << res.x << "/" << res.y << "\n";
    PLL ch = sub(f2, f3);
    // cout << ch.x << "/" << ch.y << "\n";
    ch.x /= (u - v);
    // cout << ch.x << "/" << ch.y << "\n";
    ch.x *= (n - v + 1);
    // cout << ch.x << "/" << ch.y << "\n";
    res = add(res, ch);
    cout << res.x << "/" << res.y << "\n";
}
