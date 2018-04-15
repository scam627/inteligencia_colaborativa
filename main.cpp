#include <bits/stdc++.h>
#include "./src/clasificacion.hh"

using namespace std;

//-----------------------------------------------------------------//
//                       Ejecucion del algoritmo                   //
//_________________________________________________________________//

int main(){
	int n,k;
	cin>>n>>k;
	k_medioids clasificador(k,n);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		point tmp(x,y);
		clasificador.add_point(tmp,i);
	}
	clasificador.initializate();
	clasificador.execute();
	point tmp(1,1);
	clasificador.insert_point(tmp);
	for(auto item : clasificador.get_groups()){	
		for(auto element : item)
			cout<<element<<" ";
		cout<<"\n";
	}
	return 0;
}