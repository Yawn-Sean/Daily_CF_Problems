# 2024.04.11
# 等价代换！
def main():
    def delete(v0,v1):
        while v0 and used[v0[-1]]: v0.pop()
        while v1 and used[v1[-1]]: v1.pop()
    n = int(input())
    sx,sy = map(int,input().split())
    g = (sx + sy) & 1
    used = [0] * (n + 1)  
    v0,v1 = [],[]
    for i in range(1,n + 1):
        x,y = map(int,input().split())
        if ((x + y) & 1) ^ g == 1:
            v1.append(i)
        else:
            v0.append(i)
    if len(v0) >= len(v1):
        print('First',flush=True)
        for i in range(1, n + 1):
            delete(v0,v1)
            if i & 1:
                if v1:
                    print(v1.pop(), flush=True)
                else:
                    print(v0.pop(), flush=True)
            else:
                used[int(input())] = 1
    else:
        print('Second',flush=True)
        for i in range(1, n + 1):
            delete(v0,v1)
            if i & 1 == 0:
                if v0:
                    print(v0.pop(), flush=True)
                else:
                    print(v1.pop(), flush=True)
            else:
                used[int(input())] = 1
    
T = int(input())
for _ in range(T):
    main()
