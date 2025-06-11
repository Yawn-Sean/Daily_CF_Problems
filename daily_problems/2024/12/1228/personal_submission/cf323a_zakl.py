def solve():
    k=int(input())
    if k%2:
        print(-1)
        return 
    def ff(k,t):
        ret=''
        for i in range(k//2):
            if i%2:
                ret+='bb' if t else 'ww'
            else:
                ret+='ww' if t else 'bb'
        return ret
        
    for i in range(k):
        for j in range(k):
            x=j
            if i%4!=1 and i%4!=0:
                x=j+1
            print(ff(k,x%2))
        if i==k-1: return
        print()
solve()
