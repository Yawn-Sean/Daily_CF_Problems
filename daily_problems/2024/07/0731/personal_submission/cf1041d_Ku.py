n,h = RII()
intervals = []

def merge(intervals) :
    intervals = sorted(intervals, key=lambda x: x[0])
    max_r = -inf
    ans = []
    for i, (left, right) in enumerate(intervals):
        if left > max_r:
            if max_r >= 0:
                ans.append([left_, max_r])
            left_ = left
        max_r = max(right, max_r)
        if i == len(intervals) - 1:
            ans.append([left_, max_r])
    return ans
for _ in range(n):
    x1,x2 = RII()
    intervals.append([x1,x2])
ans = merge(intervals)
n = len(ans)
d = [0]
x = ans[0][1] - ans[0][0]
leng = [x]
for i in range(1,n):
    d.append(ans[i][0] - ans[i-1][1])
    leng.append(ans[i][1] - ans[i][0])
s1 = list(accumulate(d,initial=0))
s2 = list(accumulate(leng,initial=0))
#print(s1)
#print(s2)
if s1[-1] < h:
    res = s2[-1] + h
else:
    res = -inf
    for i in range(len(s1)-1 ,-1,-1):
        if s1[i] < h:
            res = max(res,s2[i] + h)
            break
        j = bisect.bisect_right(s1,s1[i] - h)
        cnt = s2[i] - s2[j-1] + h
        res = max(res,cnt)
print(res)
