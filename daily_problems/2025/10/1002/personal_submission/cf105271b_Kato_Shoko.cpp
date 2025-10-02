#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il char query(int i,int x){
    cout<<"? "<<i<<" "<<x<<endl;
    char op;
    cin>>op;
    return op;
}

il void solve(){
    int n;
    cin>>n;

    vector<int>a(n+1);

    int last=1;
    for(int i=1;i<=n;i++){
        while(query(i,last)!='='){
            last++;
        }
        a[i]=last;
    }

    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
