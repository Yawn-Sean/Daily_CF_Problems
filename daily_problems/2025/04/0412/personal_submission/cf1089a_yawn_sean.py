# Submission link: https://codeforces.com/contest/1089/submission/315072076
def main():
    def f(score1, score2, set1, set2):
        return (((score1 * 201) + score2) * 4 + set1) * 4 + set2

    dp = [-2] * (201 * 201 * 4 * 4)
    dp[f(0, 0, 0, 0)] = -1

    que = [f(0, 0, 0, 0)]

    for u in que:
        cur = u
        u, set2 = divmod(u, 4)
        u, set1 = divmod(u, 4)
        score1, score2 = divmod(u, 201)
        
        # 如果这局赢了
        if set1 + 1 <= 3 and set2 < 3:
            
            set_score = 25 if set1 + set2 < 4 else 15
            
            if score1 + set_score <= 200:
                for i in range(set_score - 1):
                    if score2 + i <= 200:
                        ncur = f(score1 + set_score, score2 + i, set1 + 1, set2)
                        if dp[ncur] == -2:
                            dp[ncur] = cur
                            que.append(ncur)
            
            for i in range(set_score + 1, 201):
                if score1 + i > 200 or score2 + i - 2 > 200: break
                ncur = f(score1 + i, score2 + i - 2, set1 + 1, set2)
                if dp[ncur] == -2:
                    dp[ncur] = cur
                    que.append(ncur)
        
        # 如果这局输了
        if set1 < 3 and set2 + 1 <= 3:
            
            set_score = 25 if set1 + set2 < 4 else 15

            if score2 + set_score <= 200:
                for i in range(set_score - 1):
                    if score1 + i <= 200:
                        ncur = f(score1 + i, score2 + set_score, set1, set2 + 1)
                        if dp[ncur] == -2:
                            dp[ncur] = cur
                            que.append(ncur)
            
            for i in range(set_score + 1, 201):
                if score1 + i - 2 > 200 or score2 + i > 200: break
                ncur = f(score1 + i - 2, score2 + i, set1, set2 + 1)
                if dp[ncur] == -2:
                    dp[ncur] = cur
                    que.append(ncur)

    t = II()
    outs = []

    for _ in range(t):
        x, y = MII()
        
        cx, cy = -1, -1
        for i in range(3):
            if dp[f(x, y, 3, i)] != -2:
                cx, cy = 3, i
                break
        
        if cx == -1:
            for i in range(2, -1, -1):
                if dp[f(x, y, i, 3)] != -2:
                    cx, cy = i, 3
                    break
        
        if cx != -1:
            outs.append(f'{cx}:{cy}')
            
            cur = f(x, y, cx, cy)
            sets = []
            
            for _ in range(cx + cy):
                prev = dp[cur]
                scores = (cur - prev) // 16
                sets.append(divmod(scores, 201))
                cur = prev
            
            sets.reverse()
            outs.append(' '.join(f'{a}:{b}' for a, b in sets))
        else:
            outs.append('Impossible')

    print('\n'.join(outs))