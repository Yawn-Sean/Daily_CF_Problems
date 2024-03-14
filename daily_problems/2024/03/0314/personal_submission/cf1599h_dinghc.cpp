#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int64 query(int64 x, int64 y) {
    cout << "? " << x << " " << y << "\n";
    int64 d;
    cin >> d;
    return d;
}

int main() {
    int64 d1 = query(1, 1);
    int64 d2 = query(1e9, 1);

    int64 xm = (d1 - d2 + 1e9 + 1) / 2;
    int64 dy = query(xm, 1);
    int64 x1 = d1 - dy + 1, y1 = dy + 1;

    int64 d3 = query(1e9, 1e9);
    int64 y2 = 1e9 - (d3 - (d2 - dy));
    int64 x2 = 1e9 - (d2 - dy);
    
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";

    return 0;
}
