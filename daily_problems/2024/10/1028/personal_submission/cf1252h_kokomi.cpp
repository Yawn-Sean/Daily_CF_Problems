#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct Node{
    ll x, y;
}a[N];
bool cmp(Node a, Node b){
    return a.y > b.y;
}
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        ans = max(ans, a[i].x * a[i].y);
        if(a[i].x > a[i].y){
            swap(a[i].x, a[i].y);
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    ll maxx = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, min(maxx, a[i].x) * a[i].y * 2);
        maxx = max(maxx, a[i].x);
    }
    (ans % 2) ? printf("%lld.5\n", ans / 2) : printf("%lld.0\n", ans / 2);
    // double res = (double)ans / 2;
    //  cout << fixed << setprecision(1) << res << endl;
}