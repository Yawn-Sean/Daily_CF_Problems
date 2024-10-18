n,m = RII()
s = input()
s = list(s)
ans = 0
cnt = 0
for i,x in enumerate(s):
    if x == '.':
        cnt += 1
    else:
        if cnt:
            ans += cnt - 1
        cnt = 0
if cnt: ans += cnt - 1
res = []
for _ in range(m):
    x,y = RIII()
    a = int(x) - 1
    if (s[a] == '.' and y == '.') or (s[a] != '.' and y != '.'):
        res.append(ans)
        continue
    elif y == '.' and s[a] != '.':
        if n >= 2:
            ans += 1
            if 0 < a < n-1 and s[a-1] == s[a+1] ==  '.':
                ans += 1
            elif 0 < a < n - 1 and s[a-1] != '.' and s[a+1] != '.':
                ans -= 1
            elif  (a == 0 and s[1] != '.') or (a == n - 1 and s[a-1] != '.'):
                ans -= 1
    elif y != '.' and s[a] == '.':
        if n >= 2:
            ans -= 1
            if 0 < a < n - 1 and s[a-1] == s[a+1] == '.':
                ans -= 1
            elif 0 < a < n - 1 and s[a-1] != '.' and s[a+1] != '.':
                ans += 1
            elif  (a == 0 and s[1] != '.') or (a == n - 1 and s[a-1] != '.'):
                ans += 1
    s[a] = y
    #print(res)
    res.append(ans)
print('\n'.join(map(str,res)))
