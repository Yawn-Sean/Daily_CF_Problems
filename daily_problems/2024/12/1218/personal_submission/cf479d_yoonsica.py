'''
测量x y两个距离，最多添加两个刻度
'''

n, l, x, y = RII()
a = RILIST()

ok_x = ok_y = False
d = {0}
for j in a:
    if j - x in d:
        ok_x = True
    if j - y in d:
        ok_y = True
    if ok_x and ok_y:
        break
    d.add(j)

if ok_x and ok_y:
    print(0)
else:
    if ok_x or ok_y:
        print(1)
        if ok_x:
            print(y)
        else:
            print(x)
    else:
        # 看看能否只添加一个
        d = set(a)
        for i in a:
            if i + x <= l and (i + x - y in d or i + x + y in d):
                print(1)
                print(i + x)
                break
            if i - x >= 0 and (i - x + y in d or i - x - y in d):
                print(1)
                print(i - x)
                break
        else:
            print(2)
            print(x, y)
        