# Submission link: https://codeforces.com/contest/1530/submission/313859448
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LGMI()
        
        cnt = [0] * n
        for num in nums:
            cnt[num] += 1
        
        target = []
        for i in range(n):
            if cnt[i] == 0:
                target.append(i)
        
        position = []
        for i in range(n):
            cnt[nums[i]] -= 1
            if cnt[nums[i]]:
                position.append(i)
        
        k = len(position)
        outs.append(str(n - k))
        
        if k > 1:
            while True:
                random.shuffle(position)
                flg = True
                for i in range(k):
                    if target[i] == position[i]:
                        flg = False
                if flg: break
            
            for i in range(k):
                nums[position[i]] = target[i]
        
        elif k == 1:
            if position[0] == target[0]:
                for j in range(n):
                    if j != position[0] and nums[j] == nums[position[0]]:
                        nums[j] = target[0]
            else:
                nums[position[0]] = target[0]
        
        outs.append(' '.join(str(x + 1) for x in nums))

    print('\n'.join(outs))