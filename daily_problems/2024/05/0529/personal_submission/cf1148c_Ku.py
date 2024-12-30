#https://codeforces.com/problemset/problem/1148/C
import sys
input = lambda : sys.stdin.readline().rstrip()
RII = lambda : int(sys.stdin.readline().rstrip())
RIII = lambda :map(int,sys.stdin.readline().rstrip().split())
RLIST = lambda :list(RIII())

n = RII()
li = RLIST()
for i,x in enumerate(li):
    li[i] = x - 1
pos = [-1] * n
ans = []
for i,x in enumerate(li):
    pos[x] = i

def swap(u, v):
    pos[li[u]], pos[li[v]] = pos[li[v]], pos[li[u]]
    li[u],li[v] = li[v],li[u]
    ans.append(f'{u+1} {v+1}')

for i in range(1, n //2):
    if i != pos[i]:
        if pos[i] < n // 2:
            #二次交换
            swap(pos[i],n - 1)
            swap(n - 1,i)
        else:
            #三次交换
            swap(pos[i],0)
            swap(0, n - 1)
            swap(n - 1,i)

for i in range(n // 2, n):
    if i != pos[i]:
        if pos[i] < n // 2:
            #三次交换
            swap(pos[i],n - 1)
            swap(n - 1,0)
            swap(0,i)
        else:
            #二次交换
            swap(pos[i],0)
            swap(0, i)

#特判第一个位置
if pos[0] != 0:
    swap(0,n-1)
    print(li)
print(len(ans))
print('\n'.join(ans))
