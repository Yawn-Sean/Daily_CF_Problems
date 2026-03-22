n=int(input())
v=[]
t=[]
for _ in range(n):
    vs,ts=map(int,input().split())
    v.append(vs)
    t.append(ts)

st_range=sorted(range(n),key=lambda x: t[x])
total_v=sum(v)
res=0
cur_t=0
cur_v=total_v
ans=[0]*n
for i in st_range:
    res+=(t[i]-cur_t)*cur_v/total_v
    cur_t=t[i]
    cur_v-=v[i]
    ans[i]=res
print('\n'.join(map(str, ans)))