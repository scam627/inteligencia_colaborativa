#include <bits/stdc++.h>

using namespace std;

//-----------------------------------------------------------------//
// Declaracion de las clases necesarias para ejecutar el algoritmo //
//_________________________________________________________________//

class point{
private:
	int x,y;
public:
	point(){}
	point(int X,int Y): x(X), y(Y){}
	int distsqrt(const point &b){
		return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	}
	double dist(const point &b){
		return sqrt(distsqrt(b));
	}
	~point(){}
};

class k_medioids{
private:
	int k;
	vector<point> medioids;
	vector<pair<point,int>> points;
	vector<vector<double>> distances;
	vector<pair<double,int>> sigma;
public:
	k_medioids(){}
	k_medioids(int K,int n): k(K){
		medioids.resize(K);
		points.resize(n);
		distances.resize(n);
		sigma.resize(n);
	}
	void add_point(const point &a,int i){
		pair<point,int> tmp(a,0);
		points[i]=tmp;
	}
	void floyd_distances(){
		assert(points.size() > 1);
		for(int i=0 ;i < points.size(); i++){
			for(int j=i+1 ; j < points.size() ; j++){
				double distance = points[i].first.dist(points[j].first);
				pair<double, int> distance_i(distance,i);
				pair<double, int> distance_j(distance,j);
				distances[i].push_back(distance);
				sigma[i].first+=distance_i.first;
				sigma[i].second=distance_i.second;
				sigma[j].first+=distance_j.first;
				sigma[j].second=distance_j.second;
			}
		}
		sort(sigma.begin(), sigma.end());
	}
	vector<pair<double,int>>& get_sigma(){
		assert(sigma.size());
		return sigma;
	};
	void average_sigma(){
		for (int i=0; i < sigma.size(); i++)
			sigma[i].first/=(points.size()-1);
	}
	~k_medioids(){}
};

//-----------------------------------------------------------------//
// Declaracion de las clases necesarias para ejecutar el algoritmo //
//_________________________________________________________________//

int main(){
	int n;
	cin>>n;
	k_medioids clasificador(2,n);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		point tmp(x,y);
		clasificador.add_point(tmp,i);
	}
	clasificador.floyd_distances();
	vector<pair<double,int>> sigma=clasificador.get_sigma();
	for(auto item : sigma)
		cout<<setprecision(5)<<fixed<<item.first<<" tag: "<<item.second<<" ";
	cout<<"\n";
	return 0;
}