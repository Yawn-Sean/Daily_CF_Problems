from collections import Counter
def main():
    n = int(input())
    a = list(map(int, input().split()))
    tmp = []
    cnt = Counter(a)
    for k,v in cnt.items():
        if v >= 4:
            print(k,k,k,k)
            return
        if v >= 2:
            tmp.append(k)
    tmp.sort()
    x,y = 1,0
    for i in range(1, len(tmp)):
        nx,ny = tmp[i], tmp[i-1]
        if nx * y < ny * x:
            x,y = nx,ny
    print(x,x,y,y)
t = int(input())
for _ in range(t):
    main()