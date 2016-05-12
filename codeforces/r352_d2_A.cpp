#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n;
    char line[1005]="", tmp[5];
    cin >> n;
    for(int i=1, len=0; len<n; i++)
    {
	sprintf(tmp, "%d", i);
	len += strlen(tmp);
	strcat(line, tmp);
    }
    cout << line[n-1] << endl;
}
