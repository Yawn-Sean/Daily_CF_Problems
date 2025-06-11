/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-12 11:56 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int x, y, l, r;
int ans;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> l >> r >> x >> y;
    if (y % x) {
        cout << 0 << endl;
        return 0;
    }
    int p = y / x;
    for (int i = 1; 1ll * i * i <= p; i ++) {
        if (p % i == 0) {
            if (gcd(i, p / i) != 1) continue;
            if (1ll * i * x >= l &&  1ll * (p / i) * x <= r) {
                if (p / i == i) ans ++;
                else ans += 2;
            }
        } 
    }  
    cout << ans << endl;
    return 0;
}

/*

*/
