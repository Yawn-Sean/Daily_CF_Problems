# Submission link: https://codeforces.com/contest/1028/submission/304784832
def main():
    n = II()
    mod = 10 ** 9 + 7

    stl = SortedList()

    l, r = 0, 10 ** 9
    stl.add(l)
    stl.add(r)

    v = 0
    for _ in range(n):
        op, x = LI()
        x = int(x)
        
        if op[1] == 'D':
            stl.add(x)
        else:
            pos = stl.bisect_left(x)
            if l < x < r:
                v += 1
            if l <= x <= r:
                stl.pop(pos)
            else:
                exit(print(0))
            l = stl[pos - 1]
            r = stl[pos]

    ans = 1
    for x in stl:
        if l < x < r:
            ans += 1

    print(ans * pow(2, v, mod) % mod)