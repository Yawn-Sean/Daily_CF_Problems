    
void solve() {
    int k, pos = 1;
    i64 w, m, val = 10, res = 0;
    cin >> w >> m >> k;
    w /= k;
    while (true) {
        i64 dif = max(0ll, val - m);
        if (dif * pos <= w) {
            w -= dif * pos;
            res += dif;
            m += dif;
        } else {
            res += w / pos;
            break;
        }
        val *= 10, pos++; 
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}