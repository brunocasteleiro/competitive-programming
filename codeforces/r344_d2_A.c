// Round 344 (Div. 2)
// A. Interview
#include <stdio.h>
#define MAX 1005

// prototypes
void readArray(int *v, int n);
int f(int *v, int l, int r);

int main()
{
    int n, a[MAX], b[MAX];

    scanf("%d", &n);
    readArray(a,n);
    readArray(b,n);
    
    // the maximum value is always the whole sequence
    // because of this property:
    // x OR y >= x
    printf("%d\n", f(a,1,n) + f(b,1,n));

    return 0;
}

void readArray(int *v, int n)
{
    int i;
    for(i=1; i<=n; i++)
	scanf("%d", (v+i));
}

int f(int *v, int l, int r)
{
    int i, sum=0;
    for(i=l; i<=r; i++)
	sum |= *(v+i);

    return sum;
}
