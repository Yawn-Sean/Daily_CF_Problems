import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# set维护b集合（直接用数组记就行），双链表维护a集合
# 然后提前记录一下b集合中要被选的数即可

def delete(x):
    if l[x] >= 0:
        r[l[x]] = r[x]
    if r[x] < n:
        l[r[x]] = l[x]

mod = 998244353
outs = []
for _ in range(II()):
    n, k = MII()
    a, b = LGMI(), LGMI()
    l, r = list(range(-1, n - 1)), list(range(1, n + 1)) # 这就是双链表
    pos = [-1] * n # 利用位置直接去找值
    for i in range(n):
        pos[a[i]] = i

    st = [False] * n # 记录哪些值被选了
    for i in range(k):
        st[b[i]] = True
        b[i] = pos[b[i]] # 全部改成下标
    
    ans = 1
    for x in b: # 已经是下标了
        cnt = 0
        if l[x] >= 0 and not st[a[l[x]]]:
            cnt += 1
        if r[x] < n and not st[a[r[x]]]:
            cnt += 1
        if cnt == 0:
            ans = 0
            break
        
        delete(x) # 直接删它就行，反正已经没用了
        ans *= cnt
        ans %= mod
    outs.append(ans)

print(*outs, sep='\n')