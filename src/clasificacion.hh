#ifndef __CLASIFICACION_HH__
#define __CLASIFICACION_HH__

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
	vector<vector<int>> groups;		
public:
	k_medioids(){}
	k_medioids(int K,int n): k(K){
		medioids.resize(K);
		groups.resize(K);
		points.resize(n);
		distances.resize(n);
	}

	void add_point(const point &a,int i){
		pair<point,int> tmp(a,0);
		points[i]=tmp;
	}

	void insert_point(const point &a){
		pair<point,int> tmp(a,0);
		points.push_back(tmp);
		distances.resize(distances.size()+1);
		for(int i=0;i<points.size()-1;i++){
			double distance=tmp.first.dist(points[i].first);
			distances[i].push_back(distance);
		}
		tag_point();
	}

	void execute(){
		bool stop=false;
		assert(points.size() > 1 && distances[0].size()>0);
		while(!stop){
			cout<<"Computing Algorithm\n";
			//vector<vector<int>> gr(medioids.size());
			for(auto& element : groups)
				element.resize(0);
			tag();
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
			stop = iteration();
		}
	}
	void initializate(){
		init_medioids();
		floyd_distances();
	}
	vector<pair<point,int>>& get_points(){
		return points;
	}
	vector<vector<double>>& get_distances(){
		return distances;
	}
	vector<vector<int>>& get_groups(){
		return groups;
	}
	~k_medioids(){}

private:
	void tag_point(){
		double min=~(1LL<<63);
		int index,tag;
		for(int j=0;j<medioids.size();j++){
			double tmp;
			tmp=distances[medioids[j]][distances[medioids[j]].size()-1];
			if(tmp<min){
				index=j;
				min=tmp;
				tag=medioids[j];
			}
		}
		points[points.size()-1].second=tag;
		groups[index].push_back(points.size()-1);
		if(!iteration())
			execute();
	}
	void tag(){
		vector<bool> memo(points.size(),false);
		for(int i=0;i<medioids.size();i++){
			memo[medioids[i]]=true;
			points[medioids[i]].second=medioids[i];
			groups[i].push_back(medioids[i]);
		}
		for(int i=0;i<points.size();i++){
			if(!memo[i]){
				double min=~(1LL<<63);
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
				//pair<double, int> distance_i(distance,i);
				//pair<double, int> distance_j(distance,j);
				distances[i].push_back(distance);
			}
		}
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

	bool iteration(){
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
			cout<<"--------------------------------------------------------------------\n";
			cout<<" | ";
			for(auto x : sigma){
				cout<<x.first<<"->"<<x.second<<" | ";
			}
			cout<<"\n";
			sort(sigma.begin(),sigma.end());
			cout<<"New centroid should be: "<<sigma.front().second<<"\n";
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
		cout<<"FINAL ITERATION !!!\n";
		cout<<"____________________________________________________________________\n";
		return stop;
	}
};

#endif