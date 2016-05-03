#include <stdio.h>
#include <algorithm>

#define MAXN 100000

int bsearch(int lo, int hi, int nCows, int stallPos[], int nStalls);

int main()
{
    int t, N, C, stalls[MAXN];
    int i, j, yato;

    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
	scanf("%d %d", &N, &C);
	for(j=0; j<N; j++)
	    scanf("%d", &stalls[j]);
	
	std::sort(stalls, stalls+N);

	yato = bsearch(1, stalls[N-1]-stalls[0], C, stalls, N);
	printf("%d\n", yato);
    }

    return 0;
}

/*
  Find the last NUMBER in range [lo, hi] such that this predicate is true:
  Can all the cows be assigned at a minimum distance NUMBER between any
  two of them?
*/
int bsearch(int lo, int hi, int nCows, int stallPos[], int nStalls)
{
    int i;

    while(lo<hi)
    {
	int mid = lo+(hi-lo+1)/2;
	int usedCows = 1, lastCowPos = 0;
	
	for(i=1; i<nStalls; i++)
	{
	    if(stallPos[i]-stallPos[lastCowPos] >= mid)
	    {
		usedCows++;
		lastCowPos = i;
	    }
	}

	if(usedCows >= nCows)
	    lo = mid;
	else 
	    hi = mid-1;
    }

    return lo;
}
