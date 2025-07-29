"""
考虑字符 s[i] 是否符合题意
考虑强制使用 s[i]，s[1...i] 至多能匹配到 t 的哪里，假设能匹配到 t[pos]
则只需要看 s[i + 1...n] 能否匹配 t[pos + 1...m] 即可，这个可以预处理出来
前缀的那部分匹配具体怎么算？如何强制匹配 s[i]?
先让 s[1...i - 1] 去匹配，假设至多匹配到 t[p1]，则看 t[p1 + 1...m] 中有没有 s[i]
- 如果有，则后边就直接判断后缀
- 如果没有，要找前面的那个和 s[i] 相同的字符，看它匹配到了哪里
"""

s = " " + input()
t = " " + input()
n = len(s) - 1
m = len(t) - 1

suffix_match_pos = [m + 2 for _ in range(n + 2)]
idx = m
for i in range(n, 0, -1):
    if idx <= 0:
        suffix_match_pos[i] = 1
        continue

    if s[i] == t[idx]:
        suffix_match_pos[i] = idx
        idx -= 1
    else:
        suffix_match_pos[i] = suffix_match_pos[i + 1]

ok = True
last_match_pos = [-1 for _ in range(26)]
idx = 1
for i in range(1, n + 1):
    ch = ord(s[i]) - ord('a')
    if idx <= m and s[i] == t[idx]:
        last_match_pos[ch] = idx
        idx += 1
    if i + 1 <= n and suffix_match_pos[i + 1] > last_match_pos[ch] + 1:
        ok = False
        break

print("Yes" if ok else "No")
