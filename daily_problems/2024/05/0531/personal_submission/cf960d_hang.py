import math
def main():
    q = int(input())
    d = [0] * 64

    for _ in range(q):
        z = list(map(int,input().split()))
        if len(z) == 2:
            t,x = z[0], z[1]
            deep = int(math.log(x,2))
            cur = (x - (1 << deep) + d[deep]) % (1 << deep)
            ans = []
            for i in range(deep, -1, -1):
                ans.append((1 << i) + (cur - d[i]) % (1 << i) )
                cur //= 2
            print(*ans)

        else:
            t,x,k = z[0], z[1], z[2]
            deep = int(math.log(x,2))
            if t == 2:
                for i in range(deep, 64):
                    d[i] += k
                    d[i] %= (1 << i)
                    k %= (1 << i)
                    k *= 2
            else:
                d[deep] += k
                d[deep] %= (1 << deep)
if __name__ == '__main__':
    main()