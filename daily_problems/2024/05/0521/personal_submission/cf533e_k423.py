# https://codeforces.com/contest/533/submission/261955995

# 我永远喜欢爱莉希雅♪ #
import string

n = int(input())
s = input()
t = input()

l, r = 0, n - 1
while s[l] == t[l]: l += 1
while s[r] == t[r]: r -= 1

s = s[l:r + 1]
t = t[l:r + 1]
ans = set()
if s[1:] == t[:-1]:
    ans.add(s + t[-1])
if s[:-1] == t[1:]:
    ans.add(t + s[-1])
print(len(ans))

