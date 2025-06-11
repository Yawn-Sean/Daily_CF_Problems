def main():
    n,s = map(int,input().split())
    d = [0] * n
    for i in range(n-1):
        a,b = map(lambda x: int(x) - 1 ,input().split())
        d[a] += 1
        d[b] += 1
    print(2 *s /d.count(1))
main()