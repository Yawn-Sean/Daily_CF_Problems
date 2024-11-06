MAXN = int(5e6) + 10

class Node:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

res = []

k = int(input())
sum_ = 0
p = int(math.sqrt(k))
i = 1

for i in range(1, min(2000000, p) + 1):
    tot = i * (i + 1) * (2 * i + 1) // 6
    add = i * (i + 1) // 2
    if k >= tot and (k - tot) % add == 0:
        x_val = i
        y_val = (k - tot) // add + i
        res.append(Node(x_val, y_val))
        sum_ += 1

if sum_ > 1 and res[sum_ - 1].y == res[sum_ - 2].x and res[sum_ - 1].x == res[sum_ - 2].y:
    print((sum_ - 1) * 2)
    for i in range(sum_):
        print(res[i].x, res[i].y)
    for i in range(sum_ - 3, -1, -1):
        print(res[i].y, res[i].x)
else:
    if res[sum_ - 1].x == res[sum_ - 1].y:
        print(sum_ * 2 - 1)
        for i in range(sum_ - 1):
            print(res[i].x, res[i].y)
        for i in range(sum_ - 1, -1, -1):
            print(res[i].y, res[i].x)
    else:
        print(sum_ * 2)
        for i in range(sum_):
            print(res[i].x, res[i].y)
        for i in range(sum_ - 1, -1, -1):
            print(res[i].y, res[i].x)
