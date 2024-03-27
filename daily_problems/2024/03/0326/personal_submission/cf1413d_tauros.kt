private fun solve() {
    // https://codeforces.com/problemset/problem/1413/D
    // 没有太会
    val n = rd.ni()

    val pos = dq<int>()
    val ans = iar(n) { -1 }
    var cnt = 0
    var success = true
    val ops = buildList {
        repeat(2 * n) {
            val op = rd.nc()
            if (op == '+') {
                pos.addLast(cnt++)
                add(iao(0))
            } else {
                val num = rd.ni()
                if (pos.isEmpty()) {
                    success = false
                } else {
                    ans[pos.removeLast()] = num
                }
                add(iao(1, num))
            }
        }
    }

    if (!success) {
        wt.println("NO")
        return
    }
    val pq = PriorityQueue<int>()
    var i = 0
    for (op in ops) {
        if (op.size > 1) {
            if (pq.poll() != op[1]) {
                wt.println("NO")
                return
            }
        } else {
            pq.offer(ans[i++])
        }
    }
    wt.println("YES")
    for (res in ans) wt.print("$res ")
    wt.println()
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}