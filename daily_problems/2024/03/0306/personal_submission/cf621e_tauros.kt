inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
class MOD {
    companion object {
        private val INV_MAP = mutableMapOf<Int, MutableMap<Int, Int>>()
        private val INV_LONG_MAP = mutableMapOf<Int, MutableMap<Long, Int>>()
        var globalMod: Int = 0

        fun inv(num: Int): Int = INV_MAP.computeIfAbsent(globalMod) { mutableMapOf() }.computeIfAbsent(num) { inv(num, globalMod) }

        fun inv(num: Long): Int = INV_LONG_MAP.computeIfAbsent(globalMod) { mutableMapOf() }.computeIfAbsent(num) { inv(num, globalMod.toLong()).toInt() }

        fun pow(num: Long, p: Long): Int {
            var pow = p
            var a = num
            if (a >= globalMod) {
                a %= globalMod.toLong()
            }
            var res: Long = 1
            while (pow > 0) {
                if (pow and 1 == 1L) {
                    res = res * a % globalMod
                }
                a = a * a % globalMod
                pow = pow shr 1
            }
            return res.toInt()
        }

        inline fun regular(num: Int): Int = if (num in 0 until globalMod) num else {
            val r = num % globalMod
            r + (globalMod and (((r xor globalMod) and (r or -r)) shr 31))
        }

        inline fun regular(num: Long): Int = if (num in 0 until globalMod) num.toInt() else {
            val r = (num % globalMod).toInt()
            r + (globalMod and (((r xor globalMod) and (r or -r)) shr 31))
        }

        inline fun add(a: Int, b: Int): Int {
            val res = regular(a) + regular(b)
            return regular(res)
        }

        inline fun sub(a: Int, b: Int): Int {
            val res = regular(a) - regular(b)
            return regular(res)
        }

        inline fun mul(a: Int, b: Int): Int {
            val res = regular(a).toLong() * regular(b)
            return regular(res)
        }

        inline fun div(a: Int, b: Int): Int {
            val res = regular(a).toLong() * inv(regular(b))
            return regular(res)
        }

        inline fun <T> decorate(mod: Int, process: Companion.() -> T): T {
            val preGlobal = globalMod
            globalMod = mod
            val res = process(Companion)
            globalMod = preGlobal
            return res
        }
    }
}
fun exgcd(a: Int, b: Int): IntArray {
    // calc ax + by = gcd(a, b)
    // x = x0 + k * (b/gcd(a,b)); y = y0 - k * (a/gcd(a,b))
    // calc ax + by = o * gcd(a, b) -> calc a * o * x' + b * o * y' = o * gcd(a, b)
    // x = x0 * o + k * (b/gcd(a,b)); y = y0 * o - k * (a/gcd(a,b))
    if (b == 0) {
        // gcd, x, y
        return intArrayOf(a, 1, 0)
    }
    // x = y0; y = x0 - (a / b) * y0;
    val (gcd, x0, y0) = exgcd(b, a % b)
    val y = x0 - a / b * y0
    return intArrayOf(gcd, y0, y)
}
fun exgcd(a: Long, b: Long): LongArray {
    // calc ax + by = gcd(a, b)
    // x = x0 + k * (b/gcd(a,b)); y = y0 - k * (a/gcd(a,b))
    // calc ax + by = o * gcd(a, b) -> calc a * o * x' + b * o * y' = o * gcd(a, b)
    // x = x0 * o + k * (b/gcd(a,b)); y = y0 * o - k * (a/gcd(a,b))
    if (b == 0L) {
        // gcd, x, y
        return longArrayOf(a, 1, 0)
    }
    // x = y0; y = x0 - (a / b) * y0;
    val (gcd, x0, y0) = exgcd(b, a % b)
    val y = x0 - a / b * y0
    return longArrayOf(gcd, y0, y)
}
fun inv(a: Long, p: Long): Long {
    val (gcd, inv, _) = exgcd(a, p)
    if (gcd != 1L) return -1
    return (inv + p) % p
}
fun inv(a: Int, p: Int): Int {
    val (gcd, inv, _) = exgcd(a, p)
    if (gcd != 1) return -1
    return (inv + p) % p
}
infix fun Int.ma(other: Int): Int = MOD.add(this, other)
infix fun Int.mm(other: Int): Int = MOD.mul(this, other)
typealias string = String
inline fun <T> withMod(mod: Int, process: MOD.Companion.() -> T): T {
    return MOD.decorate(mod, process)
}
inline fun iar(size: Int, init: (Int) -> Int = { 0 }) = IntArray(size) { init(it) }
class Matrix(val rows: Int, val cols: Int = rows, elements: IntArray = IntArray(0)) : Iterable<Iterable<Int>>, Cloneable {
    val elements = IntArray(rows * cols) { if (it >= elements.size) 0 else elements[it] }
    constructor(matrix: Array<IntArray>) : this(
        matrix.size, if (matrix.isEmpty()) 0 else matrix[0].size,
        matrix.flatMap { it.toList() }.toIntArray()
    )
    companion object {
        private val ZERO = mutableMapOf<Pair<Int, Int>, Matrix>()
        private val ONE = mutableMapOf<Int, Matrix>()
        fun zero(rows: Int, cols: Int) = ZERO.computeIfAbsent(rows to cols) { (rows, cols) -> Matrix(rows, cols) }
        fun one(rows: Int) = ONE.computeIfAbsent(rows) { cols ->
            Matrix(cols, cols, IntArray(cols * cols) { if (it / cols == it % cols) 1 else 0 })
        }
    }
    class IntArrayView(private val base: Int, private val matrix: Matrix) : Iterable<Int> {
        val size = matrix.cols
        operator fun get(idx: Int) = matrix.elements[base + idx]
        override fun iterator() = object : Iterator<Int> {
            private var idx = 0
            override fun hasNext() = idx < size
            override fun next() = get(idx)
        }
    }
    operator fun get(idx: Int) = IntArrayView(idx * cols, this)
    operator fun plus(other: Matrix): Matrix {
        return Matrix(rows, cols, IntArray(rows * cols) {
            if (MOD.globalMod > 0) {
                elements[it] ma other.elements[it]
            } else {
                elements[it] + other.elements[it]
            }
        })
    }
    operator fun times(other: Matrix): Matrix {
        val ans = IntArray(rows * other.cols)
        if (MOD.globalMod > 0) {
            for (i in 0 until rows) for (j in 0 until other.cols) {
                var sum = 0
                for (k in 0 until cols) {
                    sum = elements[i * cols + k] mm other.elements[k * other.cols + j] ma sum
                }
                ans[i * other.cols + j] = sum
            }
        } else {
            for (i in 0 until rows) for (k in 0 until cols) {
                if (elements[i * cols + k] == 0) continue
                for (j in 0 until other.cols) {
                    ans[i * other.cols + j] += elements[i * cols + k] * other.elements[k * other.cols + j]
                }
            }
        }
        return Matrix(rows, other.cols, ans)
    }
    fun pow(exp: Int) = pow(exp.toLong())
    fun pow(exp: Long): Matrix {
        var (a, p) = this to exp
        var ans: Matrix = one(rows)
        while (p > 0) {
            if (p and 1L == 1L) {
                ans *= a
            }
            a *= a
            p = p shr 1
        }
        return ans
    }
    public override fun clone() = Matrix(rows, cols, elements)
    override fun iterator() = object : Iterator<Iterable<Int>> {
        private var row = 0
        override fun hasNext() = row < rows
        override fun next() = object : Iterable<Int> {
            private val base = row * cols
            override fun iterator() = object : Iterator<Int> {
                private var col = 0
                override fun hasNext() = col < cols
                override fun next() = elements[base + col++]
            }
        }.also { row++ }
    }
    fun toTypedArray() = toList().map { it.toList().toIntArray() }.toTypedArray()
    override fun toString(): String {
        return buildString {
            for (i in 0 until rows) {
                append('[')
                append(buildString {
                    for (j in 0 until cols) {
                        append(elements[i * cols + j])
                        append(", ")
                    }
                }.trimEnd(' ').trimEnd(','))
                append(']')
                append('\n')
            }
        }
    }
}
class IntArrayView(private val base: Int, private val matrix: Matrix) : Iterable<Int> {
        val size = matrix.cols
        operator fun get(idx: Int) = matrix.elements[base + idx]
        override fun iterator() = object : Iterator<Int> {
            private var idx = 0
            override fun hasNext() = idx < size
            override fun next() = get(idx)
        }
    }

