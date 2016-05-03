// Round 344 (Div. 2)
// B. Print Check
#include <stdio.h>

// prototypes
int max(int n1, int n2);

int main()
{
	int i, j, n, m, k, type, index, color;
	int colors[100001], r[5001] = {0}, c[5001] = {0};

	scanf("%d %d %d", &n, &m, &k);
	colors[0] = 0;

	for(i=1; i<=k; i++)
	{
		scanf("%d %d %d", &type, &index, &color);
		colors[i] = color; // guardar a cor que ocorreu na query #i (instante i)	

		// só nos interessa a última ocorrência de cada linha ou coluna (pois a pintura vai sobrepor as anteriores)
		// portanto vamos guardar o instante da query em que a mesma ocorreu
		// no valor de index r(linha) ou c(coluna) da respetiva query
		if(type == 1)
			r[index] = i;
		else
			c[index] = i;
	}

	// imprimir pintura final
	// para cada (x,y), seja ins[a] = instante da última ocorrência de a:
	// 		-> se ins[x] > ins[y] = cor[ins[x]]
	//		-> se ins[y] > ins[x] = cor[ins[y]]
	for(i=1; i<=n; i++)
	{
		printf("%d", colors[max(r[i],c[1])]);
		for(j=2; j<=m; j++)
		{
			printf(" %d", colors[max(r[i],c[j])]);
		}
		puts("");
	}

	return 0;
}

int max(int n1, int n2)
{
	return (n1 > n2) ? n1 : n2;
}
