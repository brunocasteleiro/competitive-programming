#include <iostream>
#include <string.h>

#define MAXRC 100
#define LENWORD 10

int R, C;
int dirx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool visited[MAXRC][MAXRC];
char table[MAXRC][MAXRC+1], target[LENWORD+1]="ALLIZZWELL";

bool dfs(int x, int y, int sLen);

using namespace std;

int main()
{
    int t;
    cin >> t;
    memset(visited, 0, sizeof visited);
    for(int i=0; i<t; i++)
    {
	cin >> R >> C;
	for(int j=0; j<R; j++)
	    cin >> table[j];

	bool found = false;
	for(int x=0; x<R; x++)
	{
	    for(int y=0; y<C; y++)
	    {
		if( dfs(x, y, 0) )
		{
		    found = true;
		    break;
		}
	    }

	    if(found) break;
	}

	cout << (found ? "YES" : "NO") << endl;
    }
}

bool dfs(int x, int y, int sLen)
{
    if(visited[x][y] || table[x][y] != target[sLen])
	return false;

    if(sLen == LENWORD-1)
	return true;

    visited[x][y] = true;
    for(int i=0; i<8; i++)
    {
	int nx = x+dirx[i];
	int ny = y+diry[i];

	if(nx>=0 && nx<R && ny>=0 && ny<C)
	{
	    if( dfs(nx, ny, sLen+1) )
	    {
		visited[x][y] = false;
		return true;
	    }
	}
    }

    visited[x][y] = false;
    return false;
}
