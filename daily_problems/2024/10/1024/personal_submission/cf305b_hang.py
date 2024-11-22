def main():
    p,q = map(int,input().split())
    n = int(input())
    a = list(map(int,input().split()))
    
    def f(idx):
        if idx == n:
            return (0, 1)
        x,y = f(idx + 1)
        return (y,x + a[idx] * y)
    y,x = f(0)
    if x * q == p * y:
        print("YES")
    else:
        print("NO")
main()