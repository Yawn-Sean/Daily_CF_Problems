//链接：https://codeforces.com/problemset/problem/849/B
//  ctrl+shift+A   2024-08-24

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e3+10;
typedef long long ll;

ll g[MAX];
int n;

void f(){
	for(int i=0;i<3;i++){
		for(int j=0;j<i;j++){
			ll k=2*(g[i]-g[j])/(i-j);
			set<ll> st;
			for(int id=0;id<n;id++){
				ll kb=2*g[id]-k*(id+1);
				st.insert(kb);
				if(st.size()>2) break;
			}
			if(st.size()==2){
				cout<<"Yes"<<endl;
				return ;
			}
		}
	}
	
	cout<<"No"<<endl;
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>g[i];
	}
	
	f();
    return 0;
} 
