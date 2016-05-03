#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100

using namespace std;

int main()
{
    int N, sols=0;
    int S[MAXN];
    vector<int> leqs, reqs;

    cin >> N;
    for(int i=0; i<N; i++)
	cin >> S[i];

    for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
	    for(int k=0; k<N; k++)
	    {
		leqs.push_back(S[i]*S[j]+S[k]);
		if(S[i] != 0)
		    reqs.push_back(S[i]*(S[j]+S[k]));
	    }

    sort(leqs.begin(), leqs.end());
    sort(reqs.begin(), reqs.end());

    vector<int>::iterator it, lo, hi, lo2, hi2;
    it = leqs.begin();
    while(it!=leqs.end())
    {
	lo = lower_bound(leqs.begin(), leqs.end(), *it);
	hi = upper_bound(leqs.begin(), leqs.end(), *it);
	lo2 = lower_bound(reqs.begin(), reqs.end(), *it);
	hi2 = upper_bound(reqs.begin(), reqs.end(), *it);
	sols += (hi-lo)*(hi2-lo2);
	it = hi;
    }
    
    cout << sols << endl;
}
