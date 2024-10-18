"""
数论题，学习学习！！

"""
#python代码：
a, b, mod = list(map(int, input().split()))

for i in range(min(mod, a + 1)):
    rem = (i * pow(10, 9)) % mod
    if mod - rem > b and rem != 0:
        print(1, str(i).zfill(9))
        break
else:
    print(2)
