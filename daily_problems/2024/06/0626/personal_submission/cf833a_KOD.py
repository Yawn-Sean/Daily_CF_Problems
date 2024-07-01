times = 0  
if not times:
    times = ix()
for _ in range(times):
    a, b = il()
    t = round(pow(a*b,1/3))
    if a * b == t**3 and a%t==b%t==0:
        py()
    else: pn()
