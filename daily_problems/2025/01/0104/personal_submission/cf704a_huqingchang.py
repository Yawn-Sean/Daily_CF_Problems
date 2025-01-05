def main():
    n, q = MII()
    d = defaultdict(deque)  # 记录每一个app里面的通知消息队列
    cnt, unread = 0, 0  # 消息总数，未读消息数量
    que = dict()  # 记录某个通知是那个app弹出来的
    dq = deque()  # 记录所有未读通知消息
    to_del = set()  # 记录所有已经读取的消息

    for _ in range(q):
        x, y = MII()
        if x == 1:
            cnt += 1
            unread += 1
            que[cnt] = y
            dq.append(cnt)
            d[y].append(cnt)
        elif x == 2:
            unread -= len(d[y])
            while d[y]:
                tmp = d[y].popleft()
                to_del.add(tmp)
        else:
            while dq and dq[0] <= y:
                tmp = dq.popleft()
                if tmp not in to_del:
                    unread -= 1
                    to_del.add(tmp)
                    d[que[tmp]].popleft()
        print(unread)


T = 1
for ii in range(T):
    # print(main())
    main()
