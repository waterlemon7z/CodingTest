fun main()
{
    for(i in 1..2)
    {
        val (a, b, c, d, e) = readln().split(" ").map { it.toInt() }
        print("${a*6+b*3+c*2+d*1+e*2} ")
    }
}