fun main()
{
    var rstMax : Int = 0
    var rstMel : Int = 0
    val (a,b,c) = readln().split(" ").map{it.toInt()}
    rstMax += 3 * a
    rstMax += 20 * b
    rstMax +=120 * c
    val (a1,b1,c1) = readln().split(" ").map{it.toInt()}
    rstMel += 3 * a1
    rstMel += 20 * b1
    rstMel +=120 * c1
    if(rstMax > rstMel)
    {
        print("Max")
    }
    else if(rstMax < rstMel)
    {
        print("Mel")
    }
    else
    {
        print("Draw")
    }
}