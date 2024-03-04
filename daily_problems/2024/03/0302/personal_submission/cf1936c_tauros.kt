import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable

open class FastReader(private val input: InputStream, bufCap: Int = 8192) {
    companion object {
        private const val NC = 0.toChar()
    }

    private val buf = ByteArray(bufCap)
    private var bId = 0
    private var size = 0
    private var c = NC
    private val char: Char
        get() {
            while (bId == size) {
                size = input.read(buf) // no need for checked exceptions
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toInt().toChar()
        }

    private fun isWhitespace(c: Char) = c.code !in 33..126

    private fun skip(): Char {
        var b: Char
        while (char.also { b = it } != NC && isWhitespace(b));
        return b
    }

    fun ns() = buildString {
        while (true) {
            c = char
            if (!isWhitespace(c)) {
                break
            }
        }
        append(c)
        while (true) {
            c = char
            if (isWhitespace(c)) {
                break
            }
            append(c)
        }
    }

    fun ns(n: Int): CharArray {
        val buf = CharArray(n)
        var b = skip()
        var p = 0
        while (p < n && !isWhitespace(b)) {
            buf[p++] = b
            b = char
        }
        return if (n == p) buf else buf.copyOf(p)
    }

    fun ni(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun nl(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun na(n: Int) = IntArray(n) { ni() }
    fun nal(n: Int) = LongArray(n) { nl() }
    fun nad(n: Int) = DoubleArray(n) { nd() }
    fun nm(n: Int, m: Int) = Array(n) { ns(m) }
    fun nmi(n: Int, m: Int) = Array(n) { na(m) }
    fun nd() = ns().toDouble()
    fun nc() = skip()
}
open class FastWriter : Closeable {
    private val writer: PrintWriter

    constructor(output: OutputStream, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(OutputStreamWriter(output), bufCap))
    }

    constructor(writer: Writer, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(writer, bufCap))
    }

    override fun close() {
        writer.flush()
        try {
            writer.close()
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    fun print(b: Boolean) = writer.print(b)
    fun print(c: Char) = writer.print(c)
    fun print(i: Int) = writer.print(i)
    fun print(l: Long) = writer.print(l)
    fun print(f: Float) = writer.print(f)
    fun print(d: Double) = writer.print(d)
    fun print(s: CharArray) = writer.print(s)
    fun print(s: String?) = writer.print(s)
    fun print(obj: Any?) = writer.print(obj)
    fun println() = writer.println()
    fun println(x: Boolean) = writer.println(x)
    fun println(x: Char) = writer.println(x)
    fun println(x: Int) = writer.println(x)
    fun println(x: Long) = writer.println(x)
    fun println(x: Float) = writer.println(x)
    fun println(x: Double) = writer.println(x)
    fun println(x: CharArray) = writer.println(x)
    fun println(x: String) = writer.println(x)
    fun println(x: Any) = writer.println(x)
    fun printf(format: String, vararg args: Any?) = writer.format(format, *args)
    fun flush() = writer.flush()
}
inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
inline fun bar(size: Int, init: (Int) -> Boolean = { false }) = BooleanArray(size) { init(it) }
typealias int = Int
fun LongArray.swap(i: Int, j: Int) {
    val tmp = this[i]
    this[i] = this[j]
    this[j] = tmp
}
fun IntArray.swap(i: Int, j: Int) {
    val tmp = this[i]
    this[i] = this[j]
    this[j] = tmp
}
open class Graph(val nodeCap: Int, var edgeCap: Int = maxOf(nodeCap, MIN_EDGE_COUNT),
                 private val needFrom: Boolean = false, private val removeAble: Boolean = false) {
    companion object {
        val MAX_EDGE_COUNT = 1e8.toInt()
        val MIN_EDGE_COUNT = 10
    }

    var idx = -1
    var removed = 0
    val totalEdgeCnt: Int get() = idx + 1 - removed
    val first = IntArray(nodeCap) { -1 }
    val vtxEdgeCnt = IntArray(if (removeAble) nodeCap else 0)
    var to = IntArray(edgeCap)
    var next = IntArray(edgeCap)
    var from = IntArray(if (needFrom) edgeCap else 0)

    private fun newCapacity(old: Int) = minOf(MAX_EDGE_COUNT, maxOf(MIN_EDGE_COUNT, old + (old shr 1)))

    private fun ensureCapacityIncrement() {
        if (idx + 1 >= edgeCap) {
            val newCap = newCapacity(edgeCap)
            expand(newCap - edgeCap)
            edgeCap = newCap
        }
    }

    protected open fun expand(increment: Int) {
        edgeCap += increment
        to += IntArray(increment)
        next += IntArray(increment)
        if (needFrom) {
            from += IntArray(increment)
        }
    }

    fun addEdge(from: Int, to: Int): Int {
        ensureCapacityIncrement()
        val edgeId = ++this.idx
        if (this.needFrom) {
            this.from[edgeId] = from
        }
        this.to[edgeId] = to
        this.next[edgeId] = this.first[from]
        this.first[from] = edgeId
        if (removeAble) {
            this.vtxEdgeCnt[from] += 1
        }
        return edgeId
    }

    inline fun each(u: Int, start: Int = first[u], withEdgeId: (Int) -> Unit = {}) {
        var edgeId = start
        while (edgeId != -1) {
            withEdgeId(edgeId)
            edgeId = next[edgeId]
        }
    }

    inline fun each(withEdgeId: (Int) -> Unit = {}) {
        var edgeId = 0
        while (edgeId <= idx) {
            withEdgeId(edgeId)
            edgeId++
        }
    }

    inline fun eachBreakable(u: Int, start: Int = first[u], withEdgeId: (Int) -> Boolean = { false }) {
        var edgeId = start
        var isBreak = false
        while (edgeId != -1 && !isBreak) {
            isBreak = withEdgeId(edgeId)
            edgeId = next[edgeId]
        }
    }

    inline fun eachBreakable(withEdgeId: (Int) -> Boolean = { false }) {
        var edgeId = 0
        var isBreak = false
        while (edgeId <= idx && !isBreak) {
            isBreak = withEdgeId(edgeId)
            edgeId++
        }
    }

    fun clear(u: Int) {
        if (removeAble) {
            removed += vtxEdgeCnt[u]
            first[u] = -1
        }
    }
}
class IGraph(nodeCap: Int, edgeCap: Int = maxOf(nodeCap, MIN_EDGE_COUNT) * 2, needFrom: Boolean = false)
    : Graph(nodeCap, edgeCap, needFrom) {
    var weight = IntArray(edgeCap)

    override fun expand(increment: Int) {
        super.expand(increment)
        weight += IntArray(increment)
    }

    fun addEdge(from: Int, to: Int, d: Int): Int {
        val edgeId = addEdge(from, to)
        weight[edgeId] = d
        return edgeId
    }
}
inline fun lar(size: Int, init: (Int) -> Long = { 0L }) = LongArray(size) { init(it) }
abstract class Heap<T>(var cap: Int = MIN_CAP) {
    companion object {
        val MIN_CAP = 10
        val MAX_CAP = 1e8.toInt()
    }

    protected var idx: Int = 0

    protected fun newCapacity(old: Int) = minOf(MAX_CAP, maxOf(MIN_CAP, old + (old shr 1)))

    fun offer(value: T) {
        if (idx >= cap) {
            val newCap = newCapacity(cap)
            expand(newCap - cap)
            cap = newCap
        }
        doOffer(value)
        afterOffer()
    }

    fun poll() = peek().also { afterPoll() }

    protected fun afterPoll() {
        swap(0, --idx)
        if (isEmpty()) return
        var iter = 0
        while (iter < idx) {
            val l = (iter shl 1) + 1
            val r = (iter shl 1) + 2
            if (l >= idx) break
            val next = if (r >= idx || compare(l, r) <= 0) l else r
            if (compare(iter, next) <= 0) break
            this.swap(iter, next)
            iter = next
        }
    }

    protected fun afterOffer() {
        var iter = idx++
        while (iter > 0) {
            val parent = (iter - 1) / 2
            if (compare(iter, parent) > 0) {
                break
            }
            swap(iter, parent)
            iter = parent
        }
    }

    abstract fun peek(): T
    protected abstract fun expand(increment: Int)
    protected abstract fun swap(p: Int, q: Int)
    protected abstract fun compare(indexA: Int, indexB: Int): Int
    protected abstract fun doOffer(new: T)
    val size: Int get() = idx
    fun isEmpty() = size <= 0
    fun isNotEmpty() = !isEmpty()
    fun clear() {
        idx = 0
    }
}
class LIHeap(initCap: Int = MIN_CAP, val keyComparator: (Long, Long) -> Int = { a, b -> a.compareTo(b) })
    : Heap<Pair<Long, Int>>(initCap) {
    private var key = LongArray(cap)
    private var value = IntArray(cap)

    override fun peek() = key[0] to value[0]

    override fun expand(increment: Int) {
        key += LongArray(increment)
        value += IntArray(increment)
    }

    override fun swap(p: Int, q: Int) {
        key.swap(p, q)
        value.swap(p, q)
    }

    override fun compare(indexA: Int, indexB: Int) = keyComparator(key[indexA], key[indexB])

    override fun doOffer(new: Pair<Long, Int>) {
        key[idx] = new.first
        value[idx] = new.second
    }
}

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/1936/C
    // https://codeforces.com/blog/entry/126513
    // 完全不会，学了题解感觉是最短路优化dp的一种套路题之类的
    // - 可以推理得知每个宝可梦最多只上场一次，多次上场没有任何意义，因为既然能第二次上场击败某个宝可梦，那被击败的那个宝可梦都没必要上场
    // - 继续推理也可得知每个用于击败某只宝可梦的属性也只会使用一次，因为击败了后胜者已经带着这个属性上场了，被这个属性再次击败也不会上场，无意义
    // - 那么属性提升的操作只会提升到刚好等于某个属性的值
    // - 原问题可以转换为第n号宝可梦站在场上最终成功击败1号宝可梦，以n号宝可梦为起始点建图
    // - 每个属性拆为两个点，一个实值点A，一个降值通道点D，这样建图
    // - 同一个属性内：实值点 -> 降值点，边权为0；意为不用费用即可使用更低属性值的属性
    // - 点i -> 点i的实值点，边权为cost[i]；意为需要需要通过点i使用这个属性的实值，这条边是用来从点i的属性j转到点i某个属性k时使用的
    //   相当于表示购买了这个宝可梦，之所以为什么点i对它的每个实值属性都要花费cost[i]
    //   其实从前面的推理可以得知某个宝可梦的只会使用一次某个属性，所以这样建图才成立
    // - 点i的降值点 -> 点i，边权为0；意为从降值通道走到了某个宝可梦，相当于是用高值属性击败了这个宝可梦
    //   如果要使用该宝可梦的另一个属性，那么才需要实际执行cost，走上面那条边即可
    // - 每项属性按属性值排序，相邻的属性间：
    //   实值点 -> 相邻的更高实值点，边权为差值；意为花钱升级属性值
    //   降值点 -> 相邻的更低降值点，边权为0；意为不用钱就能使用任意低于其值的任何一个降值点
    //   通过降值点走到某个宝可梦来执行其它属性
    // 非常好题目，使我学了很多
    val cases = rd.ni()
    repeat(cases) {
        val (n, m) = rd.ni() to rd.ni()
        val cost = rd.na(n)
        val attr = ar(n) { rd.na(m) }

        fun actualAttrIdx(i: int, j: int) = i * m + j
        fun goDownAttrIdx(i: int, j: int) = n * m + i * m + j
        fun vtxIdx(i: int) = n * m * 2 + i
        val graph = IGraph(n * m * 2 + n)

        for (j in 0 until m) {
            val sorted = (0 until n).sortedBy { attr[it][j] }
            for (k in 0 until n) {
                val cur = sorted[k]
                if (k + 1 < n) {
                    val next = sorted[k + 1]
                    graph.addEdge(actualAttrIdx(cur, j), actualAttrIdx(next, j), attr[next][j] - attr[cur][j])
                    graph.addEdge(goDownAttrIdx(next, j), goDownAttrIdx(cur, j), 0)
                }
                graph.addEdge(actualAttrIdx(cur, j), goDownAttrIdx(cur, j), 0)
            }
            for (i in 0 until n) {
                graph.addEdge(vtxIdx(i), actualAttrIdx(i, j), cost[i])
                graph.addEdge(goDownAttrIdx(i, j), vtxIdx(i), 0)
            }
        }

        val dist = lar(n * m * 2 + n) { 0x3f3f3f3f3f3f3f3fL }
        val vis = bar(n * m * 2 + n)
        val heap = LIHeap()
        heap.offer(0L to vtxIdx(n - 1))
        dist[vtxIdx(n - 1)] = 0
        while (heap.isNotEmpty()) {
            val (curDist, u) = heap.poll()
            if (vis[u]) continue
            vis[u] = true
            graph.each(u) {
                val (v, w) = graph.to[it] to graph.weight[it]
                if (curDist + w < dist[v]) {
                    dist[v] = curDist + w
                    heap.offer(dist[v] to v)
                }
            }
        }

        val ans = dist[vtxIdx(0)]
        wt.println(ans)
    }
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}