# https://codeforces.com/contest/314/submission/280677031
b, d = map(int, input().split()) 
a, c = input(), input() 

m = len(c)

next_idx = list(range(m))
cnt = [0] * m
for i in range(m): 
    for ch in a: 
        if ch == c[next_idx[i]]: 
            next_idx[i] += 1 
            if next_idx[i] == m: 
                cnt[i] += 1 
                next_idx[i] = 0 
ans = idx = 0 
for _ in range(b):
    ans += cnt[idx]
    idx = next_idx[idx]
print(ans // d)
