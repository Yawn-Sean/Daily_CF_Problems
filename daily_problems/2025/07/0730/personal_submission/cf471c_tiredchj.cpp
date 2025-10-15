#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define mem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
constexpr int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    ll n;
    cin>>n;
    int cnt=0;
    for (ll h=1;h*(3*h+1)/2<=n;h++){
        ll temp=n+h;
        if (temp%3==0){
            ll k=temp/3;
            if (k>=h*(h+1)/2){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
