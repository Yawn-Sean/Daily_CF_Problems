#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
const double Pi = 3.141592653589793238462643383;
#define int double

int n, Px, Py, cx, cy;
int x[N], y[N];
int maxn, minn;
signed Pair;

int dis(int ax, int ay, int bx, int by) {
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

signed main() {
    cin >> n >> Px >> Py;
    for (signed i = 1; i <= n; i++) cin >> x[i] >> y[i];
    
    minn = 0x3f3f3f3f3f3f3f3f;
    maxn = 0;
    
    for (signed i = 1; i <= n; i++) {
        maxn = max(maxn, dis(Px, Py, x[i], y[i]));
        minn = min(minn, dis(Px, Py, x[i], y[i]));
    }
    
    for (signed i = 1; i <= n; i++) {
        if (i == 1) Pair = n;
        else Pair = i - 1;
        
        int dx = x[i] - x[Pair];
        int dy = y[i] - y[Pair];
        int A = dy;
        int B = -dx;
        int C = dx * y[Pair] - dy * x[Pair];
        
        int num = A * Px + B * Py + C;
        int den = A * A + B * B;
        
        cx = Px - A * num / den;
        cy = Py - B * num / den;
        
        if (cx < min(x[Pair], x[i]) || cx > max(x[Pair], x[i]) || cy < min(y[Pair], y[i]) || cy > max(y[Pair], y[i])) continue;
        
        minn = min(minn, dis(Px, Py, cx, cy));
    }
    
    cout << fixed << setprecision(16) << (maxn - minn) * Pi << endl;
    
    return 0;
}
