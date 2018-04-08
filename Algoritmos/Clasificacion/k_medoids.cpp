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
	vector<int> medioids;
	vector<pair<point,int>> points;				
	vector<vector<double>> distances;			
	//vector<pair<double,int>> sigma;
public:
	k_medioids(){}
	k_medioids(int K,int n): k(K){
		medioids.resize(K);
		points.resize(n);
		distances.resize(n);
		//sigma.resize(n);
	}

	void add_point(const point &a,int i){
		pair<point,int> tmp(a,0);
		points[i]=tmp;
	}

	void init_medioids(){
		vector<bool> memo(points.size(),false);
		srand(time(0));	
		int i=0;
		while(i<medioids.size()){
			int random=rand()%points.size();
			if(!memo[random]){
				medioids[i]=random;
				memo[random]=true;
				i++;
			}
		}
	}

	void execute(){
		bool stop=false;
		assert(points.size() > 1);
		init_medioids();
		floyd_distances();
		while(!stop){
			vector<vector<int>> groups(medioids.size());
			tag(groups);
			cout<<"Centroides:\n";
			for (int i = 0; i < medioids.size(); i++){
				cout<<medioids[i]<<" ";
			}
			cout<<"\n";
			cout<<"Groups:\n";
			for(auto x : groups){
				for(auto y : x)
					cout<<y<<" ";
				cout<<"\n";
			}
			stop = iteration(groups);
		}
	}

	//void average_sigma(){
	//	for (int i=0; i < sigma.size(); i++)
	//		sigma[i].first/=(points.size()-1);
	//}

	//vector<pair<double,int>>& get_sigma(){
	//	assert(sigma.size());
	//	return sigma;
	//};

	~k_medioids(){}

private:
	void tag(vector<vector<int>>& groups){
		vector<bool> memo(points.size(),false);
		for(int i=0;i<medioids.size();i++){
			memo[medioids[i]]=true;
			points[medioids[i]].second=medioids[i];
			groups[i].push_back(medioids[i]);
		}
		for(int i=0;i<points.size();i++){
			if(!memo[i]){
				double min=(1LL<<31)-1;
				int tag,index;
				cout<<i<<" -> ";	
				for(int j=0;j<medioids.size();j++){
					double tmp;
					if(medioids[j]<i)
						tmp=distances[medioids[j]][(i-medioids[j])-1];
					else
						tmp=distances[i][(medioids[j]-i)-1];
					cout<<tmp<<" ";
					if(tmp<min){
						index=j;
						min=tmp;
						tag=medioids[j];
					}
				}
				cout<<"\n";
				points[i].second=tag;
				groups[index].push_back(i);
				memo[i]=true;
			}
		}
		for(auto item : points)
			cout<<item.second<<" ";
		cout<<"\n";
	}
	void floyd_distances(){
		for(int i=0 ;i < points.size(); i++){
			for(int j=i+1 ; j < points.size() ; j++){
				double distance = points[i].first.dist(points[j].first);
				pair<double, int> distance_i(distance,i);
				pair<double, int> distance_j(distance,j);
				distances[i].push_back(distance);
				//sigma[i].first+=distance_i.first;
				//sigma[i].second=distance_i.second;
				//sigma[j].first+=distance_j.first;
				//sigma[j].second=distance_j.second;
			}
		}
		//sort(sigma.begin(), sigma.end());
	}
	bool iteration(vector<vector<int>>& groups){
		bool stop=true;
		int index=0;
		for(auto item : groups){
			vector<pair<double,int>> sigma(item.size());
			for(int i=0;i<item.size();i++){
				sigma[i].second=item[i];
				for(int j=i+1;j<item.size();j++){
					double tmp;
					if(item[j]<item[i])
						tmp=distances[item[j]][(item[i]-item[j])-1];
					else
						tmp=distances[item[i]][(item[j]-item[i])-1];
					sigma[i].first+=tmp;
					sigma[j].first+=tmp;
				}
			}
			cout<<"------------------------------------------------------------\n";
			cout<<" | ";
			for(auto x : sigma){
				cout<<x.first<<"->"<<x.second<<" | ";
			}
			cout<<"\n";
			sort(sigma.begin(),sigma.end());
			cout<<"New centroide should  will be: "<<sigma.front().second<<"\n";
			cout<<" | ";
			for(auto x : sigma){
				cout<<x.first<<"->"<<x.second<<" | ";
			}
			cout<<"\n";
			if(sigma.front().second!=medioids[index]){
				stop=false;
				medioids[index]=sigma.front().second;
			}
			index++;
		}
		cout<<"_________________________________________________________________\n";
		return stop;
		//sort(sigma.begin(), sigma.end());
	}
};

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
	clasificador.execute();
	//vector<pair<double,int>> sigma=clasificador.get_sigma();
	//for(auto item : sigma)
	//	cout<<setprecision(5)<<fixed<<item.first<<" tag: "<<item.second<<" ";
	//cout<<"\n";
	return 0;
}