int n, vp, vs;
using ai3 = array<int, 3>;
using ld = long double;

const ld eps = 1e-10;
ld dis(ld x1, ld y1, ld z1, ld x2, ld y2, ld z2) {
    auto t = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
    return sqrtl(t);
}

bool check(ld ds, ld dp) {
    // dbg(vp, ds, dp, vs);
    return vp * ds >= dp * vs;
}

void solve() {
    cin >> n;
    vector<ai3> p(n + 2);
    for (int i = 1; i <= n + 1; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> p[i][j];
        }
    }
    cin >> vp >> vs;
    cin >> p[0][0] >> p[0][1] >> p[0][2];
    
    if (p[0] == p[1]) {
        cout << "YES" << endl;
        cout << 0 << endl;
        cout << p[0][0] << ' ' << p[0][1] << ' ' << p[0][2] << endl;
        return;
    }
    
    vector<ld> len(n);
    int st = -1;
    ld sum = 0;
    for (int i = 0; i < n; i ++) {
        len[i] = dis(p[i+1][0], p[i+1][1], p[i+1][2], p[i+2][0], p[i+2][1], p[i+2][2]);
        sum += len[i];
        if (check(sum, dis(p[0][0], p[0][1], p[0][2], p[i+2][0], p[i+2][1], p[i+2][2]))) {
            st = i;
            sum -= len[i];
            break;
        }
    }
    
    if (st < 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (st == n) {
        cout << sum / vs << endl;
        cout << p[n+1][0] << ' ' << p[n+1][1] << ' ' << p[n+1][2] << endl;
        return;
    }
    
    // 第st+1段会发生第一次捕捉 p[st+1]~p[st+2]
    ld time = sum / vs;
    ld l = 0, r = len[st] / vs;
    
    for (int _ = 0; _ < 50; _ ++) {
        auto mid = (l + r) / 2;
        ld dx = p[st+2][0] - p[st+1][0], dy = p[st+2][1] - p[st+1][1], dz = p[st+2][2] - p[st+1][2];
        ld radio = mid * vs / len[st];
        ld x = dx * radio + p[st+1][0], y = dy * radio + p[st+1][1], z = dz * radio + p[st+1][2];
        
        if (dis(p[0][0], p[0][1], p[0][2], x, y, z) / vp < mid + time) {
            r = mid;
        }
        else l = mid;
    }
    
    cout << time + r << endl;
    
    ld dx = p[st+2][0] - p[st+1][0], dy = p[st+2][1] - p[st+1][1], dz = p[st+2][2] - p[st+1][2];
    ld radio = r * vs / len[st];
    ld x = dx * radio + p[st+1][0], y = dy * radio + p[st+1][1], z = dz * radio + p[st+1][2];
    
    cout << x << ' ' << y << ' ' << z << endl;
}