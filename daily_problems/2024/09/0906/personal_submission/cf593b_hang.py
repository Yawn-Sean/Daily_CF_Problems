def main():
    n = int(input())
    x1,x2 = map(int,input().split())
    ks = []
    bs = []
    for _ in range(n):
        k,b = map(int,input().split())
        ks.append(k)
        bs.append(b)
    a = []
    for k,b in zip(ks,bs):
        a.append((k*x1+b, k*x2+b))

    a.sort()
    for i in range(1, n):
        if a[i][1] < a[i-1][1]:
            print("YES")
            return
    print("NO")
main()