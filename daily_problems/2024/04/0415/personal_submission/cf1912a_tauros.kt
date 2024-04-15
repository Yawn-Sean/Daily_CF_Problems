private fun solve() {
    // https://codeforces.com/problemset/problem/1912/A
    // https://codeforces.com/problemset/submission/1912/256760255
    // 乱搞过的
    // 把有负数的做下前缀和，前缀和最小值为获取这一段的门槛值，收益是整个和
    // 收益小于0就没意义了，然后每个队头扔到堆里，门槛值越高越好
    // 从堆一个一个取，直到不能取
    val (x, k) = rd.ni() to rd.ni()
    val lists = ar(k) {
        val n = rd.ni()
        rd.na(n)
    }

    data class Info(val min: long, val sum: long)
    val items = lists.map { list ->
        buildList {
            var i = 0
            while (i < list.size) {
                var (min, sum) = 0L to 0L
                var j = i
                while (j < list.size && (j == i || sum < 0)) {
                    sum += list[j++]
                    min = minOf(min, sum)
                }
                if (sum >= 0) {
                    add(Info(min, sum))
                } else break
                i = j
            }
        }.toTypedArray()
    }.toTypedArray()

    var ans = x.toLong()
    val heap = KHeap<Pair<Info, IIP>> { a, b -> -a.first.min.compareTo(b.first.min) }
    for (i in items.indices) if (items[i].isNotEmpty()) heap.offer(items[i][0] to (i to 1))
    while (heap.isNotEmpty()) {
        val (top, idx) = heap.poll()
        if (ans + top.min < 0) break
        ans += top.sum
        val (i, j) = idx
        if (j < items[i].size) {
            heap.offer(items[i][j] to (i to j + 1))
        }
    }
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}