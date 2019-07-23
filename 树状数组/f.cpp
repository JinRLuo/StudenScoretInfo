#include <iostream>
#define ll long long
using namespace std;

ll a[500010];
ll b[500010];
ll res;

void merge_sort(ll* A,int x,int y,ll* T){
	if(y-x>1){
		int m=x+(y-x)/2;
		int p=x,q=m,i=x;
		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);
		while(p<m||q<y){
			if(q>=y||(p<m&&A[p]<A[q]))
				T[i++]=A[p++];
			else{
				T[i++]=A[q++];
				res+=m-p;
			}
		}
		for(int k=x;k<y;k++)
			A[k]=T[k];
	}
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		res=0;
		merge_sort(a,0,n,b);
		cout << res << endl;
	}
}
