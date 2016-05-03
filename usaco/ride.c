/*
ID: bruno.c2
LANG: C
TASK: ride
*/

#include <stdio.h>

#define LEN 7 // 6+1

int product(char *s);

int main()
{
    FILE *in = fopen("ride.in", "r");
    FILE *out = fopen("ride.out", "w");
    
    char comet[LEN], group[LEN];

    fscanf(in, "%s\n%s", comet, group);
    fprintf(out, "%s\n", (product(comet)%47 == product(group)%47) ? "GO" : "STAY");

    fclose(in);
    fclose(out);

    return 0;
}

int product(char *s)
{
    int mul=1;
    while(*s!='\0')
    {
	mul *= (*s-'A'+1);
	s++;
    }

    return mul;
}
   
