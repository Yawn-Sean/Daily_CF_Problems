/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-02 16:42 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::function<int (int, int)> gcd = [&] (int a, int b) -> int {
        if (!b) return a;
        return gcd(b, a % b);
    };
    int la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    if (la > lb) {
        std::swap(la, lb);
        std::swap(ra, rb);
        std::swap(ta, tb);
    }
    int g = gcd(ta, tb), d = lb - la;
    d = d % g;
    cout << max(0, max(min(rb - lb + 1, ra - la + 1 - d), min(ra - la + 1, rb - lb + 1 - g + d))) << "\n";
    return 0;
}

#endif

/*

*/
