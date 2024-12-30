/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-02 10:38 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, m;
    cin >> a >> b >> m;
    if (b >= m - 1) {
        cout << 2 << "\n";
    } else {
        int k = 1000000000 % m;
        // debug("k:", k);
        for (int i = 0; i <= min(m, a); i ++) {
            if (((-1ll * i * k % m) % m + m) % m > b) {
                printf("1 %09d", i);
                return 0;
            } 
        }
        cout << 2 << "\n";
    }
    return 0;
}

#endif

/*

*/
