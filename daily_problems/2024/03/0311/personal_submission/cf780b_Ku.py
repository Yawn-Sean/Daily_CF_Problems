import math
n = int(input())
x = list(map(float,input().split(' ')))
v = list(map(float,input().split(' ')))
right = (max(x) - min(x)) / min(v)
left = 0
def check(mx):
    max_left = -math.inf
    min_right = math.inf
    for i,y in enumerate(x):
        le = y - v[i] * mx
        ri = y + v[i] * mx
        if le > max_left:
            max_left = le
        if ri < min_right:
            min_right = ri
    if max_left < min_right:
        return True
    else:
        return False
while left  +  10 ** (-7) < right:
    mid = (left + right) / 2
    if check(mid):
        right = mid
    else:
        left = mid
print(right)
