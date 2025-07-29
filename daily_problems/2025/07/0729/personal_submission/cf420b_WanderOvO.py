"""
完全没有提及的人，可能是主持人
然后假设其他没提及的人都不在
先扫描一遍所有的，假如出现未进入直接退出的，就说明最开始一定有这个人，把这些人存起来
先只考虑最开始有这几个人，然后从前往后模拟，同时维护一个始终在会议里的人的集合；倘若最开始没人，则手动特判掉第一个进入的人
维护当前集合以及“始终在会议里的人”集合，当前集合里的人删完时，需要记录最后一个被删的人，假如下次它又被第一个加进来了，则仍然视为“始终在会议里”
最后的答案就是“始终在会议里的人”集合中的这些人，以及从来没被提及的人们
"""

n, m = map(int, input().split())
logs = []
for i in range(m):
    op, id = input().split()
    id = int(id)
    logs.append((op, id))

cur_in_meeting = set()
always_in_meeting = set()

in_meeting = [False] * (n + 1)
appear = [False] * (n + 1)

for i in range(m):
    op, id = logs[i][0], logs[i][1]
    appear[id] = True
    if op == "+":
        in_meeting[id] = True
    else:
        if in_meeting[id]:
            in_meeting[id] = False
        else:
            # 说明在最开始就在里面
            cur_in_meeting.add(id)
            in_meeting[id] = False

for id in cur_in_meeting:
    always_in_meeting.add(id)

res = []
for i in range(1, n + 1):
    if not appear[i]:
        res.append(i)

start = 0
# 如果给出的记录中没有暗含某个人之前就在里面，则先把记录中第一个人加进去
if len(always_in_meeting) == 0:
    assert logs[0][0] == "+"
    only_id = logs[0][1]
    always_in_meeting.add(only_id)
    cur_in_meeting.add(only_id)
    start = 1

i = start
while i < m:
    op, id = logs[i][0], logs[i][1]
    if op == "+":
        cur_in_meeting.add(id)
    else:
        cur_in_meeting.remove(id)
        if id in always_in_meeting:
            always_in_meeting.remove(id)
            if len(always_in_meeting) == 0 and len(cur_in_meeting) == 0:
                if i + 1 < m:
                    if logs[i + 1][0] == "+" and logs[i + 1][1] == id:
                        always_in_meeting.add(id)
                        cur_in_meeting.add(id)
                        i += 1
                    else:
                        break
                else:
                    always_in_meeting.add(id)
    i += 1

for id in always_in_meeting:
    res.append(id)
res.sort()
print(len(res))
print(*res)
