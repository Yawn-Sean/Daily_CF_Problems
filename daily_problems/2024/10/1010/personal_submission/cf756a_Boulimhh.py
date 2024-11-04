"""
思路： 先判断有几个环， 再判断需不需要加反转次数。
"""

#pyrhon代码：
n = int(input())
p = list(map(int, input().split()))
b = list(map(int, input().split()))
st = [False] * n
cnt = 0
for i in range(n):
    if st[i]: continue
    cnt += 1
    while not st[i]:
        st[i] = True
        i = p[i] - 1
if cnt <= 1: cnt = 0
cnt += (sum(b) + 1) % 2
print(cnt)
