if __name__ == '__main__':
    n, m = list(map(int, input().split(' ')))
    records = []
    for i in range(m):
        records.append(list(map(int, input().split(' '))))
    ans = max(records[0][1] + records[0][0] - 1, records[-1][1] + n - records[-1][0])
    for i in range(m - 1):
        d1, h1 = records[i]
        d2, h2 = records[i + 1]
        if abs(h2 - h1) > d2 - d1:
            print("IMPOSSIBLE")
            exit(0)
        ans = max(ans, max(h1, h2) + (d2 - d1 - abs(h2 - h1)) // 2)
    print(ans)