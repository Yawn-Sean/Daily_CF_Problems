for _ in range(int(input())):
    n = int(input())    
    cnt = [0] * 4
    for x, y in zip(input() , input()):
        cnt[int(x) << 1 | int(y)] += 1        
    ans1 = cnt[-1] + cnt[0] if cnt[-1] == cnt[0] + 1 else n + 1
    ans2 = cnt[2] + cnt[1] if cnt[2] == cnt[1]  else n + 1
    ans = min(ans1 , ans2)
    print(-1 if ans == n + 1 else ans)
