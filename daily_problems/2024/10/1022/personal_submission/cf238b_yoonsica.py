'''
思路：
要求abs(mx_f - mn_f)最小
a中的任意两个数，分开放只会让f(i,j)变大或不变，因为h >= 0， 所以最大的两个数肯定放一组
最小值a[0] + a[1] 分开后是a[0] + a[1] + h,所以最小的两个数要么放一组，要么分开放，根据h判断
https://codeforces.com/contest/238/submission/287295044
'''
n, h = RII()
a = RILIST()
b = sorted(range(n), key=lambda x: a[x])
mx_f = a[b[-1]] + a[b[-2]]
mn_f = a[b[0]] + a[b[1]]
ans = mx_f - mn_f
if n == 2 or h == 0:
    print(ans)
    print(' '.join(map(str, [1] * n)))
else:
    # 分开放
    mn_f = mn(a[b[0]] + a[b[1]] + h, a[b[1]] + a[b[2]])
    mx_f = mx(mx_f, a[b[0]] + a[b[-1]] + h)
    if abs(mx_f - mn_f) < ans:
        print(abs(mx_f - mn_f))
        ans = [1]*n
        ans[b[0]] = 2
        print(' '.join(map(str, ans)))
    else:
        print(ans)
        print(' '.join(map(str, [1] * n)))
