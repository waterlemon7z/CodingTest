import java.math.BigInteger

fun main(args: Array<String>) {
    var cur: String
    while(true)
    {
        cur = readln()
        val rst: BigInteger = BigInteger(cur)
        if(rst == BigInteger("0"))
            break
        if(rst%BigInteger("42")==BigInteger("0"))
        {
            println("PREMIADO")
        }
        else
            println("TENTE NOVAMENTE")
    }
}