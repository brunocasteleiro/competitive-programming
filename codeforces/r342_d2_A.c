// Round 342 (Div. 2)
// A. Guest From the Past
#include <stdio.h>

int main()
{
    long long n, a, b, c, maxi;

    scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &c);    

    if(a>b-c && b<=n)
    {
	maxi = (n-b)/(b-c)+1; // numero de garrafas de vidro que se pode comprar com (b-c) rubles
        maxi += (n-maxi*(b-c))/a; // somar numero de garrafas de plastico que se pode comprar com os rubles que sobraram
    } 
    else
    {
	maxi = n/a;
    }

    printf("%I64d", maxi);

    return 0;
}
