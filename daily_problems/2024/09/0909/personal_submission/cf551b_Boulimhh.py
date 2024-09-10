"""
思路：有点难读的题目，看了🐏神题解才知道什么意思。

求一个变化后的串，要求长度不变，包含尽可能多的 b 串或者 c 串的数量。

枚举 b 串最多是几个， 再看 c 串能放几个， 取二者数量的最大值， 再用其他字符填充。
"""
#python代码：
a = input()
b = input()
c = input()
ca, cb, cc = [0] * 26, [0] * 26, [0] * 26
for i in a: ca[ord(i) - 97] += 1
for i in b: cb[ord(i) - 97] += 1
for i in c: cc[ord(i) - 97] += 1
n, m = len(a), len(a) // len(b)

u, v = 0, 0
for i in range(m + 1):
    cnt = n
    ok = True
    for j in range(26):
        if ca[j] < cb[j] * i:
            ok = False
        if cc[j]:
            cnt = min(cnt, (ca[j] - cb[j] * i) // cc[j])
    if not ok:
        break
    if i + cnt > u + v:
        u, v = i, cnt

ans = [b * u + c * v]
for i in range(26):
    ans.append((ca[i] - cb[i] * u - cc[i] * v) * chr(ord('a') + i))
print(''.join(ans))
