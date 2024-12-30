def main():
    n = int(input())
    a = list(map(int, input().split()))
    M = max(a) + 10
    pre = [0] * M
    for x in a: pre[x] += 1
    for i in range(1, M): pre[i] += pre[i - 1]
    ans = [0] * M
    for i in range(1, M):
        for j in range(i, M, i):
            # [j,j+i-1]范围内都乘以 j
            ans[i] += j * (pre[min(M-1,j + i - 1)] - pre[j-1])
       
    print(max(ans[x] for x in a))
main()