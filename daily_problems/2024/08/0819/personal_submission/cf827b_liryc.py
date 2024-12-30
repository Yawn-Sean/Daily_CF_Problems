'''
https://codeforces.com/contest/827/submission/277206660
CF827B
2024/8/19 Y1
1800
Tree Contructive
'''

if __name__ == '__main__':
    n, k = map(int, input().split())
    n0, n1 = 0, 0
    a, ans = [0] * k, []
    i = 0
    for j in range(n, 1, -1):
        if i == 0:
            n0 +=1 
        elif i == 1:
            n1 += 1
        if a[i]:
            ans.append(f"{a[i]} {j}")
        a[i] = j
        i = (i + 1) % k

    # build root
    for x in a:
        ans.append(f"{x} 1")

    # print answer
    print(n0 + n1)
    print(*ans, sep='\n')