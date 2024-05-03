# submission: https://codeforces.com/problemset/submission/954/259116665

def main():
    n, T = MII()
    nums = LII()
    ts = LII()

    tot_temp = sum(nums[i] * ts[i] for i in range(n))
    tot_volume = sum(nums[i] for i in range(n))
    ave = tot_temp / tot_volume
    
    arr = list(zip(ts, nums))
    arr_cold = [x for x in arr if x[0] < T]
    arr_hot = [x for x in arr if x[0] > T]
    arr_warm = [x for x in arr if x[0] == T]

    ans = tot_volume
    # 去掉冷水
    if ave < T:
        if not arr_hot:
            print(sum(x[1] for x in arr_warm))
            exit()
        arr_cold.sort(key=lambda x: x[0], reverse=True)
        while ave < T:
            if not arr_cold:
                ans = 0.0
                break
            t, num = arr_cold.pop()
            new_ave = (tot_temp - t * num) / (tot_volume - num)
            if new_ave >= T:
                '''
                设 去掉 x 个冷水后刚好温度等于 T
                (tot_temp - x * t) / (tot_volume - x) = T
                tot_temp - x * t = T * tot_volume - x * T
                x * (T - t) = T * tot_volume - tot_temp
                x = (T * tot_volume - tot_temp) / (T - t)
                '''
                ans = tot_volume - (T * tot_volume - tot_temp) / (T - t)
                break
            else:
                ave = new_ave
                tot_volume -= num
                tot_temp -= t * num
    else: # 去掉热水
        if not arr_cold:
            print(sum(x[1] for x in arr_warm))
            exit()
        arr_hot.sort(key=lambda x: x[0])
        while ave > T:
            if not arr_hot:
                ans = 0.0
                break
            t, num = arr_hot.pop()
            new_ave = (tot_temp - t * num) / (tot_volume - num)
            if new_ave <= T:
                ans = tot_volume - (T * tot_volume - tot_temp) / (T - t)
                break
            else:
                ave = new_ave
                tot_volume -= num
                tot_temp -= t * num
    print(ans)

main()