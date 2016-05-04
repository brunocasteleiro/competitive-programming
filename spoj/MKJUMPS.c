#include <stdio.h>

#define MAXN 10

char table[MAXN][MAXN];
int maxSquaresReached;
int diri[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dirj[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void cleanTable(void);
void search(int posi, int posj, int reachedSquares);

int main()
{

	int N, nSquares, nCase=1, yato;
	int i, j, x, y;

	scanf("%d", &N);
	while(N != 0)
	{
		cleanTable();
		nSquares = 0;

		for(i=0; i<N; i++)
		{
			scanf("%d %d", &x, &y);
			for(j=x; j<x+y; j++, nSquares++)
				table[i][j] = '.';
		}

		maxSquaresReached = 0;
		search(0, 0, 0);

		yato = nSquares - maxSquaresReached; 
		printf("Case %d, %d %s can not be reached.\n", nCase++, yato, yato==1 ? "square" : "squares");

		scanf("%d", &N);
	}
	

	return 0;
}

void cleanTable(void)
{
	int i, j;
	for(i=0; i<MAXN; i++)
		for(j=0; j<MAXN; j++)
			table[i][j] = 'x';
}

void search(int posi, int posj, int reachedSquares)
{
	if( (posi >= MAXN || posi < 0) || 
		(posj >= MAXN || posj < 0) ||
		table[posi][posj] == 'x' ) // out of bounds or already visited
	{
		if(reachedSquares > maxSquaresReached)
			maxSquaresReached = reachedSquares;

		return;
	}

	table[posi][posj] = 'x'; // mark square as visited

	int dir;
	for(dir=0; dir<8; dir++)
		search(posi+diri[dir], posj+dirj[dir], reachedSquares+1);

	table[posi][posj] = '.'; // mark square as not visited
}
