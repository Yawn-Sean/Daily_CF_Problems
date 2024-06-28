/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-28 21:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n - 1, m - 1) + 1 << endl;
    return 0;
}

/*

*/
