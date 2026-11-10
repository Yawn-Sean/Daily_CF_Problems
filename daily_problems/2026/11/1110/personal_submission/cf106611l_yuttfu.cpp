#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    string ss = s;
    queue<int> q;
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(ss[i] == '?') continue;
        if(ss[i] == '0'){
            q.push(i);
            if(i-1 >= 0 && s[i-1] == '?') s[i-1] = '0',ans ++,q.push(i-1);
            if(i+1 < n && s[i+1] == '?') s[i+1] = '0',ans ++,q.push(i+1);
        }else if(ss[i] == '2'){
            if(i-1 >= 0 && s[i-1] == '?') s[i-1] = '2',q.push(i-1);
            if(i+1 < n && s[i+1] == '?') s[i+1] = '2',q.push(i+1);
        }else{
            q.push(i);
            if(n > 1 && (i == 0 || i == n-1)){
                int j = (i==0 ? 1 : n-2);
                if(s[j] == '?'){
                    s[j] = '2';
                    q.push(j);
                }
            }
        }
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(i-1 >= 0 && s[i-1] == '1'){
            if(i-2 >= 0 && s[i-2] == '?'){
                if(s[i] == '0' || s[i] == '1'){
                    s[i-2] = '2';
                }else if(s[i] == '2'){
                    s[i-2] = '0';
                    ans ++;
                }
                q.push(i-2);
            } 
        }
        if(i+1 < n && s[i+1] == '1'){
            if(i+2 < n && s[i+2] == '?'){
                if(s[i] == '0' || s[i] == '1'){
                    s[i+2] = '2';
                }else if(s[i] == '2'){
                    s[i+2] = '0';
                    ans ++;
                }
                q.push(i+2);
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
