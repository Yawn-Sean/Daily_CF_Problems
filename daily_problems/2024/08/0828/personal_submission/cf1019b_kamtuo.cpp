/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-28 19:23 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    auto query = [&] (int x) -> int {
        cout << "? " << x << std::endl;
        int now;
        cin >> now;
        return now;
    };
    if (n % 4) {
        cout << "! -1" << std::endl;
        return 0;
    } 
    int prel = query(1) - query(1 + n / 2);
    int prer = -prel;
    int l = 1, r = n / 2;
    int now = prel;
    int ans = 1;
    while (prel && prer) {
        int mid = l + r >> 1;
        now = query(mid) - query(mid + n / 2);
        if (now == 0) {
            ans = mid;
            break;
        }
        if ((now > 0) == (prel < 0)) {
            prer = now;
            r = mid - 1;
        } else {
            prel = now;
            l = mid + 1;
        }
    }
    cout << "! " << ans << std::endl;
    return 0;
}

#endif

/*

*/
