import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 想着去一个一个匹配1，2，3，4位的字符串，肯定超时呀
# 看村长题解了，对于每个位置，预处理前缀0，然后判断即可
t = II()
ans = []
for _ in range(t):
    s = I()
    n = len(s)

    pref_zero = [0]
    for c in s:
        if c == '0': pref_zero.append(pref_zero[-1] + 1)
        else: pref_zero.append(0)
    
    res = 0
    for i in range(n):
        cur = 0
        for j in range(i, max(0, i - 18) - 1, -1): # 从右边开始走，这样cur的值才是确定的
            if s[j] == '1':
                cur |= 1 << i - j
                if pref_zero[j] + i - j + 1 >= cur:
                    res += 1
    ans.append(res)
print(*ans, sep='\n')