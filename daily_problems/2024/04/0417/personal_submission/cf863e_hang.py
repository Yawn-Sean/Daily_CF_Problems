from functools import cmp_to_key
def cmp(a, b):
    if a[0] == b[0]:
        return b[1] - a[1]
    return a[0] - b[0]
def main():
    n = int(input())
    p = []
    for i in range(1, n + 1):
        l,r = map(int, input().split())
        p.append([l,r,i])
    p.sort(key=cmp_to_key(cmp))
    
    for i,(l,r,idx) in enumerate(p):
        if i > 0 and p[i-1][1] >=r:
            print(idx)
            return
        if i > 1 and l <= p[i-2][1] + 1:
            print(p[i-1][-1])
            return
    print(-1)
        
main()