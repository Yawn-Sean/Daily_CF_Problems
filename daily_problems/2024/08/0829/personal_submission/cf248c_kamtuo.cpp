/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-29 18:53 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    int v = yw - r;
    y1 += 2 * (v - y1);
    y2 += 2 * (v - y2);
    // debug("y1:", y1, "y2:", y2);
    int s = y1 - r;
    double k = 1.0 * (yb - s) / xb;
    double b = 1.0 * yb - 1.0 * k * xb;
    if (fabs(fabs(-1.0 * y2 + b) / (sqrt(k * k + 1))) > r) {
        printf("%.12lf\n", (yw - r - b) / k);
    } else {
        cout << -1 << "\n";
    }
    return 0;
}

#endif

/*

*/
