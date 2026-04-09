import bisect
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
m=II()
b=LII()
a.sort()
b.sort()
candidates=set()
for x in a:
    candidates.add(x)
    candidates.add(x-1)
for x in b:
    candidates.add(x)
    candidates.add(x-1)
max_diff=-10**18
best_a, best_b=0, 0
for d in candidates:
    cnt_a=bisect.bisect_right(a, d)
    cnt_b=bisect.bisect_right(b, d)
    score_a=2*cnt_a+3*(n-cnt_a)
    score_b=2*cnt_b+3*(m-cnt_b)
    diff=score_a-score_b
    if diff > max_diff or (diff == max_diff and score_a > best_a):
        max_diff=diff
        best_a=score_a
        best_b=score_b
print(f"{best_a}:{best_b}")