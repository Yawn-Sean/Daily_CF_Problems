/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-15 20:00 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector s(n, 0);
    vector ans(2, 0);
    auto print = [&] (vector<int> &s) -> int {
        cout << "? ";
        for (int i = 0; i < s.size(); i ++) {
            cout << s[i];
        }
        int now;
        cout << std::endl;
        cin >> now;
        return now;
    };
    int k0 = print(s);
    s[0] = 1;
    int k1 = print(s);
    int find;
    if (k0 > k1) {
        ans[1] = 1;
        find = 0;
    } else {
        ans[0] = 1; 
        find = 1;
    }
    for (int i = 0; i < n; i ++) s[i] = find;
    int base = print(s);
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        for (int i = 0; i < n; i ++) s[i] = find;
        for (int i = 0; i < mid; i ++) s[i] = (find ^ 1);
        if (base - print(s) != mid) r = mid;
        else l = mid + 1;
    }
    ans[find] = r;
    cout << "! " << ans[0] << ' ' << ans[1] << std::endl;
    return 0;
}

#endif

/*

*/
