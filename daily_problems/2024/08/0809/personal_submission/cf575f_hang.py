#题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/08/0809/solution/cf575f.md
def main():
    n,x = map(int,input().split())
    l,r = x, x
    ans = 0
    for i in range(n):
        l2,r2 = map(int,input().split())
        if l > r2:
            ans += l - r2
            l,r = r2,l
        elif r < l2:
            ans += l2 - r
            l,r = r,l2
        else:
            l,r = max(l,l2),min(r,r2)
    print(ans)
main()