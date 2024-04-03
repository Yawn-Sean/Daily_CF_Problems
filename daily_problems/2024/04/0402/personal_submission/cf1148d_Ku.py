n = int(input())
x = []
y = []
for i in range(n):
    a,b = map(int,input().split())
    x.append(a)
    y.append(b)
ans = 0
#第一种情况好数队长度，必须满足x[i] < y[i]
good_one = [i for i in range(n) if x[i] < y[i]]

#第二种情况好数队长度，必须满足x[i] > y[i]
good_two = [i for i in range(n) if x[i] > y[i]]

if len(good_one) > len(good_two):
    print(len(good_one))
    #按照b降序排列一定是满足要求的
    good_one.sort(key = lambda i:-y[i])
    print(' '.join(str(t+1) for t in good_one))
else:
    print(len(good_two))
    #按照a升序排列一定满足要求
    good_two.sort(key = lambda i:x[i])
    print(' '.join(str(t+1) for t in good_two))
