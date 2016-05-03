// Round 344 (Div. 2)
// C. Report
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main()
{
    int i, j, n, m, t, r, trCount, left, right;
    int tr[200000][2];
    
    scanf("%d %d", &n, &m);
    int commodities[n];

    for(i=0; i<n; i++)
	scanf("%d", &commodities[i]);
    
    // ler querys de forma a ficar apenas com as necessárias
    // uma query com i elems é descartável se nas querys seguintes vier uma 
    // com j elems e i<=j
    trCount=0;
    for(i=0; i<m; i++)
    {
	scanf("%d %d", &t, &r);
        while(trCount>0 && tr[trCount-1][1]<=r)
	{
	   trCount--;
	}

	tr[trCount][0] = t;
	tr[trCount][1] = r;
	trCount++;
    }
    
    left = 0;
    right = tr[0][1];
    tr[trCount][1] = 0;
    trCount++;
    
    // copiar apenas os elementos que vamos mexer dos commodities
    // para um array auxiliar
    int auxArray[right];
    for(i=0; i<right; i++)
	auxArray[i] = commodities[i];
    
    // fazer sort do array auxiliar para estar pronto a usar da melhor forma
    qsort(auxArray, right, sizeof(int), compare);
    
    // uma vez que temos uma lista de querys ordenadas
    // e um vetor auxiliar ordenado para nos ajudar,
    // conseguimos saber, para cada query, qual o numero de elementos
    // que não nos interessa estar a ordenar uma vez que a query
    // seguinte vai mexer neles, portanto mexemos apenas nos que interessam
    for(i=1; i<trCount; i++)
	for(j=tr[i-1][1]; j>tr[i][1]; j--)
	    commodities[j-1] = tr[i-1][0] == 1 ? auxArray[--right] : auxArray[left++];

    // output
    printf("%d", commodities[0]);
    for(i=1; i<n; i++)
    {
	printf(" %d", commodities[i]);
    }
    puts("");
    

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a) - (*(int*)b);
}
