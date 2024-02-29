inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
class MInt(raw: Int) {
    companion object {
        val ZERO = MInt(0)
        val ONE = MInt(1)
    }
    val num = MOD.regular(raw)

    operator fun plus(other: Int): MInt = MInt(num ma other)
    operator fun minus(other: Int): MInt = MInt(num ms other)
    operator fun times(other: Int): MInt = MInt(num mm other)
    operator fun div(other: Int): MInt = MInt(num md other)

    operator fun plus(other: Long): MInt = MInt(num ma other)
    operator fun minus(other: Long): MInt = MInt(num ms other)
    operator fun times(other: Long): MInt = MInt(num mm other)
    operator fun div(other: Long): MInt = MInt(num md other)

    operator fun plus(other: MInt): MInt = MInt(num ma other.num)
    operator fun minus(other: MInt): MInt = MInt(num ms other.num)
    operator fun times(other: MInt): MInt = MInt(num mm other.num)
    operator fun div(other: MInt): MInt = MInt(num md other.num)

    fun pow(exp: Int) = MOD.pow(num.toLong(), exp.toLong()).toMInt()
    fun pow(exp: Long) = MOD.pow(num.toLong(), exp).toMInt()

    fun toInt(): Int {
        return num
    }

    override fun toString(): String {
        return num.toString()
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false
        other as MInt
        return num == other.num
    }

    override fun hashCode(): Int {
        return num
    }

    operator fun compareTo(other: MInt): Int = num.compareTo(other.num)
    operator fun compareTo(other: Int): Int = num.compareTo(other)
    operator fun compareTo(other: Long): Int = num.compareTo(other)
}
class MIntArray(size: Int, init: (Int) -> Int = { 0 }) : Iterable<MInt>, Cloneable {
    val raw = IntArray(size, init)
    val size = raw.size

    constructor(array: IntArray) : this(array.size, { array[it] })

    operator fun get(index: Int): MInt = raw[index].toMInt()

    operator fun set(index: Int, value: MInt) {
        raw[index] = value.num
    }

    override fun iterator(): Iterator<MInt> {
        return object : Iterator<MInt> {
            private var idx = 0

            override fun hasNext(): Boolean {
                return idx < size
            }

            override fun next(): MInt {
                return raw[idx++].toMInt()
            }
        }
    }

    public override fun clone(): MIntArray {
        return MIntArray(raw.clone())
    }
}
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
            globalMod = mod
            val res = process(Companion)
            globalMod = 0
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
fun MIntArray.fill(element: Int, fromIndex: Int = 0, toIndex: Int = size) {
    java.util.Arrays.fill(this.raw, fromIndex, toIndex, element)
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
infix fun Int.ma(other: Long): Int = MOD.add(this, MOD.regular(other))
infix fun Int.ma(other: Int): Int = MOD.add(this, other)
infix fun Int.md(other: Long): Int = MOD.div(this, MOD.regular(other))
infix fun Int.md(other: Int): Int = MOD.div(this, other)
typealias mint = MInt
infix fun Int.mm(other: Long): Int = MOD.mul(this, MOD.regular(other))
infix fun Int.mm(other: Int): Int = MOD.mul(this, other)
infix fun Int.ms(other: Long): Int = MOD.sub(this, MOD.regular(other))
infix fun Int.ms(other: Int): Int = MOD.sub(this, other)
fun Int.toMInt(): MInt = MInt(this)
inline fun <T> withMod(mod: Int, process: MOD.Companion.() -> T): T {
    return MOD.decorate(mod, process)
}
inline fun miar(size: Int, crossinline init: (Int) -> Int = { 0 }) = MIntArray(size) { init(it) }

/**
 * generated by kotlincputil@tauros
 */
fun main(args: Array<String>) {
    // https://codeforces.com/problemset/problem/1152/D
    // 不会做，很神奇，同深度且括号前缀和值相同的连出去的边肯定是一样的，子树肯定也是一样的，但是要取模不会比大小
    // 答案是贪心，先从叶子节点往上选边，一层一层隔着选，那么总答案就是深度为奇数点的个数，解释：
    // - 由于选的任何一条边一定是覆盖一个深度为奇数的点和一个深度为偶数的点，根节点深度为0
    // - 所以答案最多不会超过min(evenCnt, oddCnt)
    // - 由于叶子节点深度为偶数，那么evenCnt >= oddCnt是成立的，所以最多只能取到oddCnt，那么看能不能取到
    // - 考虑从叶子节点开始，每次都努力连它的父节点，那么所有深度为2n的节点可以把所有深度为2n-1的节点抢完，然后剥去下面两层，循环执行这个逻辑
    // - 上一步的逻辑要注意不是所有深度为2n的节点能被匹配，但是所有2n-1的节点都它被其中一个儿子抢走了
    // - 因此可以取满oddCnt，dp计算下oddCnt即可
    val n = readln().toInt()
    withMod(1e9.toInt() + 7) {
        val cnt = ar(2) { miar(n + 1) }
        cnt[0][0] = mint.ONE
        var cur = 0
        var ans = mint.ZERO
        for (len in 1 .. 2 * n) {
            val pre = cur; cur = 1 - cur
            cnt[cur].fill(0)
            for (top in 0 .. n) {
                val rest = 2 * n - len
                if (top > rest || (rest - top) % 2 == 1) continue
                if (top > 0) cnt[cur][top] += cnt[pre][top - 1]
                if (top < n) cnt[cur][top] += cnt[pre][top + 1]
                if (len % 2 == 1) {
                    ans += cnt[cur][top]
                }
            }
        }
        println(ans)
    }
}