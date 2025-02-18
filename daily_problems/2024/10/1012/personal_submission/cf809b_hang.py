def main():
    n,k = map(int,input().split())
    def q(x,y):
        print(1,x,y, flush=True)
        return True if input()=='TAK' else False
    def search(l,r):
        while l < r:
            m = (l+r)//2
            if q(m,m+1):
                r = m
            else:
                l = m+1
        return r
    x = search(1,n)
    y = search(1,x-1)
    if y == 0 or not q(y,x):
        y = search(x+1,n)
    print(2,y,x, flush=True)

main()