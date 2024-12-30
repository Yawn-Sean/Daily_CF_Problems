def main():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    l,r = 0,m

    def ok(mid):
        pre = 0
        for x in a:
            if x == pre:
                continue
            elif x < pre:
                t = pre - x
                if t > mid:
                    return False
            else:
                t = m - (x - pre)
                if t > mid:
                    pre = x

        return True

    while l < r:
        mid = (l+r)//2
        if ok(mid): r = mid
        else: l = mid+1
   
    print(l)
main()