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
inline fun iao(vararg nums: Int) = intArrayOf(*nums)
inline fun lar(size: Int, init: (Int) -> Long = { 0L }) = LongArray(size) { init(it) }

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/1083/A
    // dp每个子树单链最长，然后比较单链（单点也是单链）与双链即可
    val n = rd.ni()
    val vtx = rd.na(n)
    val graph = IGraph(n, (n - 1) * 2)

    repeat(n - 1) {
        val (u, v, c) = iao(rd.ni() - 1, rd.ni() - 1, rd.ni())
        graph.addEdge(u, v, c); graph.addEdge(v, u, c)
    }

    var ans = 0L
    fun IGraph.dfs(u: int, fa: int = -1): long {
        var (max1, max2) = lar(2) { -0x3f3f3f3f3f3f3f3fL }
        var dp = vtx[u].toLong()
        each(u) {
            val (v, c) = to[it] to weight[it]
            if (v == fa) return@each
            val chd = dfs(v, u)
            val sub = chd - c
            if (sub > max1) {
                max2 = max1
                max1 = sub
            } else if (sub > max2) {
                max2 = sub
            }
            dp = maxOf(dp, sub + vtx[u])
        }
        ans = maxOf(ans, dp, max1 + max2 + vtx[u])
        return dp
    }
    graph.dfs(0)
    wt.println(ans)
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}