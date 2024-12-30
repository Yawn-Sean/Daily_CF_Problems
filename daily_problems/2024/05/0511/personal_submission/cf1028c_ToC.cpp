// https://codeforces.com/contest/1028/submission/260814107
// left, right, down, up
int xl[MAXN], xr[MAXN], yd[MAXN], yu[MAXN];
struct Info {
    int x1, x2, y1, y2;
};
Info L[MAXN], R[MAXN];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> xl[i] >> yd[i] >> xr[i] >> yu[i];
    int x1 = -INF, x2 = INF, y1 = -INF, y2 = INF;
    for (int i = 1; i <= n; i++) {
        x1 = max(x1, xl[i]), x2 = min(x2, xr[i]);
        y1 = max(y1, yd[i]), y2 = min(y2, yu[i]);
        L[i] = {x1, x2, y1, y2};
    }
    x1 = -INF, x2 = INF, y1 = -INF, y2 = INF;
    for (int i = n; i >= 1; i--) {
        x1 = max(x1, xl[i]), x2 = min(x2, xr[i]);
        y1 = max(y1, yd[i]), y2 = min(y2, yu[i]);
        R[i] = {x1, x2, y1, y2};
    }
    L[0] = {-INF, INF, -INF, INF};
    R[n + 1] = L[0];
    for (int i = 1; i <= n; i++) {
        x1 = max(L[i - 1].x1, R[i + 1].x1);
        x2 = min(L[i - 1].x2, R[i + 1].x2);
        y1 = max(L[i - 1].y1, R[i + 1].y1);
        y2 = min(L[i - 1].y2, R[i + 1].y2);
        if (x1 <= x2 && y1 <= y2) {
            cout << x1 << " " << y1 << '\n';
            break;
        }
    }
}
