/*
单独考虑每个面是否可能被看到
*/

int x, y, z, x1, y1, z1, a[10];

void meibao() {
    cin >> x >> y >> z >> x1 >> y1 >> z1;
    for (int i = 1; i <= 6; i++) {
        cin >> a[i];
    }
    int res = 0;
    if (y < 0) {
        res += a[1];
    }
    if (y > y1) {
        res += a[2];
    }
    if (z < 0) {
        res += a[3];
    }
    if (z > z1) {
        res += a[4];
    }
    if (x < 0) {
        res += a[5];
    }
    if (x > x1) {
        res += a[6];
    }
    cout << res << "\n";
}
