"""
OK，七夕又学新知识点了。

这题没想到可以用 0 结尾数组 和 1 结尾数组来分别处理， 有点子奇妙的。

"""
#python代码：
s = input()
zero = []
one = []
for i, c in enumerate(s):
    if c == '0':
        if one:
            t = one.pop()
            t.append(i + 1)
            zero.append(t)
        else:
            zero.append([i + 1])
    else:
        if zero:
            t = zero.pop()
            t.append(i + 1)
            one.append(t)
        else:
            print(-1)
            exit()
if one:
    print(-1)
else:
    print(len(zero))
    for x in zero:
        print(len(x), *x)
