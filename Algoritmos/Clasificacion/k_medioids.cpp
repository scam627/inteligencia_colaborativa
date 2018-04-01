#include <bits/stdc++.h>

using namespace std;

struct point{
	long long x,y;
	point() {}	
	point(long long X,long long Y): x(X), y(Y) {}	
};

typedef vector<point> vp;
typedef vector<vector<double long>> vd;

long long distsqrt(const point &a, const point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double long dist(const point &a, const point &b){
	return sqrt(distsqrt(a,b));
}

int main(){
	int n;
	cin>>n;
	vp data(n);
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		point tmp(x,y);
		data[i]=tmp;
	}
	vd distances(n);
	vector<pair<double long,long long>> average(n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			double long distance=dist(data[i],data[j]);
			pair<double long, long long> distance_i(distance,i);
			pair<double long, long long> distance_j(distance,j);
			distances[i].push_back(distance);
			average[i].first+=distance_i.first;
			average[i].second=distance_i.second;
			average[j].first+=distance_j.first;
			average[j].second=distance_j.second;
		}
	}
	for (int i=0; i < average.size(); i++)
		average[i].first/=(n-1);
	sort(average.begin(), average.end());
	for(auto item : average)
		cout<<setprecision(5)<<fixed<<item.first<<" tag: "<<item.second<<" ";
	cout<<"\n";
	return 0;
}