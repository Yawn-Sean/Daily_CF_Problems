n = int(input())
p = [-1] + list(map(int,input().split()))
s = list(map(int,input().split()))
ans = 0

for i in range(1,n):
    if s[i] != -1 and (s[p[i] - 1] == -1 or s[p[i] - 1] > s[i]):
        s[p[i] - 1] = s[i]

for i in range(n-1,0,-1):
    if s[i] != -1:
        if s[p[i]-1] > s[i]:
            ans = -1
            break
        else:
            ans += s[i] - s[p[i]-1]
print(ans + s[0] if ans != -1 else -1)
