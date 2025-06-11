n, m = RII()
li = []
for _ in range(n):
    s,r = RII()
    li.append((r,s))
li.sort(reverse=True)
dic = defaultdict(list)
dic2 = defaultdict(list)
for r,s in li:
    dic[s].append(r)
    if len(dic2[s]) == 0: res = 0
    else: res = dic2[s][-1]
    dic2[s].append(r + res)
dic3 = sorted(dic2.values(), key = lambda x:len(x),reverse=True)

len_li = []
for i in range(len(dic3)):
    len_li.append(len(dic3[i]))
len_li = len_li[::-1]
dic3 = dic3[::-1]
ans = 0
mx = len_li[-1]

for j in range(mx,0,-1):
    q = bisect.bisect_left(len_li,j)
    res = 0
    for r in range(q,len(len_li)):
        res += dic3[r][j-1] if dic3[r][j-1] >= 0 else 0
    #print(j,res)
    ans = max(ans,res)
print(ans)
