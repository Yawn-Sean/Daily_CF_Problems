# submission url: https://codeforces.com/contest/729/submission/281559910
# 修改a中元素，使其满足mex(a) = max(a) + 1，对于0的情况需单独考虑

n, s = map(int, input().split()) 
a = list(map(int, input().split()))
cnt = [0] * (n + 2)

for x in a: 
    cnt[x] += 1 

if a[s - 1]:
    ans = 1 
    cnt[-1] += cnt[0]
    cnt[a[s - 1]] -= 1 
else:
    ans = 0 
    cnt[-1] += cnt[0] - 1

mx  = n + 1
mex = 1 
while mex < mx:
    while mex < mx and cnt[mx] == 0: 
        mx -= 1
    while mex < mx and cnt[mex]: 
        mex += 1
    if mex < mx: 
        ans += 1 
        cnt[mx]  -= 1
    mex += 1 
print(ans + cnt[-1])
