#include <bits/stdc++.h>
using namespace std;

int N;
int tree[50010];

int lowbit(int x){
	return x&-x;
}

void add(int k,int x){
	for(int i=k;i<=N;i+=lowbit(i)){
		tree[i]+=x;
	}
}

int sum(int x){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)){
		res+=tree[i];
	}
	return res;
}

int main(){
	int c=1;
	int m,n;
	int T;
	string s;
	cin >> T;
	while(T--){
		memset(tree,0,sizeof(tree));
		cin>>N;
		for(int i=1;i<=N;i++){
			cin >> m;
			add(i,m);
		}
		cout << "Case " << c << ":" << endl;
		while(cin>>s){
			if(s=="Query"){
				cin >> m >> n;
				cout << sum(n)-sum(m-1) << endl;
			}else if(s=="Add"){
				cin >> m >> n;
				add(m,n);
			}else if(s=="Sub"){
				cin >> m >> n;
				add(m,-n);
			}else if(s=="End")
				break;
		}
		c++;
	}
}
