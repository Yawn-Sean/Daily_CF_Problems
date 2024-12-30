/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-15 11:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

double a[N], b[N], r[N];
double ax, ay, bx, by, rx, ry;
double ans;
vector<std::pair<double, int>> ar, br;

double dis(double x, double y, double a, double b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

int main() {
    int n;
    cin >> ax >> ay >> bx >> by >> rx >> ry;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        double x, y;
        cin >> x >> y;
        a[i] = dis(ax, ay, x, y);
        b[i] = dis(bx, by, x, y);
        r[i] = dis(rx, ry, x, y);
        ans += 2.0 * r[i];
        ar.push_back({r[i] - a[i], i});
        br.push_back({r[i] - b[i], i});
    }
    sort(ar.begin(), ar.end());
    sort(br.begin(), br.end());
    double tot = ans;
    ans = min(ans - ar.back().first, ans - br.back().first);
    if (ar.back().second == br.back().second && n != 1) {
        ans = min(min(tot - ar.back().first - br[br.size() - 2].first, tot - br.back().first - ar[ar.size() - 2].first), ans);
    } else {
        if (n != 1) ans = min(ans, tot - ar.back().first - br.back().first);
    }
    printf("%.12lf", ans); 
    return 0;
}

/*

*/
