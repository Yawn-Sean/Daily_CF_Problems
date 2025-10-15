def solve():
    import sys

    n, m = map(int, input().split())
    # print(n, m)
    pos = [[] for _ in range(n + 1)]
    for i in range(1, m + 1):
        c, x = input().split()
        x = int(x)
        # print(c, x)
        if c == "+":
            pos[x].append(i)
        else:
            # print(len[pos[x]])
            if not pos[x]:
                pos[x].append(0)
            pos[x].append(i)

    for i in range(1, n + 1):
        if len(pos[i]) % 2 == 1:
            pos[i].append(m + 1)

    sum = [0] * (m + 2)

    for i in range(1, n + 1):
        for j in range(0, len(pos[i])):
            # print(i, pos[i][j])
            if j % 2 == 1:
                sum[pos[i][j]] -= 1
            else:
                sum[pos[i][j]] += 1

    lens = 0
    for i in range(1, m + 2):
        if sum[i - 1] > 0:
            lens += 1
        sum[i] += sum[i - 1]
    ans = []
    for i in range(1, n + 1):
        if not pos[i]:
            ans.append(i)
        else:
            num = 0
            for j in range(0, len(pos[i])):
                if j % 2 == 0:
                    num -= pos[i][j]
                else:
                    num += pos[i][j]
            if num == lens:
                ans.append(i)

    print(len(ans))
    print(" ".join(map(str, ans)))


if __name__ == "__main__":
    solve()
