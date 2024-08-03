INF = 10**10
def main():
    n = int(input())
    z = []
    for _ in range(n):
        z.append(list(map(int, input().split())))
    max_l = [-INF] * n
    min_r = [INF] * n
    for i in range(n - 1):
        max_l[i + 1] = max(max_l[i], z[i][0])
        min_r[i + 1] = min(min_r[i], z[i][1])
    s_mx_l = -INF
    s_mn_r = INF
    ans = 0
    for i in range(n - 1, -1, -1):
        ans = max(ans, min(min_r[i], s_mn_r) - max(max_l[i], s_mx_l))
        s_mx_l = max(s_mx_l, z[i][0])
        s_mn_r = min(s_mn_r, z[i][1])
    print(ans)
main()