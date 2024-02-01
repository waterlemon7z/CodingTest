fun main()
{
    val (ur,tr,uo,to) = readln().split(" ").map{ it.toInt()}
    println(ur *  56 + tr * 24 + uo * 14 + to * 6)
}