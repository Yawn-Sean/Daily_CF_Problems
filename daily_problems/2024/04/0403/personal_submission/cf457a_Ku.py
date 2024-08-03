a = input()
b = input()
n, m = len(a), len(b)
li1, li2 = [0] * n, [0] * m

for i,x in enumerate(a):
    if x == '1':
        li1[i] = 1
for i in range(n-2):
    if li1[i] >= 1:
        li1[i+1] += li1[i]
        li1[i+2] += li1[i]
        li1[i] = 0

for i,x in enumerate(b):
    if x == '1':
        li2[i] = 1

for i in range(m-2):
    if li2[i] >= 1:
        li2[i+1] += li2[i]
        li2[i+2] += li2[i]
        li2[i] = 0

q = 2 / (pow(5,0.5) + 1)
li1.insert(0,0)
li2.insert(0,0)
k1 = li1[-2]
k2 = li2[-2]
b_ = li2[-1] - li1[-1]
#opt： k1*x + b1 > k2*x + b2 其中x = (5^0.5+1)/2
if b_ == 0:
    if k1 > k2:
        print(">")
    elif k1 == k2:
        print('=')
    else:
        print("<")
elif b_ < 0:
    t = (k1-k2) /  (b_)
    if t < q:
        print('>')
    elif t == q:
        print('=')
    else:
        print('<')
else:
    t = (k1-k2) /  (b_)
    if t < q:
        print('<')
    elif t == q:
        print('=')
    else:
        print('>')
