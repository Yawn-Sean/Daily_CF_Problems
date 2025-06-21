#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
bool ncmp(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<0>(a)==get<0>(b))return get<1>(a)<get<1>(b);
    return get<0>(a)<get<0>(b);
}
void solve(){
	int n;cin>>n;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y, i});
    }
    sort(v.begin(), v.end(),ncmp);
    int flag=-1,ans1=-1,ans2=-1,ans3=-1;
    for(int i=0;i<n-2;i++){
        int a1=get<0>(v[i]),a2=get<0>(v[i+1]),a3=get<0>(v[i+2]);
        int x1 = get<0>(v[i]), y1 = get<1>(v[i]);
        int x2 = get<0>(v[i+1]), y2 = get<1>(v[i+1]);
        int x3 = get<0>(v[i+2]), y3 = get<1>(v[i+2]);
        if((x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)) continue;
        else {
            ans1 = get<2>(v[i]);
            ans2 = get<2>(v[i+1]);
            ans3 = get<2>(v[i+2]);
            break;
        }


    }
    cout<<ans1+1<<" "<<1+ans2<<" "<<1+ans3<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
