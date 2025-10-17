'''
https://codeforces.com/gym/104852/submission/344131691
'''
# BFS + 两数之和
a = []
s = set()
def init():
    global a, s
    LIMIT = 10 ** 9
    a.append(0)
    s.add(0)
    i = 1
    for x in range(1, 10):
        for y in range(x):
            if y and y != x:
                a.append(y)
            a.append(x)
            while i < len(a):
                c = a[i] 
                i += 1
                s.add(c)
                if c * 10 + x <= LIMIT:
                    a.append(c * 10 + x)
                if y != x and c * 10 + y <= LIMIT:
                    a.append(c * 10 + y)

def solve(n: int) -> int:
    global a, s
    ans, dup = 0, 0
    for x in s:
        if x <= n and n - x in s:
            ans += 1
            if x != n - x:
                dup += 1
    return ans - dup // 2
