#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= 1;
    }
    vector<int> b(n, 0);
    int mx1 = -1, mx2 = -1;
    for(int i = 0; i < n; i++){
        if(a[i] > mx1){
            b[a[i]] -= 1;
            mx2 = mx1;
            mx1 = a[i];
        }
        else if (a[i] > mx2){
            b[mx1] += 1;
            mx2 = a[i];
        }
    }
    int mx = -5;
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(b[i] > mx){
            mx = b[i];
            ans = i;
        }
    }
    cout << ans + 1<< endl;

}