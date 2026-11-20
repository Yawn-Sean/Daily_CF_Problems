#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll a,m,b,n;
    cin >> a >> m >> b >> n;
    auto bfs = [&](int s) -> string{
        vector<int> pa(n,-1);
        vector<char> op(n);
        pa[s] = s;
        queue<ll> q;
        q.push(s);
        while(!q.empty()){
            ll u = q.front();
            q.pop();
            if(u == b) break;
            int t = (u + m) % n;
            if(pa[t] == -1){
                q.push(t);
                pa[t] = u;
                op[t] = '+';
            }
            t = ((u - m) % n + n) % n;
            if(pa[t] == -1){
                q.push(t);
                pa[t] = u;
                op[t] = '-';
            }
            t = u * m % n;
            if(pa[t] == -1){
                q.push(t);
                pa[t] = u;
                op[t] = '*';
            }
        }
        if(pa[b] == -1){
            return "";
        }
        string ans;
        for(int i = b;i != s;i = pa[i]){
            ans.push_back(op[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    };
    int s = (a % n + n) % n;
    if(s == b){
        cout << 0 << '\n';
        return;
    }
    string ans1 = bfs(s);
    string ans2 = bfs(0);
    s = ((a % m + m) % m) % n;
    string ans3 = bfs(s);
    if(ans1.size() == 0 && ans2.size() == 0){
        cout << -1 << '\n';
        return;
    }
    auto print = [](string ans) -> void {
        cout << ans.size() << '\n' << ans << '\n';
    };
    ans2.insert(0,"*%");
    ans3.insert(0,"%");
    if(ans2.size() < ans1.size()){
        if(ans3.size() < ans2.size()){
            print(ans3);
        }else print(ans2);
    }else{
        if(ans3.size() < ans1.size()){
            print(ans3);
        }else print(ans1);
    }
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