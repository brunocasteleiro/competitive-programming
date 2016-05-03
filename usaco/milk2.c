/*
ID: bruno.c2
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *pa, const void *pb);
int max(int n1, int n2);

int main()
{
    FILE *in = fopen("milk2.in", "r");
    FILE *out = fopen("milk2.out", "w");

    int i, j, N;
    
    fscanf(in, "%d", &N);
    int schedule[N][2];

    for(i=0; i<N; i++)
	fscanf(in, "%d %d", &schedule[i][0], &schedule[i][1]);

    qsort(schedule, N, sizeof(int)*2, compare); // ordena tempos
    
    int clean[N][2]; // matriz para guardar tempos sem sobreposição
    clean[0][0] = schedule[0][0];
    clean[0][1] = schedule[0][1];

    for(i=1,j=1; i<N; i++)
    {
	// se o tempo atual não se sobrepõe ao último adicionado
	// nos tempos sem sobreposição, então adicionamos o atual também
	if(schedule[i][0] > clean[j-1][1])
	{
	    clean[j][0] = schedule[i][0];
	    clean[j][1] = schedule[i][1];
	    j++;
	}
	else if(schedule[i][1] > clean[j-1][1])
	    // se o atual se sobrepõe mas ainda assim
	    // tem um tempo final maior, atualizamos
	    // o tempo final do último adicionado
	    clean[j-1][1] = schedule[i][1];
    }

    // percorrer tempos sem sobreposição
    // e descobrir 2 outputs resposta
    int idle=0, cont=0;
    for(i=0; i<j; i++)
    {
	cont = max(cont, clean[i][1]-clean[i][0]);
	if(i)
	    idle = max(idle, clean[i][0]-clean[i-1][1]);
    }
    
    fprintf(out, "%d %d\n", cont, idle);

    fclose(in);
    fclose(out);

    return 0;
}

int compare(const void *pa, const void *pb)
{ 
    const int *a = (const int *)pa;
    const int *b = (const int *)pb;
    
    if( *a == *b )
	return *(a+1) - *(b+1);

    return *a - *b;
}

int max(int n1, int n2)
{
    return n1>n2 ? n1 : n2;
}
