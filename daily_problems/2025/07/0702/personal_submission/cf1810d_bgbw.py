t=II()
for _ in range(t ):
    n=II()
    ans = []
    a = -1
    b = math.inf
    def f (a,b ,x ):
        if x <=a:
            return 1
        # x-=a
        return (x-a-1)//(a-b )+2
    for i in range(n):
        s=LII()
        if s[0]==1 :
            if s[3]!=1:
                c=(s[1]-s[2])*(s[3]-2)+s[1 ]+1
                d = (s[1] - s[2]) * (s[3] - 1) + s[1]
            else:
                c=1
                d=s[1]

            if   max(a,c )<=min(b,d):
                a=max(c,a)
                b=min(b,d )
                ans .append( 1 )
            else:
                ans.append(0)
        else:
           if f(s[1],s[2 ],a )==f(s[1 ],s[2 ],b ):
               ans.append(f(s[1],s[2], a ))
           else:
               ans .append(-1)
    print(' '.join(map(str,ans )))
