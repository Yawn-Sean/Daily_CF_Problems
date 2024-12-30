from collections import Counter
def main():
    n,q = map(int,input().split())
    a = list(map(int,input().split()))
    right = dict()
    c = Counter(a)
    for i in range(n):
        right[a[i]] = i
    l,r,mx = 0,0,0
    ans = 0
    for i in range(n):
        if i > r:
            ans += r - l + 1 - mx
            l,r = i,i
            mx = 0
        if right[a[i]] > r:
            r = right[a[i]]
        if c[a[i]] > mx:
            mx = c[a[i]]
    ans += r - l + 1 - mx
    print(ans)
if __name__ == '__main__':
    main()
