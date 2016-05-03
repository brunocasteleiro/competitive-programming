/*
ID: bruno.c2
LANG: C
TASK: friday
*/

#include <stdio.h>

int isLeap(int year);

int main()
{
	FILE *in = fopen("friday.in", "r");
	FILE *out = fopen("friday.out", "w");

	int i, j, day=13, N;
	int freq[7]={0}, // 0=sunday
		months[12]={31,0,31,30,31,30,31,31,30,31,30,31}; 

	fscanf(in, "%d", &N);
	for(i=1900; i<1900+N; i++)
	{
		months[1] = isLeap(i) ? 29 : 28;
		for(j=0; j<12; j++)
		{
			freq[day%7]++;
			day+=months[j]; // tracking day count
		}
	}

	fprintf(out, "%d", freq[6]);
	for(i=0; i<6; i++)
		fprintf(out, " %d", freq[i]);
	fprintf(out, "\n");

	fclose(in);
	fclose(out);

	return 0;
}

int isLeap(int year)
{
	return (year%100 == 0) ? (year%400 == 0) : (year%4 == 0);
}