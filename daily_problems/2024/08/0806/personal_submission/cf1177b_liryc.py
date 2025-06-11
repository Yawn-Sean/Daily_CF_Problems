'''
https://codeforces.com/contest/1177/submission/274622756
1177B
2024/8/6 Y1
1800
binary search: find the smallest n such that getTotalLength(n) >= k
'''

# 求1-n拼接的总长度
def getTotalLength(n: int) -> int:
    totalLength, b = 0, 1
    while n >= b:
        totalLength += n - b + 1
        b *= 10
    return totalLength

if __name__ == '__main__':
    k = int(input())
    l, r = 1, k
    while l < r:
        m = l + r >> 1
        if getTotalLength(m) < k:
            l = m + 1
        else:
            r = m
    s, d = str(l), getTotalLength(l)
    print(s[len(s) - d + k - 1])

