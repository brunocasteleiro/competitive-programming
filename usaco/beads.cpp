/*
ID: bruno.c2
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("beads.in");
	ofstream out("beads.out");

	int N, w, c, best, prev;
	string neck;
	char color;

	in >> N >> neck;
	neck += neck;

	best = prev = w = c = 0;
	color = neck[0];

	for(int i=0; i<N*2; i++)
	{
		if(neck[i] == 'w')
			w++;
		else
		{
			c += w;

			if(neck[i] != color)
			{
				best = max(best, c+prev);
				prev = c-w;
				c=w+1;
				color = neck[i];
			}
			else
				c++;

			w=0;
		}
	}

	best = max(best, c+w+prev);
	out << ((best>N) ? N : best) << endl;

	in.close();
	out.close();
} // no need for return 0 in C++