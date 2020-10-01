#include <bits/stdc++.h>
using namespace std;

int MAX = 2e5+5;

void buildTree(int *tree,int *a,int index,int s,int e){
	// base Case
	if(s>e){
		return ;
	}
	
	// Base case - Leaf Node
	if(s==e){
		tree[index] = a[s];
		return;
	}
	
	// Recursive Case
	int mid = (s+e)/2;
	// Left Subtree
	buildTree(tree,a,2*index,s,mid);
	// Right Subtree
	buildTree(tree,a,2*index + 1,mid+1,e);
	
	int left = tree[2*index];
	int right = tree[2*index + 1];
	
	tree[index] = min(left,right);
	
}

// Return a min element from the tree lying in range qs and qe
int query(int *tree,int index,int s,int e,int qs,int qe){
	
	// No Overlap
	if(qs>e||qe<s){
		return INT_MAX;
	}
	
	// Total Overlap
	if(s>=qs && e<=qe){
		return tree[index];
	}	
	
	// Partial OVerlap
	int mid = (s+e)/2;
	int left = query(tree,2*index,s,mid,qs,qe);
	int right = query(tree,2*index+1,mid+1,e,qs,qe);
	return min(left,right);	
	
}

void updateNode(int *tree,int index,int s,int e,int i,int value){
	// No Overlap
	if(i<s || i>e){
		return ;
	}
	// Reached Leaf Node
	if(s==e){
		tree[index] = value;
		return;
	}
	// Lying in range - i is playing between s and e
	int mid = (s+e)/2;
	updateNode(tree,2*index,s,mid,i,value);
	updateNode(tree,2*index+1,mid+1,e,i,value);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
	 
}

// Incrementing every value in range by inc
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc){
	// No Overlap
	if(re<s || rs>e){
		return;
	}
	// Reached Leaf Node
	if(s==e){
		tree[index] += inc;
		return;
	}
	// Lying in Range - Call both sides
	int mid = (s+e)/2;
	updateRange(tree,2*index,s,mid,rs,re,inc);
	updateRange(tree,2*index+1,mid+1,e,rs,re,inc);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return; 
}

signed main(){

	int a[] = {1,4,-2,3};
	int n=4;

	int *tree = new int[4*n + 1];  // Max size of segment tree
	int index = 1;
	int s=0;
	int e = n-1;
	buildTree(tree,a,index,s,e);
	
	
	
	int no_of_q;
	cin>>no_of_q;
	
//	updateNode(tree,index,s,e,2,8);
	updateRange(tree,index,s,e,1,2,4);
	
	while(no_of_q--){
		int qe,qs;
		cin>>qs>>qe;
		cout<<query(tree,index,s,e,qs,qe)<<endl;
	}
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";	
}