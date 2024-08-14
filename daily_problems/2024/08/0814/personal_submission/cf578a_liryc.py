'''
578A
2024/8/14 Y1
1700
计算几何+分类讨论
'''

def checkRight(a: int, b: int) -> float:
    k = (a + b) // (b + b)
    return (a + b) / (k + k)

def checkLeft(a: int, b: int) -> float:
    k = (a - b) // (b + b)
    if k < 1:
        return -1
    return (a - b) / (k + k)

if __name__ == '__main__':
    a, b = map(int, input().split())
    if b > a:
        print(-1)
    else:
        x = checkRight(a, b)
        y = checkLeft(a, b)
        if y > 0 and y < x:
            print(y)
        else:
            print(x)
