fun main()
{
    var rst = 0
    val arr: List<Int> = readln().split(" ").map{it.toInt()}
    for(i in arr)
    {
        rst += i * 5
    }
    println(rst)
}