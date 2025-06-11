#include<bits/stdc++.h>
using namespace std;
int R[70], C[70];
int r, c, sum;
bool is_sj(int x, int y){
	if(x==1&& y==1) return 1;
	if(x==1&& y==c) return 1;
	if(x==r&& y==1) return 1;
	if(x==r&& y==c) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		sum=0;
		bool sj=0;//四角是否有点
		cin>>r>>c;
		for(int i=1;i<=r;i++) R[i]=0;
		for(int i=1;i<=c;i++) C[i]=0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				char t;
				cin>>t;
				if(t=='A'){
					sum++;
					if(is_sj(i, j)) sj=1;
					R[i]++; C[j]++;
				}
			}
		}
		if(sum==0) cout<<"MORTAL\n";
		else if(sum==r*c) cout<<"0\n";
		else{
			if(R[1]==c|| R[r]==c|| C[1]==r|| C[c]==r) cout<<"1\n";
			else{
				bool fg=0;
				for(int i=1;i<=r;i++){
					if(R[i]==c){
						fg=1;
						break;
					}
				}
				for(int i=1;i<=c;i++){
					if(C[i]==r){
						fg=1;
						break;
					}
				}
				if(fg) cout<<"2\n";
				else{
					if(sj) cout<<"2\n";
					else{
						if(R[1]|| R[r]|| C[1]|| C[c]) cout<<"3\n";
						else cout<<"4\n";
					}
				}
			}
		}
	}
	return 0;
}
