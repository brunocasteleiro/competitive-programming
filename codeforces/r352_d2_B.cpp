#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n, changes;
    cin >> n;
    char input[n+1];
    scanf("%s", input);
    if(n > ('z'-'a'+1))
    {
	cout << "-1" << endl;
	return 0;
    }
    changes = 0;
    for(int i=0; i<n; i++)
    {
	if(input[i] == '*') continue;
	for(int j=i+1; j<n; j++)
	{
	    if(input[j] == input[i])
	    {
		changes++;
		input[j] = '*';
	    }
	}
    }
    cout << changes << endl;
}
