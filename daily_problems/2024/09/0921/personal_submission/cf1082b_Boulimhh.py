"""
思路： 先统计每个连续段金奖杯的长度， 取相邻两段长度的加和再 + 1 。 

但是也有可能只有一串G， 所以对结果取两者的min

"""
#python代码：
n = int(input())
s = input()
start, end, res = 0, 0, 0
for c in s:
    if c == "G": start += 1
    else: end, start = start, 0
    res = max(res, start + end + 1)
print(min(res, s.count("G")))
