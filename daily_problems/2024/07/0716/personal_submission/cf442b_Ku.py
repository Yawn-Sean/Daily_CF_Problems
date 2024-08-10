n = RI()
a = RLIST2()
a.sort(reverse=True)
#x*p0 + (1-x)*p1 > p1 ——> x(p0-p1) > 0
p0,p1 = 1,0
ans = 0
for i,x in enumerate(a):
    if p0 < p1:break
    p1 = p1 * (1-x) + x * p0
    ans = max(ans,p1)
    p0 *= (1-x)
print(ans)
