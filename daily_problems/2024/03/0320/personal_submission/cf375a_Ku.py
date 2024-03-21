#https://codeforces.com/problemset/problem/375/A
from itertools import  permutations
from collections import Counter
a = map(str,input())
saved = [''] * 7
for i in permutations('1689'):
    s = ''.join(i)
    saved[int(s) % 7] = s
cnt = Counter(a)
for i in '1689':
    cnt[i] -= 1
ans = []
for i in cnt:
    if i != '0':
        ans.append(i * cnt[i])
mod = 0   #大数取模
s = ''.join(ans)
for x in s:
    mod = (10 * mod + int(x)) % 7
#后面加’1689‘ 4位 因此新的数为 mod * 10000 + x
new_begin = (10000 * mod) % 7
opt = 7 - new_begin if new_begin else 0
res = ''.join(ans) + saved[opt] + '0' * cnt['0']
print(res)
