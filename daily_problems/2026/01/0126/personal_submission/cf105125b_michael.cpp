#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    int total = 0;
    vector<int> one;
    vector<int> more;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        total += arr[i];
        if(arr[i] == 1){
            one.push_back(i);
        }else if(arr[i] > 1){
            more.push_back(i);
        }
    }
    
    vector<int> res;
    for(int id = 1; ;++id){
        if((id & 1) == 0){
            if(more.size()){
                int tmp = more.back();
                arr[tmp]--;
                res.push_back(tmp);
                if(arr[tmp] == 1){
                    more.pop_back();
                    one.push_back(tmp);
                }
            }else{
                break;
            }
        }else{
            if(one.size()){
                int tmp = one.back();
                arr[tmp]--;
                res.push_back(tmp);
                one.pop_back();
            }else if(more.size()){
                int tmp = more.back();
                arr[tmp]--;
                res.push_back(tmp);
                if(arr[tmp] == 1){
                    more.pop_back();
                    one.push_back(tmp);
                }
            }else{
                break;
            }
        }
    }

    if(res.size() == total){
        cout << "YES\n";
        for(auto a : res){
            cout << a << " ";
        }
        cout << '\n';
    }else{
        cout << "NO\n";
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}