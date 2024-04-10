n,m = MII()
a = sorted(LII())
b = sorted(LII())
res = inf
sa = list(accumulate(a , initial=0))
sb = list(accumulate(b , initial=0))
for i in range(n):    
    j = bisect.bisect_right(b,a[i])            
    res = min(res,(sb[-1]-sb[j])-(m-j)*a[i]+(i+1)*a[i]-sa[i+1])   
for i in range(m):        
    j = bisect.bisect_left(a,b[i])       
    res = min(res,(sb[-1]-sb[i])-(m-i)*b[i]+j*b[i]-sa[j])
print(res)
