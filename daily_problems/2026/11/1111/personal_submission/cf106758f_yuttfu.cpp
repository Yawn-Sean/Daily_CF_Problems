#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int L = 1e9;

int wrap(int x){
    return ((x-1)%L+L)%L+1;
}

void solve(){
    int n;
    cin >> n;
    int cnt = n;
    string st;
    set<int> ss;
    int d;
    mt19937 rng(random_device{}());
    auto ask = [&](int x){
        cout << "? " << x << endl;
        cin >> st >> d;
        ss.insert(x);
        if(st == "YES") cnt --;
    };
    int x = 1;
    ask(x);
    while(1){
        int l = wrap(x - d);
        int r = wrap(x + d);
        if(l == r || ss.count(l)){
            cout << "! " << r << endl;
            return;
        }
        if(ss.count(r)){
            cout << "! " << l << endl;
            return;
        }
        if(cnt == 1){
            int t = (d == 1 ? 2 : 1);
            int dist = abs(d-t);
            ask(wrap(x+t));
            if(dist == d){
                cout << "! " << r << endl;
            }else{
                cout << "! " << l << endl;
            }
            return;
        }
        if(rng() % 2) swap(l,r);
        x = r;
        ask(x);
        if(st == "NO"){
            cout << "! " << l << endl;
            return;
        } 
    }
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
