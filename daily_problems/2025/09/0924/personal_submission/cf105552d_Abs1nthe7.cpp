#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
#define M_PI 3.14159265358979323846
//数学题，点与线的距离，然后算面积就行
void sol()
{
    
    int n;
    double r;
    cin >> n >> r;
    double best_s = 0.0;
    
    for (int i = 0; i < n; ++i) 
    {
        int A, B, C;
        cin >> A >> B >> C;
        double tmp = sqrt(1.0 * A * A + 1.0 * B * B);
        double d = fabs(C) / tmp;
        double theta = 2 * acos(d / r);
        
        double s = (theta - sin(theta)) / (2 * M_PI);//扇形面积是r2*th/2，三角形是r2*sinth/2,然后除掉总圆面积
        if (s > best_s) 
        {
            best_s = s;
        }
    }
    cout << fixed << setprecision(10) << best_s << ' ' << 1 - best_s << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
