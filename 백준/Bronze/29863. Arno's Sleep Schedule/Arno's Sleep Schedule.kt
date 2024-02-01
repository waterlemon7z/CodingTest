fun main()
{
    val N: Int = readln().toInt()
    var M: Int = readln().toInt()
    if(N > 4)
        M += 24
    print(M - N)
}