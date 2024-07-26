import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    # 最短字符串為字母，因此每個字母只會出現一次
    # 暴力: 枚舉所有可能的字符排列(TLE)
    # 觀察: 每個字符的後繼只會有一種可能，組成DAG
    # case1: 不能共用字符: 同字符串vis[p]只會變成i一次
    # case2: 是否能連接: 唯一 nxt[last] -> p
    # case3: 能連接，但只能經過一次轉移
    # case4: 必須用光所有字符
    
    nxt = [-1] * 26  # 每個字符的後繼
    vis = [-1] * 26 # 使用此字符的字串名稱
    
    for i in range(n):
        s = input()
        last = -1 # 上個連接的字符
        for c in s:
            p = ord(c) - 97 
            
            if vis[p] == i: # case1: 重複使用字符(注意可以共用)
                print('NO')
                return
            vis[p] = i
            
            if last != -1: # case2: 考慮是否能連接(共用字符)
                if nxt[last] != -1 and nxt[last] != p:
                    print('NO')
                    return
                nxt[last] = p
            last = p
    
    ind = [0] * 26
    for x in nxt:
        if x != -1:
            ind[x] += 1
    if any(x > 1 for x in ind): # case3: 兩個入度
        print('NO')
        return
    
    ans = []
    for i in range(26):
        if ind[i] == 0 and vis[i] != -1:
            cur = i
            while cur != -1: # 只看vis[cur]!=-1會錯誤，會print(chr(96))
                ans.append(cur)
                vis[cur] = -1
                cur = nxt[cur]
    if any(x != -1 for x in vis): # 沒用光字符串
        print('NO')
    else:
        print(''.join(chr(x + 97) for x in ans))
                
for _ in range(1):
    n = int(input())
    solve()