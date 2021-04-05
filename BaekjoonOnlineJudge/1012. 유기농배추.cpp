// https://www.acmicpc.net/problem/1012
// 1012. 유기농배추

#include <iostream>

using namespace std;

void recursion(int i, int j, int M, int N);
void seeMap(int M, int N);
int** map;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

int main()
{

	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase)
	{
		// 입력 받기
		int M, N, K;
		cin >> M >> N >> K;
		map = new int*[N];
		for (int i = 0; i < N; i++)
		{
			map[i] = new int[M];
			memset(map[i], 0, sizeof(int) * M);
		}

		for (int cabbage = 0; cabbage < K; cabbage++)
		{
			int i, j;
			cin >> i >> j;
			map[j][i] = 1;
		}

		//seeMap(M, N);

		int worm = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					recursion(i, j, M, N);
					//seeMap(M, N);
					worm++;
				}
				
			}
		}
		
		cout << worm << endl;

		for (int i = 0; i < N; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}
	
	return 0;

}


void recursion(int i, int j, int M, int N)
{
	if (i<0 || i>=N || j<0 || j>=M)
		return;
	else if (map[i][j] == 0 || map[i][j] == -1)
		return;
	else 
	{
		map[i][j] = -1;	// 방문하면 -1
		recursion(i + dx[0], j + dy[0], M, N);	//위
		recursion(i + dx[1], j + dy[1], M, N);	//좌
		recursion(i + dx[2], j + dy[2], M, N);	//우
		recursion(i + dx[3], j + dy[3], M, N);	//아래
	}
}

void seeMap(int M, int N)
{
	//  배열 잘 들어갔나
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}
