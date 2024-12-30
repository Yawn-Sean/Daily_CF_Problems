def main():
    n = int(input())
    def slove(a,b):
        l,r = 1, 10**6
        while l <= r:
            m = (l+r)//2
            if m ** 3 > a * b:
                r = m - 1
            else:
                l = m + 1
        if r ** 3 == a * b and a %r == 0 and  b % r == 0: 
            return 'Yes'
        else:
            return 'No'
    ans = []
    for _ in range(n):
        a,b = map(int,input().split())
        ans.append(slove(a,b))
    print(*ans,sep='\n')
main()