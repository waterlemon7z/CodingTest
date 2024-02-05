fun main()
{
    val (h,i,a,r,c) = readln().split(" ").map {it.toInt() }
    print(h*i - a*r*c)
}