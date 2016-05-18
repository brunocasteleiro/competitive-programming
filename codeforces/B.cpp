#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, d;
    long long int sols=0;
    cin >> n >> a >> b >> c >> d;

    for(int i=1; i<=n; i++)
    {
        int tr = i+b-c;
	int bl = i+a-d;
	int br = i+a+b-c-d;

	if(tr>=1 && tr<=n && bl>=1 && bl<=n && br>=1 && br<=n)
	    sols++;
    }

    cout << (sols*n) << endl;
}
