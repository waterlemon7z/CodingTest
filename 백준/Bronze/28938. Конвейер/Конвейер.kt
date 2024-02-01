fun main()
{
    var rst : Int = 0
     readln().toInt()
    val arr = readln().split(" ").map{it.toInt()}
    for (i in arr)
    {
        rst += i
    }
    if(rst < 0)
    {
        print("Left")
    }
    else if(rst == 0)
    {
        print("Stay")
    }
    else
    {
        print("Right")
    }
}