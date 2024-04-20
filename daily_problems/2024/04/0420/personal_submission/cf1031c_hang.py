def main():
    a, b = map(int, input().split())
    l = 0
    r = 1000000
    while l < r:
        m = (l + r + 1) // 2
        if m * (m + 1) // 2 <= a + b:
            l = m
        else:
            r = m - 1
    q = [i for i in range(1, l + 1)]
    a_list, b_list = [], []
    while q:
        t = q.pop()
        if a >= t:
            a -= t
            a_list.append(t)
        else:
            b -= t
            b_list.append(t)

    print(len(a_list))
    print(*a_list)
    print(len(b_list))
    print(*b_list)

main()