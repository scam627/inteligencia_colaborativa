#include <bits/stdc++.h>

using namespace std;

int peak(int l,int r){
	if(l!=r){	
		if(a[n/2]<a[n/2-1])
			peak(l,n/2-1);
		else if(a[n/2]<a[n/2+1])
			peak(n/2+1,r);
		else
			return n/2;
	}else{
		return -1;
	}
}

int main(){
	return 0;
}