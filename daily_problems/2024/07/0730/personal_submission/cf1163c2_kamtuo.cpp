/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-30 20:38 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

struct Node {
    int dx, dy;
    int c;
};

#if !KAMTUO_LEETCODE

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }
    std::set<std::array<int, 3>> mni;
    map<std::pair<int, int>, int> mp;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int dx = x[i] - x[j], dy = y[i] - y[j];
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx *= -1;
                dy *= -1;
            }
            std::array<int, 3> now = {dx, dy, dy * x[i] - dx * y[i]};
            if (mni.count(now) == 0) mp[{dx, dy}] ++;
            mni.emplace(now);
        }
    }
    LL ans = 1ll * mni.size() * (1ll * mni.size() - 1) / 2;
    for (auto &[key, val] : mp) {
        ans -= 1ll * val * (val - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

#endif

/*

*/
