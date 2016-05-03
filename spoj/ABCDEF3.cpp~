#include <algorithm>
#include <stdio.h>

#define MAXN 100 
#define MAXEQ 1000000

int first(int lo, int hi, int searchSpace[], int target);
int last(int lo, int hi, int searchSpace[], int target);

int main()
{
    int N;
    int S[MAXN], leftEq[MAXEQ], rightEq[MAXEQ];
    int i, x, y, z, lc, rc, sols, hil, lor, hir;

    scanf("%d", &N);
    
    for(i=0; i<N; i++)
	scanf("%d", &S[i]);
    
    // ((a*b+c)/d)-e=f  <=>  a*b+c=d*(f+e)
    // calc left & right side equation results
    lc = rc = 0;
    for(x=0; x<N; x++)
	for(y=0; y<N; y++)
	    for(z=0; z<N; z++)
	    {
		leftEq[lc++] = S[x]*S[y]+S[z];
		if(S[x]) // d<>0 (problem statement)
		    rightEq[rc++] = S[x]*(S[y]+S[z]);
	    }
    
    std::sort(leftEq, leftEq+lc);
    std::sort(rightEq, rightEq+rc);

    sols=0;
    for(i=0; i<lc; i++) 
    {
	hil = last(0, lc-1, leftEq, leftEq[i]);   // last leftEq[i] in leftEq
	hir = last(0, rc-1, rightEq, leftEq[i]);  // last leftEq[i] in rightEq
	lor = first(0, rc-1, rightEq, leftEq[i]); // first leftEq[i] in rightEq
	if(lor!=-1) sols += (hil-i+1)*(hir-lor+1);
	i=hil;
    }

    printf("%d\n", sols);
    return 0;
}

int compare(const void *va, const void *vb)
{
    return (*(const int*)va - *(const int*)vb);
}

int last(int lo, int hi, int searchSpace[], int target)
{
    int max = hi;
    while(lo<=hi)
    {
	int mid = (hi+lo)/2;

        if( (mid == max || target < searchSpace[mid+1]) && target == searchSpace[mid])
	    return mid;
	else if(target < searchSpace[mid])
	    hi = mid-1;
	else
	    lo = mid+1;
    }

    return -1;
}

int first(int lo, int hi, int searchSpace[], int target)
{
    while(lo<=hi)
    {
	int mid = (hi+lo)/2;
	
	if( (mid == 0 || target > searchSpace[mid-1]) && target == searchSpace[mid])
	    return mid;
	else if(target > searchSpace[mid])
	    lo = mid+1;
	else
	    hi = mid-1;
    }

    return -1;
}
