/*
ID: bruno.c2
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 13 // 12 + NULL

int main()
{
    FILE *dic = fopen("dict.txt", "r");
    FILE *in  = fopen("namenum.in", "r");
    FILE *out = fopen("namenum.out", "w");

    int hasAnswer;
    char keys['Z'], input[MAXLEN], fname[MAXLEN], *p, *q;
    
    // pre-compute keys matrix
    keys['A'] = keys['B'] = keys['C'] = '2';
    keys['D'] = keys['E'] = keys['F'] = '3';
    keys['G'] = keys['H'] = keys['I'] = '4';
    keys['J'] = keys['K'] = keys['L'] = '5';
    keys['M'] = keys['N'] = keys['O'] = '6';
    keys['P'] = keys['R'] = keys['S'] = '7';
    keys['T'] = keys['U'] = keys['V'] = '8';
    keys['W'] = keys['X'] = keys['Y'] = '9';

    // read input
    fscanf(in, "%s", input);
    
    // search for valid words
    hasAnswer = 0;
    while( !feof(dic) )
    {
	fscanf(dic, "%s", fname);

	// verify word
	for(p=input, q=fname; *p && *q; p++, q++) // *p && *q igual a *p!='\0' && *q!='\0' porque '\0' = 0 na tabela ascii
	    if(*p != keys[*q])
		break;

        if( *p == '\0' && *q == '\0'  )
	{
	    fprintf(out, "%s\n", fname);
	    hasAnswer=1;
	}
    }

    if(!hasAnswer)
	fprintf(out, "NONE\n");

    fclose(dic);
    fclose(in);
    fclose(out);

    return 0;
}
