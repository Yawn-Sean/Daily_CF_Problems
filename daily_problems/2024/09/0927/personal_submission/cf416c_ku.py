n = RI()
c,p = [],[]
for _ in range(n):
    x,y = RII()
    c.append(x)
    p.append(y)
k = RI()
t = RLIST()
table = []
for i,x in enumerate(t):
    table.append((x,i))
table.sort()  #按桌子容纳人数排列
table_ = [table[i][0] for i in range(len(table))]

people = []
for i in range(n):
    people.append((p[i],c[i],i))
people.sort(key = lambda x:(-x[0],x[1]))  #按pay降序排列
ans = 0
res = []
for i in range(n):
    pay,count,index = people[i]
    j = bisect.bisect_left(table_,count)
    if j == len(table_):
        continue
    else:
        ans += pay
        res.append(f'{index+1} {table[j][1]+1}')
        #res.append((index+1,table[j][1]+1))
        del table_[j]
        del table[j]
print(len(res),end = ' ')
print(ans)
print('\n'.join(res))
