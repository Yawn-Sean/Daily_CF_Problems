"""
关心最后是否得到无限黄金，所以考虑以 d 是否为 0 为初始讨论点
"""

a = list(map(int, input().split()))

if a[3] == 0:
    print("Hermione")
else:
    if a[2] == 0:
        print("Ron")
    else:
        if a[1] == 0:
            print("Hermione")
        else:
            if a[0] == 0:
                print("Ron")
            else:
                if a[5] == 0:
                    print("Hermione")
                else:
                    if a[4] == 0:
                        print("Ron")
                    else:
                        initial_sand = 1
                        for i in range(6):
                            initial_sand *= a[i]
                        lead_cnt = initial_sand // a[0] * a[1]
                        gold_cnt = lead_cnt // a[2] * a[3]
                        sand_cnt = gold_cnt // a[4] * a[5]
                        if sand_cnt > initial_sand:
                            print("Ron")
                        else:
                            print("Hermione")
