#include<bits/stdc++.h>
using namespace std; 
int dirx[]={2, 2, -2, -2, 1, -1, 1, -1};
int diry[]={1, -1, 1, -1, 2, 2, -2, -2};
bool isSafe(int N, int M, int x, int y)
{
	if(x>=1 && y>=1 && x<=N && y<=M)
		return true;
	return false;
}
int bfs_knight(int N, int M, int x1, int y1, int x2, int y2)
{
	queue<pair<pair<int, int>,int>> q;
	q.push({{x1, y1},0});
	bool vis[N+2][M+2];
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	while(!q.empty())
	{
		int x=q.front().first.first;
		int y=q.front().first.second;
		int dis = q.front().second;
		if(x==x2 && y==y2)
			return dis;
		if(isSafe(N, M, x, y) && !vis[x][y])
		{
			vis[x][y]=true;
			for(int i=0; i<8; i++)
			{
				q.push({{x+dirx[i], y+diry[i]}, dis+1});
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	int a, b, r1, c1, r2, c2;
	cout<<"Enter the rows of board"<<endl;
	cin>>a;
	cout<<"Enter the columns of board"<<endl;
	cin>>b;
	cout<<"Enter the row and column of source"<<endl;
	cin>>r1>>c1;
	cout<<"Enter the row and column of destination"<<endl;
	cin>>r2>>c2;
	int res = bfs_knight(a, b, r1, c1, r2, c2);
	cout<<"Result is "<<res<<endl;
}