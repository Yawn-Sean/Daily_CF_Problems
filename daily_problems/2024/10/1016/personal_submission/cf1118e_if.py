def check():
    n, k = map(int, input().split())
    if n > k * (k - 1):
        print("NO")
    else:
        print("YES")
        for i in range(1, k):
            for j in range(i + 1, k + 1):
                print(i, j)
                n -= 1
                if not n :
                    return
                print(j, i)
                n -= 1
                if not n :
                    return
                    
check()
