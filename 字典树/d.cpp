/*
hdu 1671

Problem Description
Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let¡¯s say the phone catalogue listed these numbers:
1. Emergency 911
2. Alice 97 625 999
3. Bob 91 12 54 26
In this case, it¡¯s not possible to call Bob, because the central would direct your call to the emergency line as soon as you had dialled the first three digits of Bob¡¯s phone number. So this list would not be consistent.
 

Input
The first line of input gives a single integer, 1 <= t <= 40, the number of test cases. Each test case starts with n, the number of phone numbers, on a separate line, 1 <= n <= 10000. Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.
 

Output
For each test case, output ¡°YES¡± if the list is consistent, or ¡°NO¡± otherwise.
 

Sample Input
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
 

Sample Output
NO
YES
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node{
	int a;
	node *next[10];
}*root;

string num[10010];

int insert(string s){
	node *tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'0';
		if(tmp->next[p]==NULL)
			tmp->next[p]=new node();
		tmp=tmp->next[p];
		tmp->a++;
	}
	if(tmp->a==1)
		return 1;
	else
		return 0;
}

void clear(node *r){
	for(int i=0;i<10;i++){
		if(r->next[i]){
			clear(r->next[i]);
		}
	}
	delete(r);
	r=NULL;
}

int cmp(string s1,string s2){
	return s1.length()>s2.length();
}

int main(){
	//root=new node(); 
	int t,n,flag;
	cin>>t;
	while(t--){
		root=new node();
		flag=1;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		sort(num,num+n,cmp);
		for(int i=0;i<n;i++){
			if(!insert(num[i])){
				cout << "NO" << endl;
				flag=0;
				break;
			}
		}
		if(flag)
			cout << "YES" << endl;
		clear(root);
	}
}
