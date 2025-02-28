#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s=" ";
int sa[N], len, rc, min_i[N], idx, r_L, r_C;
bool st[135];
int main(){
	string t;
	cin>>t;
	len=t.size();
	s+=t;
	st['a']=st['e']=st['i']=st['o']=st['u']=1;
	st['A']=st['E']=st['I']=st['O']=st['U']=1;
	for(int i=1;i<=len;i++){
		sa[i]=sa[i-1];
		if(st[s[i]]) sa[i]-=1;
		else sa[i]+=2;
	}
	sa[0]=0;
    int r_idx=0;
	for(int i=1;i<=len;i++){
		if(sa[i]>=sa[min_i[idx]]){
            int t_idx=idx;
			for(int j=max(0, r_idx-2);j<=idx;j++){
            //j<=idx 而不是j<=min(idx, r_idx+1) hack:AAAAAAABBB
                if(sa[i]>=sa[min_i[j]]){
                    t_idx=j;
                    break;
                }
            }
			int t_L=i-min_i[t_idx];
            r_idx=t_idx;
			if(t_L>r_L){
				r_L=t_L;
				r_C=1;
			}else if(t_L==r_L) r_C++;
		}else{
			min_i[++idx]=i;
		}
	}
	if(r_C){
		cout<<r_L<<" "<<r_C;
	}else{
		cout<<"No solution";
	}
	return 0;
}
