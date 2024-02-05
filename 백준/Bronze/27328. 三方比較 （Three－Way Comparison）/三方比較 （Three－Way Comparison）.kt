fun main()
{
    val N = readln().toInt()
    val S = readln().toInt()
    if(N<S)
        print(-1)
    else if(N == S)
        print(0)
    else
        print(1)
}