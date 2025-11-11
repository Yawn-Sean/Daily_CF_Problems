#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 2E5 + 10;
int n, a[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1;i <= n; ++i){
        cin >> a[i];
    }
    int mxl = 0, mxr = 0;
    int mil = 1E9, mir = 1E9;
    for (int i = 1; i <= n / 2; ++i){
        mxl = max(mxl, a[i]);
        mil = min(mil, a[i]);
    }
    for (int i = n; i > n / 2; --i){
        mxr = max(mxr, a[i]);
        mir = min(mir, a[i]);
    }
 
    if (mxl < mir || mil > mxr){
        cout << "1\n";
        cout << n << " ";
        for (int i = 1; i <= n; ++i){
            cout << a[i] << " \n"[i == n];
        }
    }else{
        int num = 0;
        for (int i = 1;i <= n / 2; ++i){
            if (a[i] <= n / 2){
                num++;
            }
        }
        cout << "2\n";
        cout << num * 2 << " ";
        for (int i = 1; i <= n / 2; ++i){
            if (a[i] <= n / 2){
                cout << a[i] << " ";
            }            
        }
        for (int i = n / 2 + 1; i <= n; ++i){
            if (a[i] > n / 2){
                cout << a[i] << " ";
            }            
        }
        cout << endl;
        cout << n - num * 2 << " ";
        for (int i = 1; i <= n / 2; ++i){
            if (a[i] > n / 2){
                cout << a[i] << " ";
            }            
        }
        for (int i = n / 2 + 1; i <= n; ++i){
            if (a[i] <= n / 2){
                cout << a[i] << " ";
            }            
        }        
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}