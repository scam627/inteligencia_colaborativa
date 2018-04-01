#include <bits/stdc++.h>
using namespace std;

int puntos(vector<int> distances[],int n){
	int x,y;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		pair<int, int> pairPrueba(x,y);
		vector<pair<int, int>> Puntos;
		Puntos.push_back(pairPrueba);
	}
}

int distance(int x, int y){ //recibir vector de puntos acá
	double d =0;
	//int h=0,k=0;
	vector<int> Vdist;
	vector<pair<int, int>> Vpuntos;
	pair<int, int> pairPunto0(0,0);
	pair<int, int> pairPunto1(0,2);
	pair<int, int> pairPunto2(2,0);
	pair<int, int> pairPunto3(3,3);
	pair<int, int> pairPunto4(7,6);
	pair<int, int> pairPunto5(6,5);
	pair<int, int> pairPunto6(8,4);
	pair<int, int> pairPunto7(8,6);
	Vpuntos[0]= pairPunto0;
	Vpuntos[1]= pairPunto1;
	Vpuntos[2]= pairPunto2;
	Vpuntos[3]= pairPunto3;
	Vpuntos[4]= pairPunto4;
	Vpuntos[5]= pairPunto5;
	Vpuntos[6]= pairPunto6;
	Vpuntos[7]= pairPunto7;
	pair<int, int> pairPunto(x,y);
	Vpuntos.push_back(pairPunto);
	
	for(int i=0;i<7; i++){ //Vpuntos.size;
		d = pow((x - Vpuntos[i].first),2) + pow((y - Vpuntos[i].second),2);
		Vdist[i] = d;
	}


}

int main(){
	vector<pair<int, int>> Vdistances[100];
	//distance(1,2,Vdistances);
	distance(1,2);

	return 0;
	
	
}