a = LII()
b = LII()
c = [0] + LII()

ans = 0 

if a[0] > b[0]:
    ans += c[6]
elif a[0] < 0:
    ans += c[5]

if a[1] > b[1]: 
    ans += c[2]
elif a[1] < 0: 
    ans += c[1]

if a[2] > b[2]:
    ans += c[4]
elif a[2] < 0: 
    ans += c[3]

print(ans)
