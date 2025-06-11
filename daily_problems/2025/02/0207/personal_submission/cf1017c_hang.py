import  math
# Dilworth 定理
def main():
    n = int(input()) 
    if n == 1:
        print(1)
        return
    ans = []
    v = math.isqrt(n)
    for i in range(1, n // v + 3):
        for j in range(i * v,(i-1) * v,-1):
            if 1 <= j <= n:
                ans.append(j)
    print(' '.join(map(str, ans)))

main()