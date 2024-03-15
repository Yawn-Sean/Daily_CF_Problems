import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable

open class FastReader(private val input: InputStream, bufCap: Int = 8192) {
    companion object { private const val NC = 0.toChar() }
    private val buf = ByteArray(bufCap)
    private var bId = 0
    private var size = 0
    private var c = NC
    private val char: Char
        get() {
            while (bId == size) { size = input.read(buf); if (size == -1) return NC; bId = 0 }
            return buf[bId++].toInt().toChar()
        }
    private fun isWhitespace(c: Char) = c.code !in 33..126
    private fun skip(): Char { var b: Char; while (char.also { b = it } != NC && isWhitespace(b)); return b }
    fun ns() = buildString {
        while (true) { c = char; if (!isWhitespace(c)) break }; append(c);
        while (true) { c = char; if (isWhitespace(c)) break; append(c) }
    }
    fun ns(n: Int): CharArray {
        val buf = CharArray(n); var (b, p) = skip() to 0
        while (p < n && !isWhitespace(b)) { buf[p++] = b;b = char }
        return if (n == p) buf else buf.copyOf(p)
    }
    fun ni(): Int {
        var neg = false; if (c == NC) c = char
        while (c < '0' || c > '9') { if (c == '-') neg = true;c = char }
        var res = 0; while (c in '0'..'9') { res = (res shl 3) + (res shl 1) + (c - '0'); c = char }
        return if (neg) -res else res
    }
    fun nl(): Long {
        var neg = false; if (c == NC) c = char
        while (c < '0' || c > '9') { if (c == '-') neg = true; c = char }
        var res = 0L; while (c in '0'..'9') { res = (res shl 3) + (res shl 1) + (c - '0'); c = char }
        return if (neg) -res else res
    }
    fun na(n: Int) = IntArray(n) { ni() }; fun nal(n: Int) = LongArray(n) { nl() }; fun nad(n: Int) = DoubleArray(n) { nd() }
    fun nm(n: Int, m: Int) = Array(n) { ns(m) }; fun nmi(n: Int, m: Int) = Array(n) { na(m) }
    fun nd() = ns().toDouble(); fun nc() = skip()
}
open class FastWriter : Closeable {
    private val writer: PrintWriter
    constructor(output: OutputStream, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(OutputStreamWriter(output), bufCap))
    }
    constructor(writer: Writer, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(writer, bufCap))
    }
    override fun close() { writer.flush(); try { writer.close() } catch (e: Exception) { e.printStackTrace() } }
    fun print(b: Boolean) = writer.print(b); fun print(c: Char) = writer.print(c); fun print(i: Int) = writer.print(i)
    fun print(l: Long) = writer.print(l); fun print(f: Float) = writer.print(f); fun print(d: Double) = writer.print(d)
    fun print(s: CharArray) = writer.print(s); fun print(s: String?) = writer.print(s);
    fun print(obj: Any?) = writer.print(obj)
    fun println() = writer.println(); fun println(x: Boolean) = writer.println(x); fun println(x: Char) = writer.println(x)
    fun println(x: Int) = writer.println(x); fun println(x: Long) = writer.println(x); fun println(x: Float) = writer.println(x)
    fun println(x: Double) = writer.println(x); fun println(x: CharArray) = writer.println(x); fun println(x: String) = writer.println(x)
    fun println(x: Any) = writer.println(x)
    fun printf(format: String, vararg args: Any?) = writer.format(format, *args)
    fun flush() = writer.flush()
}
inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
typealias int = Int
typealias long = Long
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
    val vtxEdgeCnt = IntArray(nodeCap)
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
        this.vtxEdgeCnt[from] += 1
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
            vtxEdgeCnt[u] = 0
            first[u] = -1
        }
    }
}
inline fun iao(vararg nums: Int) = intArrayOf(*nums)
inline fun lar(size: Int, init: (Int) -> Long = { 0L }) = LongArray(size) { init(it) }
inline fun <reified T> mlo(vararg elements: T) = mutableListOf(*elements)
inline fun <R> LongArray.bitQuery(pos: Int, initial: R, operation: (R, Long) -> R): R {
    var iter = pos
    var ans = initial
    while (iter > 0) {
        ans = operation(ans, this[iter])
        iter -= iter.takeLowestOneBit()
    }
    return ans
}
inline fun LongArray.bitUpdateWithIndex(pos: Int, calc: LongArray.(Int) -> Unit) {
    if (pos <= 0) return
    var iter = pos
    while (iter < size) {
        calc(iter)
        iter += iter.takeLowestOneBit()
    }
}

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/1076/E
    // 差分再差分，首先是子树dfn差分
    // 然后在子树内对dep差分，对每个点查询它dep的值
    // 可以dfs时在线对dep差分，时间比全部离线更好
    val n = rd.ni()
    val graph = Graph(n, (n - 1) * 2)
    repeat(n - 1) {
        val (u, v) = rd.ni() - 1 to rd.ni() - 1
        graph.addEdge(u, v); graph.addEdge(v, u)
    }
    val ops = ar(n + 1) { mlo<IntArray>() }
    val m = rd.ni()
    repeat(m) {
        val (v, d, x) = iao(rd.ni() - 1, rd.ni(), rd.ni())
        ops[v].add(iao(d, x))
    }

    fun LongArray.update(pos: int, add: int) = this.bitUpdateWithIndex(pos) { this[it] += add.toLong() }
    fun LongArray.query(pos: int) = this.bitQuery(pos, 0L, long::plus)

    val (ans, bit) = lar(n) to lar(n + 2)
    fun Graph.dfs(u: int = 0, fa: int = -1, dep: int = 1) {
        for ((d, x) in ops[u]) {
            bit.update(dep, x)
            bit.update(dep + d + 1, -x)
        }
        ans[u] = bit.query(dep)
        each(u) {
            val v = to[it]
            if (v == fa) return@each
            dfs(v, u, dep + 1)
        }
        for ((d, x) in ops[u]) {
            bit.update(dep, -x)
            bit.update(dep + d + 1, x)
        }
    }
    graph.dfs()

    for (res in ans) wt.print("$res ")
    wt.println()
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}