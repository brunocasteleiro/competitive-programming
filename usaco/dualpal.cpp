/*
ID: bruno.c2
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string.h>

void toBase(int number, int base, char *convstore);
bool isPal(char *number);

using namespace std;

int main()
{
	ifstream in("dualpal.in");
	ofstream out("dualpal.out");

	int N, S, npal, sols=0;
	char outp[20];

	in >> N >> S;
	for(int i=S+1; sols<N; i++)
	{
		npal=0;
		for(int j=2; j<=10 && npal<2; j++)
		{
			toBase(i, j, outp);
			if( isPal(outp) )
				npal++;
		}

		if(npal == 2)
		{
			out << i << endl;
			sols++;
		}
	}

	in.close();
	out.close();
}

void toBase(int number, int base, char *convstore)
{
	if(number == 0)
	{
		*convstore = '\0';
		return;
	}

	toBase(number/base, base, convstore);

	char chars[] = "0123456789ABCDEFGHIJ";
	int len = strlen(convstore);
	convstore[len] = chars[number%base];
	convstore[len+1] = '\0';
}

bool isPal(char *number)
{
	int len=strlen(number);
	for(char *beg=number, *end=number+len-1; beg<end; beg++, end--)
		if(*beg != *end)
			return false;

	return true;
}