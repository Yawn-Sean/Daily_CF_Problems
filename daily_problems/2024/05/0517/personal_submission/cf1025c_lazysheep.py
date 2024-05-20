s = input()
n = len(s)
s += s 
 
ans, idx = 0, 0 
while idx < n:
    st = idx 
    idx += 1
    while idx < st + n and s[idx] != s[idx - 1]:
        idx += 1 
    ans = max(ans, idx - st)
print(ans)
