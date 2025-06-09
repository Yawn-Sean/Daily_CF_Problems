#include<iostream>
using namespace std;
#define int long long
void solve(){
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    if(b*d*f>a*c*e||(!a&&b&&d)||(!c&&d))cout << "Ron" << endl;
    else cout << "Hermione" << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
