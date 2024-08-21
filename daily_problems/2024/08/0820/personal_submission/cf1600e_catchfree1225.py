import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 不要討論誰贏，討論總操作次數(長度)
    # 兩種Case: 操作數為奇數, 偶數(Alice, Bob)
    # 討論前後綴遞增長度: 偶偶, 偶奇, 奇奇
    
    # case1: 偶偶
    # 如果兩端都為偶數，後手一直跟著先手操作即可
    # 不管先手怎麼選，後手可以一直跟進
    # 最後結束在某側，必是偶數長度
    
    # case2: 偶奇
    # 先手先拿奇數堆，化為偶偶
    # 情況同偶偶，只是先手勝
    
    # case3: 奇奇
    # 跟偶偶不同，先手不知道後手選誰，但可以優先選擇前後
    # 先手拿較大的，讓後手無法選擇
    # 結束操作數為奇數
    
    left = 1
    for i in range(n - 1):
        if a[i] >= a[i + 1]:
            break
        left += 1
    
    right = 1
    for i in range(n - 1, 0, -1):
        if a[i - 1] <= a[i]:
            break
        right += 1
    
    if left % 2 == 0 and right % 2 == 0:
        print('Bob')
    else:
        print('Alice')
    
               
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()