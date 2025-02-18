import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
s = input()

# 开始觉得要保存这么多状态需要空间太多了，然后把查询代码放到每次q里就TLE了，没想到正解就是保存状态。。
saved = [[0] * (n + 1) for _ in range(26)]
for ci in range(26):
    c = chr(ci + ord('a'))
    for mi in range(n + 1):
        m = mi
        i = j = ans = 0
        while j < n:
            if s[j] != c:
                if m:
                    m -= 1
                else:
                    while i < j and s[i] == c:
                        i += 1
                    i += 1
            if ans < j - i + 1:
                ans = j - i + 1
            j += 1
        saved[ci][mi] = ans
# print(saved)
q = int(input())
outs = []
for _ in range(q):
    m, c = input().split()
    outs.append(saved[ord(c) - ord('a')][int(m)])
print('\n'.join(map(str, outs)))
