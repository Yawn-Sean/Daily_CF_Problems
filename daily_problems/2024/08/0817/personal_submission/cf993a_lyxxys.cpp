#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 3e5+11, mod = 1e9+7, inf = 1e9;
struct dot{
    int x, y;
};
int cross(dot A, dot B){
    return A.x*B.y - A.y*B.x;
}
dot operator-(dot a, dot b){
    return {a.x-b.x, a.y-b.y};
}
int sgn(int x){
    if (!x) return x;
    return x < 0 ? -1 : 1;
}
bool segCross(dot a, dot b, dot c, dot d){
    int c1 = cross(b-a, c-a), c2 = cross(b-a, d-a);
    int c3 = cross(d-c, a-c), c4 = cross(d-c, b-c);
    return c1*c2 <= 0 && c3*c4 <= 0;
}
bool sqrCross(array<dot,4> A, array<dot,4> B){
    bool jg = 1;
    int f1 = 0, f2 = 0;
    for (int i = 0; i < 4; ++ i){
        for (int j = 0; j < 4; ++ j){
            int c = cross(A[(i+1)%4]-A[i], B[j]-A[i]);
            if (sgn(c) > 0) f1 = 1;
            if (sgn(c) < 0) f2 = 1;
            if (f1 && f2) jg = 0;
        }
    }
    return jg;
}
void solve(){
    array<dot,4> A, B;
    for (int i = 0; i < 4; ++ i) cin >> A[i].x >> A[i].y;
    for (int i = 0; i < 4; ++ i) cin >> B[i].x >> B[i].y;

    for (int i = 0; i < 4; ++ i){
        for (int j = 0; j < 4; ++ j){
            if (segCross(A[i], A[(i+1)%4], B[j], B[(j+1)%4])){
                cout << "YES\n";
                return;
            }
        }
    }
    bool jg = (sqrCross(A, B) || sqrCross(B, A));
    cout << (jg ? "YES\n" : "NO\n");
}
