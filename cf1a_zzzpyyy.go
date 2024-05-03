func average(salary []int) float64 {
    sort.Ints(salary)
    sum := 0
    for i := 1; i < len(salary) -1; i++ {
        sum += salary[i]
    }
    return float64(sum)/ float64(len(salary) -2)
}
