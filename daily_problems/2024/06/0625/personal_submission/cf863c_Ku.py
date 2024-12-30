k,a,b = RII()
A,B = [],[]
for _ in range(3):
    x = RLIST()
    A.append(x)
for _ in range(3):
    x = RLIST()
    B.append(x)
def judge(a,b):
    if a == b:
        return -1
    if a == 1 and b == 3:
        return 1
    if a == 3 and b == 1:
        return 0
    if a > b:
        return 1
    if a < b:
        return 0
s1,s2 = 0, 0
seen = set()
dic = Counter()
cnt = 0
while cnt < k:
    #print(a, b)
    if (a,b) in seen:
        round = cnt  - dic[(a,b)]
        #print(round)
        #print(cnt)
        break
    seen.add((a,b))
    dic[(a, b)] = cnt
    cnt += 1
    if judge(a, b) > 0:
        s1 += 1
    elif judge(a, b) == 0:
        s2 += 1
    a, b = A[a-1][b-1], B[a-1][b-1]
#print('s1',s1,s2)
if cnt == k:
    ans = [str(s1),str(s2)]
    print(' '.join(ans))
else:
    s3,s4 = 0, 0
    for _ in range(round):
        if judge(a,b) > 0:
            s3 += 1
        elif judge(a,b) == 0:
            s4 += 1
        a, b = A[a-1][b-1], B[a-1][b-1]
    #print(s3,s4)
    left = k - cnt
    s1 += (left // round) * s3
    s2 += (left // round) * s4
    for _ in range(left % round):
        if judge(a, b) > 0:
            s1 += 1
        elif judge(a,b) == 0:
            s2 += 1
        a, b = A[a - 1][b - 1], B[a - 1][b - 1]
    ans = [str(s1), str(s2)]
    print(' '.join(ans))

