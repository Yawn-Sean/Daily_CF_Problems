def main():
    n = int(input())
    a,b = 2, 1
    ans = 0
    # 最大为第ans场比赛时最多有多少名玩家
    while a <= n:
        ans += 1
        a,b = a+b,a
    print(ans)
main()