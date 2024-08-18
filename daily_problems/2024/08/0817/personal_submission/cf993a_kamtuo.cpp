/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-18 20:11 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<std::pair<int, int>> s1(4, {0, 0}), s2(4, {0, 0});
    for (int i = 0; i < 4; i ++) cin >> s1[i].first >> s1[i].second;
    for (int i = 0; i < 4; i ++) cin >> s2[i].first >> s2[i].second;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int b1 = s2[0].second + s2[0].first, b2 = s2[2].second + s2[2].first, b3 = s2[1].second - s2[1].first, b4 = s2[0].second - s2[0].first;
    int left = s1[0].first, right = s1[2].first, up = s1[1].second, down = s1[0].second;
    auto check_in_s2 = [&] (int x, int y)  -> bool {
        return (-x + b1 <= y && y <= -x + b2) && (x + b3 <= y && y <= x + b4);
    };
    auto check_in_s1 = [&] (int x, int y)  -> bool {
        return x >= left && x <= right && y >= down && y <= up;
    };
    bool ok = false;
    // debug("b1:", b1, "b2:", b2, "b3:", b3, "b4:", b4);
    for (int i = 0; i < 4; i ++) {
        if (check_in_s2(s1[i].first, s1[i].second)) {
            ok = true;
        }
        if (check_in_s1(s2[i].first, s2[i].second)) {
            ok = true;
        }
    }
    if (s2[0].first <= left && s2[3].first >= right && s2[1].second <= down && s2[2].second >= up && check_in_s1(s1[0].first, b1 - s1[0].first) && check_in_s2(s1[0].first, b1 - s1[0].first)) ok = true;
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

#endif

/*

*/
