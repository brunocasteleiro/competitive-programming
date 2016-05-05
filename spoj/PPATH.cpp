/**
 * Judge: Spoj
 * Problem: Prime Path
 * Type: bfs
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPrime[10000];
bool visited[10000];

void runSieve();
int findCheapestPrimePath(int firstPrime, int lastPrime);

using namespace std;

int main()
{
	int ncases, prime1, prime2;
	cin >> ncases;
	runSieve();
	for(int i=0; i<ncases; i++)
	{
		cin >> prime1 >> prime2;
		cout << findCheapestPrimePath(prime1, prime2) << endl;
	}
}

void runSieve()
{
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i<10000; i++)
		isPrime[i] = true;
	
	int l = sqrt(10000);

	for(int i=2; i<=l; i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i; j<10000; j+=i)
				isPrime[j] = false;
		}
	}
}

int findCheapestPrimePath(int firstPrime, int lastPrime)
{
	int minPath=10000, gPrime;
	queue< pair<int,int> > q;
	char tmp[5];

	q.push( make_pair(firstPrime, 0) );
	memset(visited, 0, sizeof visited);

	while( !q.empty() )
	{
		pair<int,int> curNode = q.front();
		int curPrime = curNode.first;
		int curDepth = curNode.second;
		visited[curPrime] = true;
		q.pop();

		if(curPrime == lastPrime)
			minPath = min(minPath, curDepth);

		for(int i=0; i<4; i++)
		{
			for(int j=0; j<=9; j++)
			{
				if(i==0 && j==0) continue;
				if(i==3 && j%2==0) continue;

				sprintf(tmp, "%d", curPrime);
				tmp[i] = '0'+j;
				gPrime = (int)strtol(tmp, (char **)NULL, 10);

				if(!visited[gPrime] && isPrime[gPrime])
					q.push( make_pair(gPrime, curDepth+1) );
			}
		}
	}

	return minPath;
}
