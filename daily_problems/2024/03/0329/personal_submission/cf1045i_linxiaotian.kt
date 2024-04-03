private fun palPairs(strings: List<String>): Long {
    val n = strings.size
    val m = 26
    val counter = Counter<Int>()
    var result = 0L
    for (str in strings) {
        val wordCount = wordToCharCount(str)
        var state = 0
        for (i in 0 until m) {
            if (wordCount[i] % 2 == 0) {
                state = state.setBit(i)
            }
        }
        // 一模一样
        result += counter.get(state)
        for (i in 0 until m) {
            if (state.isBit(i)) {
                // 只少一个 1
                val ns = state.clearBit(i)
                result += counter.get(ns)
            } else {
                // 只多一个 1
                val ns = state.setBit(i)
                result += counter.get(ns)
            }
        }
        counter.add(state)
    }
    return result
}
