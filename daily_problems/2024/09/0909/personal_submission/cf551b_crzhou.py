a, b, c = I(), I(), I()
al = [0] * 26
bl = [0] * 26
cl = [0] * 26
for x in a:
    al[ord(x) - ord('a')] += 1
for x in b:
    bl[ord(x) - ord('a')] += 1
for x in c:
    cl[ord(x) - ord('a')] += 1

def count(s: List[int], t: List[int]) -> int:
    res = 1e5 + 1  # 1e5 不对
    for i, x in enumerate(t):
        if x:
            if s[i] >= x:
                res = min(res, s[i] // x)
            else:
                return 0
    return res

tmp1 = count(al, bl)
ans = 0
res = [0, 0]
for x in range(tmp1 + 1):
    tmp = al.copy()
    for i in range(26):
        tmp[i] -= bl[i] * x
    t = count(tmp, cl) + x
    if t > ans:
        ans = t
        res = [x, t - x]

for i in range(26):
    al[i] -= bl[i] * res[0] + cl[i] * res[1]
ans = b * res[0] + c * res[1]
for i in range(26):
    ans += al[i] * (chr(ord('a') + i))
print(ans)
