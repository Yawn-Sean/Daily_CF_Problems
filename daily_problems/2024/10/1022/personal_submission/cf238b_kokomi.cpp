#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, h;
const int N = 1e5 + 10;
ll a[N],b[N];
int main(){
    cin >> n >> h;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    if(n == 2){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    ll ans = a[n] + a[n-1] - a[1] - a[2];
    if(ans <= max(a[1] + a[n] + h, a[n] + a[n-1]) - min(a[1] + a[2] + h, a[2] + a[3])){
        cout << ans << endl;
        for(int i = 1; i <= n; i++){
            cout << 1 << " ";
        }
    }else{
        cout << max(a[1] + a[n] + h, a[n] + a[n-1]) - min(a[1] + a[2] + h, a[2] + a[3]) << endl;
        int mark = 0;
        for(int i = 1; i <= n; i++){
            if(mark == 0 && b[i] == a[1]){
                cout << 1 << " ";
                mark = 1;
            }else{
                cout << 2 << " ";
            }
        }
    }
}