# https://codeforces.com/problemset/problem/863/C
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 预测两轮的得分
# 记录步数，一旦出现一个已经出现的，则是循环节了
def get(x, y):
    if x == y:
        return 0, 0
    elif (x + 3 - y) % 3 == 1:
        return 1, 0
    else:
        return 0, 1

k, a, b = MII()
a -= 1
b -= 1
alice = [LGMI() for _ in range(3)]
bob = [LGMI() for _ in range(3)]
mp = dict()

ans1, ans2 = [0], [0]
for i in range(1, k + 1):
    if (a, b) in mp: # 出现循环了
        pre = mp[(a, b)]
        t = i - pre # 循环节
        # 三部分：之前 + 循环节 + 剩余
        cycle, last = divmod(k - i + 1, t)
        res1 = ans1[-1] + (ans1[i - 1] - ans1[pre - 1]) * cycle + ans1[pre + last - 1] - ans1[pre - 1]
        res2 = ans2[-1] + (ans2[i - 1] - ans2[pre - 1]) * cycle + ans2[pre + last - 1] - ans2[pre - 1]
        print(res1, res2)
        break

    t = get(a, b)
    ans1.append(ans1[-1] + t[0]) # 前缀和，直接用数组记录太妙了，还想着用字典记录。。。
    ans2.append(ans2[-1] + t[1])
    mp[(a, b)] = i
    a, b = alice[a][b], bob[a][b]
else:
    print(ans1[-1], ans2[-1])