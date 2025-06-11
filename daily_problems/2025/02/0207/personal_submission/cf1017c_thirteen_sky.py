import math

def solve():
    n = int(input())
    if n == 0:
        print()
        return
    if n == 1:
        print(1)
        return
    if n == 2:
        print("2 1")
        return
    if n == 3:
        print("3 2 1")
        return
    if n == 4:
        print("3 4 1 2")
        return
        
    k = math.ceil(math.sqrt(n))
    c = math.ceil(n / k)
    permutation = []
    for i in range(1, k + 1):
        start_num = (k - i) * c + 1
        end_num = min((k - i + 1) * c, n)
        for j in range(start_num, end_num + 1):
            permutation.append(j)
            
    print(*(permutation))

if __name__ == '__main__':
    solve()
