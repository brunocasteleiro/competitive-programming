/*
ID: bruno.c2
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <string.h>

#define MAXN 10

// a struct é usada para representar o input.
// é conveniente porque as structs são passadas
// por valor ás funções, e não por referência como as matrizes,
// isto torna mais fácil a criação de métodos
// como o rotate ou o reflect que retornam "boards" alteradas.
typedef struct board
{
    int n;
    char m[MAXN+1][MAXN+1]; // MAXN + 1(NULL) para facilitar na leitura de input (ler como string)
}
Board;

int boardcmp(Board b1, Board b2);
Board rotate90(Board b);
Board reflect(Board b); 

int main()
{
    FILE *in = fopen("transform.in", "r");
    FILE *out = fopen("transform.out", "w");

    int i;
    int N, ans;
    Board orig, transf;

    fscanf(in, "%d", &N);
    orig.n   = N;
    transf.n = N;

    for(i=0; i<N; i++)
	fscanf(in, "%s", orig.m[i]);

    for(i=0; i<N; i++)
	fscanf(in, "%s", transf.m[i]);
    
    if( boardcmp(transf, rotate90(orig)) ) // rotate 90
	ans = 1;
    else if( boardcmp(transf, rotate90(rotate90(orig))) ) // rotate 180
	ans = 2;
    else if( boardcmp(transf, rotate90(rotate90(rotate90(orig)))) ) // rotate 270
	ans = 3;
    else if( boardcmp(transf, reflect(orig)) ) // reflection
	ans = 4;
    else if( boardcmp(transf, rotate90(reflect(orig)))           || 	     // reflection + rotate 90
	     boardcmp(transf, rotate90(rotate90(reflect(orig)))) || 	     // reflection + rotate 180
	     boardcmp(transf, rotate90(rotate90(rotate90(reflect(orig))))) ) // reflection + rotate 270
	ans = 5;
    else if( boardcmp(transf, orig) ) // no transformation
	ans = 6;
    else
	ans = 7;

    fprintf(out, "%d\n", ans);
   
    fclose(in);
    fclose(out);

    return 0;
}

int boardcmp(Board b1, Board b2)
{
    int i, j;

    if(b1.n != b2.n) return 0;

    for(i=0; i<b1.n; i++)
	for(j=0; j<b1.n; j++)
	    if(b1.m[i][j] != b2.m[i][j])
		return 0;

    return 1; // equal patterns
}

Board rotate90(Board b)
{
    int i, j;
    Board ans;    

    for(i=0; i<b.n; i++)
	for(j=0; j<b.n; j++)
	    ans.m[i][j] = b.m[b.n-j-1][i];

    ans.n = b.n;
    return ans;
}

Board reflect(Board b)
{
    int i, j;
    Board ans;

    for(i=0; i<b.n; i++)
	for(j=0; j<b.n; j++)
	    ans.m[i][j] = b.m[i][b.n-j-1];

    ans.n = b.n;
    return ans;
}
