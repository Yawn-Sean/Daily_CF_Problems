/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-19 10:34 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, y, n;
    cin >> x >> y >> n;
    struct Node {
        LL a, b;
        LL v, by;
        bool operator < (const Node &now) const {
            if ((__int128) v * now.by != (__int128) now.v * by) return (__int128) v * now.by < (__int128) now.v * by;
            if (by != now.by) return by < now.by;
            return a < now.a;
        };
    };
    vector<Node> nums;
    for (int i = 1; i <= n; i ++) {
        LL now = 1ll * x * i;
        nums.push_back({now / y, i, now - now / y * y, 1ll * i * y});
        nums.push_back({now / y + 1, i, (now / y + 1) * y - now, 1ll * i * y});
    }
    sort(nums.begin(), nums.end());
    cout << nums[0].a << "/" << nums[0].b << "\n";
    return 0;
}

#endif

/*

*/
