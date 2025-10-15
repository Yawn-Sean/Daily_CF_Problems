"""
先求出交替的长度，如果反转的不是整个长度，那么会在11 或 00 处进行反转，产生2个长度
"""
n = int(input())
s = input()
res = 1
for i in range(1, n):
    if s[i] != s[i - 1]: res += 1
print(min(res + 2, n))
