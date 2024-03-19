#include <bits/stdc++.h>
using namespace std;

typedef double db;
const db EPS = 1E-9;

inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }

inline int cmp(db a, db b) { return sign(a - b); }

struct P
{
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) { return {x + p.x, y + p.y}; }
    P operator-(P p) { return {x - p.x, y - p.y}; }
    P operator*(db d) { return {x * d, y * d}; }

    bool operator<(P p) const
    {
        int c = cmp(x, p.x);
        if (c)
            return c == -1;
        return cmp(y, p.y) == -1;
    }

    bool operator==(P o) const
    {
        return cmp(x, o.x) == 0 && cmp(y, o.y) == 0;
    }

    db dot(P p) { return x * p.x + y * p.y; }
    db distTo(P p) { return (*this - p).abs(); }
    db abs() { return sqrt(abs2()); }
    db abs2() { return x * x + y * y; }
};

bool isMiddle(db a, db m, db b)
{
    return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}

bool isMiddle(P a, P m, P b)
{
    return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}

P proj(P p1, P p2, P q)
{
    P dir = p2 - p1;
    return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}

db nearest(P p1, P p2, P q)
{
    if (p1 == p2)
        return p1.distTo(q);
    P h = proj(p1, p2, q);
    if (isMiddle(p1, h, p2))
        return q.distTo(h);
    return min(p1.distTo(q), p2.distTo(q));
}

const int N = 1010;
P a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = P(x, y);
    }
    a[n] = P(a[0].x, a[0].y);
    a[n + 1] = P(a[1].x, a[1].y);

    db ans = 2E9;
    for (int i = 1; i <= n; i++)
        ans = min(ans, nearest(a[i - 1], a[i + 1], a[i]));
    cout << setprecision(12) << ans / 2 << "\n";
    return 0;
}