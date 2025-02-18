#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll p, q, a;
int n;
int main(){
    cin >> p >> q >> n;
    while(n--){
        cin >> a;
        if(q == 0 || p / q < a){
            cout << "NO";
            return 0;
        }
        ll t = q;
        q = p - a * q;
        p = t;
//        cout << p << " " << q << endl;
    }
    if(q == 0) cout << "YES";
    else cout << "NO";
}
