'''
b >= x:
    b -= x
    c -= 1
b < x:
    b += w - x
    c -= 1
    a -= 1
求a >= c的时间

b < x时， a和c都-1，没有贡献
b >= x时，a - c的值+1
要让a >= c, 需要让c减少 c - a次， 则b要减少 x * (c - a)，也就是b最大值，至少要达到x * (c - a)
b < x时每次增加 w - x,设cnt次后达到x * (c - a)
cnt * (w - x) + b = x * (c - a)
cnt = (x * (c - a) - b + w - x - 1) // (w - x)
ans = cnt + c - a 最后一次性操作c - a次
'''

a, b, w, x, c = RII()
if a >= c:
    print(0)
else:
    # cnt * (w - x) + b = x * (c - a)
    cnt = (x * (c - a) - b + w - x - 1) // (w - x)
    ans = cnt + c - a
    print(ans)