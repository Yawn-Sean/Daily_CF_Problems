def main():
    n = int(input())
    s = input()
    m = len(s)
    idx = -1
    for i in  range(m):
        if s[i] != s[0]:
            idx = i
            break
    if idx == -1:
        print(n)
        return
    ans = idx + (n - idx) * n
    a,b = 0, 0
    for i in range(idx, m):
        if s[i] == 'R':
            a += 1
        else:
            b += 1
    print(ans - a * b)
t = int(input())
for _ in range(t):
    main()
