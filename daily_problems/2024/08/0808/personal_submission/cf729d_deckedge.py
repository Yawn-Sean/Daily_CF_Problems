def sovle():
    n, a, b, k = MII()
    s = I()
    cur, va = 0, []
    for i in range(n):
        if s[i] == '0':
            cur += 1
            if cur == b:
                va.append(i + 1)
                cur = 0
        else:
            cur = 0
    for _ in range(a - 1):
        va.pop()
    print(len(va))
    print(*(i for i in va))
def main():
    t = 1
    while t:
        sovle()
        t -= 1
main()