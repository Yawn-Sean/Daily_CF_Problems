'''
https://codeforces.com/gym/106020/submission/380108525
two pointers
'''
# 0* + 1 + 1
def solve1(n: int, a: list[int]) -> int:
    ans, l, r, c0, c1 = 0, 0, 0, 0, 0
    for i, x in enumerate(a):
        if x == 0:
            c0 += 1
        elif x == 1:
            c1 += 1
            while c1 > 2:
                if a[r] == 0:
                    c0 -= 1
                else:
                    c1 -= 1
                r += 1
                l = r
        else:
            l = r = i + 1
            c0 = c1 = 0
        if c0 and c1 == 2:
            while a[r] == 0 and c0 > 1:
                c0 -= 1
                r += 1
            ans += r - l + 1
    return ans

# 0* + 1 + 2
def solve2(n: int, a: list[int]) -> int:
    ans, l, r, c0, c1, c2 = 0, 0, 0, 0, 0, 0
    for i, x in enumerate(a):
        if x == 0:
            c0 += 1
        elif x == 1:
            c1 += 1
        elif x == 2:
            c2 += 1
        else:
            c0 = c1 = c2 = 0
            l = r = i + 1
        while c1 > 1 or c2 > 1:
            if a[r] == 0:
                c0 -= 1
            elif a[r] == 1:
                c1 -= 1
            else:
                c2 -= 1
            r += 1
            l = r
        if c0 and c1 == c2 == 1:
            while a[r] == 0 and c0 > 1:
                c0 -= 1
                r += 1
            ans += r - l + 1
    return ans

# ans = solve1(*args) + solve2(*args)
