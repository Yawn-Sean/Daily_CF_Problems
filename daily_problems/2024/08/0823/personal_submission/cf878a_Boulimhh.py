"""
今天又是学习的一题， 学习一下位运算（弱项）。 a & b = (a ^ b) ^ (a | b)
"""
#python代码：
xor, ro = 0, 1023
for _ in range(int(input())):
    op, x = input().split()
    x = int(x)
    if op == '&':
        xor &= x
        ro &= x
    elif op == '^':
        xor ^= x
        ro ^= x
    else:
        xor |= x
        ro |= x
print(2)
print('&', xor ^ ro)
print('^', xor)
