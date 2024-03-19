#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e3 + 10;

struct Point{
  double x, y;
  Point(){}
  Point(double x, double y):x(x),y(y){}
  void read(){
    cin >> x >> y;
  }
  Point operator - (Point A){
    return Point(x - A.x, y - A.y);
  }
}P[N];

double det(Point A, Point B){
  return A.x * B.y - A.y * B.x;
}

double sqr(double x){
  return x * x;
}

double dist(Point &A, Point &B){
  return sqrt(sqr(A.x-B.x) + sqr(A.y-B.y));
}

double check(Point &A, Point &B, Point &C){
  double s = fabs(det(A - B, C - B));
  double d = dist(A, C);
  return s / d;
}

int n;

void _main(){
  cin >> n;
  for(int i=0; i<n; ++i)  P[i].read();
  P[n] = P[0]; P[n+1] = P[1];
  double ans = 1e20;
  for(int i=1; i<=n; ++i){
    ans = min(ans, check(P[i-1], P[i], P[i+1]));
  }
  ans = ans * 0.5;
  cout << fixed << setprecision(8) << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
