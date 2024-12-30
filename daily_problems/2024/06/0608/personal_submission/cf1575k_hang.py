def main():
    n,m,k,r,c = map(int,input().split())
    ax,ay,bx,by = map(int,input().split())
    mod = 10**9+7
    print(pow(k, n * m - r * c * (ax != bx or ay != by), mod))

main()