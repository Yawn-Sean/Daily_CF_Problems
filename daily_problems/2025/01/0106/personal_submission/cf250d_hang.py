def main():
    n,m,a,b = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    L = list(map(int, input().split()))
    def dist(i,j):
        return (a *a + A[i] * A[i]) ** 0.5 + ((b-a) * (b - a) + (A[i] - B[j]) * (A[i] - B[j])) ** 0.5 + L[j]
    ans  = 10 ** 9
    idx1,idx2 = -1, -1
    cur = 0
    for i in range(m):
        while cur < n - 1 and dist(cur, i) > dist(cur + 1, i):
            cur += 1
        
        tmp = dist(cur, i)
        if tmp < ans:
            ans = tmp
            idx1 = cur
            idx2 = i
    print(idx1 + 1, idx2 + 1)

main()