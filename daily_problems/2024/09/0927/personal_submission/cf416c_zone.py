"""
problem url   : https://codeforces.com/problemset/problem/416/C
submission url: https://codeforces.com/contest/416/submission/283129089
"""
n = II()
b = [None] * n  
for i in range(n):
    b[i] = LII() 
k = II() 
a = LII()
idxa = sorted(range(k), key=lambda x: a[x])
idxb = sorted(range(n), key=lambda x: b[x][0])
cnt = [] 
ans = 0 
i = 0 
outs = [] 
for j in idxa: 
    while i < n and b[idxb[i]][0] <= a[j]: 
        heappush(cnt, (-b[idxb[i]][1], idxb[i] + 1))
        i += 1 
    if cnt:
        t = heappop(cnt) 
        ans -= t[0]
        outs.append(f"{t[1]} {j + 1}")

print(f"{len(outs)} {ans}")
print('\n'.join(outs))