/**
 * generated by kotlincputil@tauros
 */
fun main(args: Array<String>) {
    // https://codeforces.com/problemset/problem/621/E
    // 一开始还讨论了每个10^y对x取模的周期，分组进行转移，结果搞了个x^4的复杂度T了
    // 回头想发现直接添加数位转移更方便，每个转移就是选前一个数的状态乘10再加最后一个数位
    // 复杂度x^3*logb
    val (n, b, k, x) = readln().split(" ").map(string::toInt)
    val a = readln().split(" ").map(string::toInt)

    val cnt = iar(10)
    for (num in a) cnt[num - 1] += 1

    withMod(1e9.toInt() + 7) {
        val transferArr = ar(x) { iar(x) }
        for (from in 0 until x) for (num in 1 .. 9) if (cnt[num - 1] > 0) {
            withMod(x) {
                val to = from mm 10 ma num
                transferArr[to][from] += cnt[num - 1]
            }
        }
        val transferMat = Matrix(transferArr).pow(b - 1)
        val initArr = iar(x)
        for (num in 1 .. 9) if (cnt[num - 1] > 0) {
            initArr[num % x] += cnt[num - 1]
        }
        val init = Matrix(x, 1, initArr)
        val ans = transferMat * init
        println(ans[k][0])
    }
}