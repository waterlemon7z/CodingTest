fun main()
{
    val (N, M) = readln().split(" ").map {it.toInt() }
    if(N * 100>=M)
    {
        println("Yes")
    }
    else
        println("No")
}