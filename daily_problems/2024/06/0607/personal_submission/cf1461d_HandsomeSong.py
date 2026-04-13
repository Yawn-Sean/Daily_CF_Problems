def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def I():
    return input().strip()
    
t=II()
for _ in range(t):
    n,q=MII()
    a=LII()
    sums=set()
    def f(arr,mn,mx):
        s=sum(arr)
        sums.add(s)
        if mn==mx:
            return
        mid=(mn+mx)//2
        left=[]
        right=[]
        left_max=-1
        right_min=10**18
        for x in arr:
            if x <= mid:
                left.append(x)
                left_max = max(left_max, x)
            else:
                right.append(x)
                right_min = min(right_min, x)
        if left:
            f(left,mn,left_max)
        if right:
            f(right,right_min,mx)
    f(a,min(a),max(a))
    for _ in range(q):
        s=II()
        print('Yes' if s in sums else 'No') 