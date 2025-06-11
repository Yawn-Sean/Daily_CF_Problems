w,t = map(int,input().split())
a = list(map(int,input().split()))
a=[0]+a+[0]
l=0
r = sum(a)
b = [0] * (len(a))
b[0] = 10 ** 9 + 1
a[-1] = 10 ** 9 + 1
ll = 0
for i in range(1,w+1):
    while i - ll > t:
        ll += 1
    while ll < i and a[i] > b[i]:
        s = min(a[i]-b[i], b[ll])
        b[i] += s
        b[ll] -= s
        if b[ll] == 0:
            ll += 1
print(b[-1])
