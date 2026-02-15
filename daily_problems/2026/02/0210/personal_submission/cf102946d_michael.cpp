#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    
    int secmx = -1,fstmx = -1;
    int mx = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        cout << "? " << 0 << ' ' << i << endl;
        cin >> mx;
        if(mx == n){
            if(secmx != -1){
                flag = true;
            }
            secmx = i;
        }
    }
    //0号位置最大
    if(flag){
        for(int i = 0; i < n; ++i){
            cout << "? " << 1 << ' ' << i << endl;
            cin >> mx;
            if(mx == n){
                secmx = i;
                break;
            }
        }
        cout << "! " << secmx << '\n';
    }else{
        int tmp = (secmx + 1) % n;
        for(int i = 0; i < n; ++i){
            cout << "? " << i << ' ' << tmp << endl;
            cin >> mx;
            if(mx == n){
                fstmx = i;
                break;
            }
        }
        cout << "! " << (secmx - fstmx + n) % n << '\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}
