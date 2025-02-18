n = int(input())
s = input()
ans = s.count("G")
a = [0] * n
if s[0] == "G":
    a[0] = 1
for i in range(1, n):
    if s[i] == "G":
        a[i] = a[i - 1] + 1
tar = 0
for i in range(n - 1, -1, -1):
    if a[i] == 0:
        tar = 0
    else:
        tar = max(tar, a[i])
        a[i] = tar

a = [0] + a + [0]
cnt = 0
for i in range(n + 1):
    if a[i] == 0:
        cnt = max(cnt, a[i + 1] + a[i - 1] + 1)
print(min(cnt, ans))
        
