'''
n张白纸，m个回合，数字范围[1, c]
每回合给一个数字，判断该数字放哪个白纸，可以覆盖原数字，目标使得白纸数字递增
'''

n, m, c = RII()
a = [0]*(n + 1)
cnt = n
while cnt:
    x = RI()
    if x <= c // 2:
        for i in range(1, n + 1):
            if a[i] == 0 or a[i] > x:
                cnt -= int(a[i] == 0)
                a[i] = x
                print(i, flush=True)
                break
    else:
        for i in range(n, 0, -1):
            if a[i] == 0 or a[i] < x:
                cnt -= int(a[i] == 0)
                a[i] = x
                print(i, flush=True)
                break