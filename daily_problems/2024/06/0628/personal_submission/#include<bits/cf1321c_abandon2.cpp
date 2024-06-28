#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int dx[]={-1,0,0,1},
	dy[]={0,-1,1,0};
	
void solve(){
    int n;cin>>n;
    string s;cin>>s;s=' '+s;
    std::vector<int>v(n+2,0);

    int cnt=0;
    for(int i=25;i>=0;i--){
    	for(int j=1;j<=n;j++){
    		if(s[j]-'a'==i){
    			for(int k=j-1;k>=1;k--){
    				if(v[k])continue;
    				if(s[k]==s[j]+1){
    					v[k]=1;
    				}
    				else{
    					break;
    				}
    				
    			}
    			for(int k=j+1;k<=n;k++){
    				if(v[k])continue;
    				if(s[k]==s[j]+1){
    					v[k]=1;
    				}else{
    					break;
    				}
    			}
    		}
    	}
    }
	
    cout<<count(v.begin(),v.end(),1)<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
