/*
There are N villages, which are numbered from 1 to N, and you should build some roads such that every two villages can connect to each other. We say two village A and B are connected, if and only if there is a road between A and B, or there exists a village C such that there is a road between A and C, and C and B are connected. 

We know that there are already some roads between some villages and your job is the build some roads such that all the villages are connect and the length of all the roads built is minimum. 
Input
The first line is an integer N (3 <= N <= 100), which is the number of villages. Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance (the distance should be an integer within [1, 1000]) between village i and village j. 

Then there is an integer Q (0 <= Q <= N * (N + 1) / 2). Then come Q lines, each line contains two integers a and b (1 <= a < b <= N), which means the road between village a and village b has been built. 
Output
You should output a line contains an integer, which is the length of all the roads to be built such that all the villages are connected, and this value is minimum. 
Sample Input
3
0 990 692
990 0 179
692 179 0
1
1 2
Sample Output
179
*/


#include <bits/stdc++.h>
using namespace std;
int d[105],v[105];
int len[105][105];
int n,q;

int prime(){
	int res=0;
	v[1]=1;
	for(int i=1;i<=n;i++){
		d[i]=len[1][i];
	}
	for(int i=1;i<n;i++){
		int min=INT_MAX,v1;
		for(int j=1;j<=n;j++){
			if(min>d[j]&&v[j]==0){
				min=d[j];
				v1=j;
			}
		}
		v[v1]=1;
		res+=min;
		//cout << "r:" << res << " min:" << min << "v:" << v1 << endl;
		for(int j=1;j<=n;j++){
			if(d[j]>len[v1][j]&&v[j]==0)
				d[j]=len[v1][j];
		}
	}
	return res;
}

int main(){
	int a,b;
	while(cin >> n){
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> len[i][j];
			}
		}
		cin >> q;
		for(int i=0;i<q;i++){
			cin >> a >> b;
			len[a][b]=0;
			len[b][a]=0;
		}
		int res = prime();
		cout << res << endl;
	}
}
