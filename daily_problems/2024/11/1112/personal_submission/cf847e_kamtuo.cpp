/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-12 15:42 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<int> pack, star;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '*') star.push_back(i);
        else if (s[i] == 'P') pack.push_back(i);
    }
    if (star.size() == 0) {
        cout << 0 << "\n";
        return 0;
    } 
    int l = 0, r = 2 * n;
    auto check = [&] (int mid) -> bool {
        int now = -1;
        int pos = 0;
        for (int i = 0; i < star.size(); i ++) {
            if (star[i] <= now) continue;
            while (pos < pack.size() && abs(star[i] - pack[pos]) > mid) pos ++;
            if (pos == pack.size()) return false;
            if (pack[pos] < star[i]) {
                now = max(now, pack[pos] + mid);
                now = max(pack[pos], now);
                pos ++;
            } else {
                now = max(mid - abs(star[i] - pack[pos]) * 2 + pack[pos], now);
                now = max((mid - abs(star[i] - pack[pos])) / 2 + pack[pos], now); 
                now = max(pack[pos], now);
                pos ++;
            }
        } 
        return true;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}

#endif

/*

*/
