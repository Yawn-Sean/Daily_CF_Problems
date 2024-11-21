#题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/11/1119/solution/cf201b.md
#凸函数
def main():
    n,m = map(int,input().split())
    g = []
    a,b1,b2,c = 0,0,0,0
    for i in range(n):
        t = list(map(int,input().split()))
        x = 4 * i + 2
        for j in range(m):
            a += t[j]
            y = 4 * j + 2
            b1 += 2 * t[j] * x
            b2 += 2 * t[j] * y
            c += t[j] * (x * x + y * y)
    def f(a,b):
        if a == 0: return 0
        x = b // (a * 8)
        return x if abs(x * a * 8 - b) <= abs((x + 1) * a * 8 - b) else x + 1
    x = f(a, b1) * 4
    y = f(a, b2) * 4

    print(a * (x * x + y * y) - b1 * x - b2 * y + c)
    print(x // 4, y // 4)
            
    


main()