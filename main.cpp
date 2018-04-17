#include <bits/stdc++.h>
#include "./src/clasificacion.hh"

using namespace std;

//-----------------------------------------------------------------//
//                       Ejecucion del algoritmo                   //
//_________________________________________________________________//

int main(){
	int n,k,x,y;
	cin>>n>>k;
	k_medioids clasificador(k,n);
	for(int i=0;i<n;i++){
		cin>>x>>y;
		//cout<<x<<" "<<y<<"\n";
		point tmp(x,y);
		clasificador.add_point(tmp,i);
	}
	clasificador.initializate();
	clasificador.execute();
	//cout<<"NEW POINT ::::::::::::::::::::::::::::\n";
	cin>>x>>y;
	point tmp(x,y);
	clasificador.insert_point(tmp);
	int tag=clasificador.get_points().back().second;
	vector<int> label(clasificador.get_medoids());
	for(int i=0;i < label.size();i++){
		if(label[i] == tag){
			//cout<<"Pertenece al grupo ";
			cout<<"\n"<<i;
		}
	}
	return 0;
}