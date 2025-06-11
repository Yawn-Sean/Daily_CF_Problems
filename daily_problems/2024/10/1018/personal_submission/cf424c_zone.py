n = II() 
a = LII() 

ans = 0 
cnt = [0] * (n + 1) 
for i, x in enumerate(a, 1): 
    ans ^= x 
    for j in range(n // i + 1):
        k = min(i, n - j * i + 1)
        cnt[0] += 1 
        cnt[k] -= 1 

cnt = list(accumulate(cnt))
for i in range(1, n):
    if cnt[i] & 1: 
        ans ^= i 

print(ans)
