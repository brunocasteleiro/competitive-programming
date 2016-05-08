/*
ID: bruno.c2
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBase(int number, int base, char *convstore);
bool isPal(char *number);

using namespace std;

int main()
{
	ifstream in("palsquare.in");
	ofstream out("palsquare.out");

	int B;
	char outp1[20], outp2[20];
	
	in >> B;
	for(int i=1; i<=300; i++)
	{
		toBase(i*i, B, outp2);
		if( isPal(outp2) )
		{
			toBase(i, B, outp1);
			out << outp1 << " " << outp2 << endl;
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
	int len = strlen(number);
	char *beg, *end;

	for(beg=number, end=number+len-1; beg<end; beg++, end--)
		if(*beg != *end)
			return false;

	return true;
}