'''
https://codeforces.com/contest/1138/submission/269534950
1138B
2024/7/9 Y1
1800
math
'''

from collections import Counter

def init():
    n = int(input())
    s1 = input()
    s2 = input()
    return [int(x) | int(y) << 1 for x, y in zip(s1, s2)]

# assume b <= c
def calc(a, b, c, d):
    a1, b1, c1, d1 = 0, 0, 0, 0

    if c == 0: # !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if d & 1:
            return -1, 0, 0, 0
        else:
            return a >> 1, 0, 0, d >> 1
        
    if b + d < c:
        b1, c1, d1 = b, c - b - d, d
        if a < c1:
            a1 = -1
        else:
            a1 = a - c1 >> 1
    else:
        x = c - b
        if d - x & 1:
            # move 1 from c2 to c1, in such case, a must be odd
            x -= 1
            a1, b1, c1, d1 = a >> 1, b, 1, d + x >> 1
        else:
            # in this case, as d - (c - b) is even, so a must be even
            # d1 = (d - x) / 2 + x = (d + x) / 2
            a1, b1, c1, d1 = a >> 1, b, 0, d + x >> 1
    return a1, b1, c1, d1
            

def solve(arr: list[int]):
    cn = Counter(arr)
    a, b, c, d = cn[0], cn[1], cn[2], cn[3]

    a1, b1, c1, d1 = 0, 0, 0, 0
    if b > c:
        a2, c2, b2, d2 = calc(a, c, b, d) # !!
        if a2 < 0: # !!!!!!!!!
            return [-1]
        a1, b1, c1, d1 = a - a2, b - b2, c - c2, d - d2
    else:
        a1, b1, c1, d1 = calc(a, b, c, d)
    if a1 < 0:
        return [-1]
    result = [a1, b1, c1, d1]
    
    ans = []
    for i, x in enumerate(arr):
        if result[x]:
            result[x] -= 1
            ans.append(i + 1)
    return ans

if __name__ == '__main__':
    a = init()
    ans = solve(a)
    print(*ans)
