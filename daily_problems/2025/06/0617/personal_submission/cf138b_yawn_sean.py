# Submission link: https://codeforces.com/problemset/submission/138/324702593
def main():
    s = I()
    cnt1 = [0] * 10

    for c in s:
        cnt1[int(c)] += 1

    cnt2 = cnt1[:]

    val = fmin(cnt1[0], cnt2[0])
    chosen = -1

    for i in range(1, 10):
        if cnt1[i] and cnt2[10 - i]:
            cnt1[i] -= 1
            cnt2[10 - i] -= 1
            
            cur = 1
            for x in range(10):
                cur += fmin(cnt1[x], cnt2[9 - x])
            
            cur += fmin(cnt1[0] - fmin(cnt1[0], cnt2[9]), cnt2[0] - fmin(cnt2[0], cnt1[9]))
            
            if cur > val:
                val = cur
                chosen = i
            
            cnt1[i] += 1
            cnt2[10 - i] += 1

    v1 = []
    v2 = []

    if chosen != -1:
        cnt1[chosen] -= 1
        cnt2[10 - chosen] -= 1
        
        v1.append(chosen)
        v2.append(10 - chosen)
        
        for i in range(10):
            while cnt1[i] and cnt2[9 - i]:
                v1.append(i)
                v2.append(9 - i)
                cnt1[i] -= 1
                cnt2[9 - i] -= 1

    x = fmin(cnt1[0], cnt2[0])
    cnt1[0] -= x
    cnt2[0] -= x

    for i in range(10):
        while cnt1[i]:
            v1.append(i)
            cnt1[i] -= 1

    for i in range(10):
        while cnt2[i]:
            v2.append(i)
            cnt2[i] -= 1

    v1.reverse()
    v2.reverse()

    for _ in range(x):
        v1.append(0)
        v2.append(0)

    print(''.join(map(str, v1)))
    print(''.join(map(str, v2)))