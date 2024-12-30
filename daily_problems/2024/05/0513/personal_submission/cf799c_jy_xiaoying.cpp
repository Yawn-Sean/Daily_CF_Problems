//链接：https://codeforces.com/problemset/problem/799/C

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
typedef vector<pp> vv;

const int MAX=1e5+10;
int dd[MAX];     //前缀最大美丽值 beauty 
int cc[MAX];

vv dia;
vv coi;

int n,c,d;

void build(){
	dia.clear();
	coi.clear();
}

int bs(vv &g,int l,int r,int tar){
	int id=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(g[mid].second<=tar){
			id=mid;
			l=mid+1;
		}
		else
		   r=mid-1;
	}
	return id;
}

void fff(){
    sort(dia.begin(),dia.end(),[&](const pp &a,const pp &b){
    	return a.second<b.second;
	}); 
	
	sort(coi.begin(),coi.end(),[&](const pp &a,const pp &b){
    	return a.second<b.second;
	});
	
	int tt=coi.size();
	if(tt>=1)
	cc[0]=coi[0].first;                        //前缀最大美丽值 beauty 
	for(int i=1;i<tt;i++){
		cc[i]=max(cc[i-1],coi[i].first);
	}
	
	tt=dia.size();
	if(tt>=1)
	dd[0]=dia[0].first;                       //前缀最大美丽值 beauty 
	for(int i=1;i<tt;i++){
		dd[i]=max(dd[i-1],dia[i].first);
	}
	
	int ans=0;
	tt=coi.size();                              //用同一种材料 -- coins
	for(int i=1;i<tt;i++){
		if(coi[i].second>c) break;
		
		int tmp=c-coi[i].second;
	    int id=bs(coi,0,i-1,tmp);
	    
		int beauty=coi[i].first;
		if(id==-1) break;                       //一定得打造2个喷泉 
		
			beauty+=cc[id];
		ans=max(ans,beauty);
	}
	
	tt=dia.size();                              //用同一种材料 -- diamonds 
	for(int i=1;i<tt;i++){
		if(dia[i].second>d) break;
		
		int tmp=d-dia[i].second;
		int id=bs(dia,0,i-1,tmp);
		
		int beauty=dia[i].first;
		if(id==-1)   break;                   //一定得打造2个喷泉 
		
			beauty+=dd[id];
		
		ans=max(ans,beauty);
	}
	
	tt=dia.size(); 
	int id1=bs(dia,0,tt-1,d);
	tt=coi.size(); 
	int id2=bs(coi,0,tt-1,c);
	
	if(id1!=-1 && id2!=-1)
	ans=max(ans,dd[id1]+cc[id2]);
	
	cout<<ans<<"\n";
}

int main(){
	cin>>n>>c>>d;
	build();
	
	int b,cost;
	char f;
	for(int i=0;i<n;i++){
		cin>>b>>cost>>f;
		if(f=='C'){
			coi.push_back(pp(b,cost));
		}
		else{
			dia.push_back(pp(b,cost));
		}
	}
	
	fff();
	return 0;
} 
