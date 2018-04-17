#include <bits/stdc++.h>
#include "./src/busqueda.hh"

using namespace std;

int main(){
	int nodes,edges;
	node start,final;
	cin>>nodes>>edges;
	vvii graph(26); 
	cin>>start.index>>final.index;
	start.rute+=start.index;
	start.weight=0;
	final.rute+=final.index;
	final.weight=0;
	while(edges--){
		int weight;
		char index,neighbor;
		node tmp;
		cin>>index>>neighbor>>weight;
		tmp.index=neighbor;
		tmp.rute=neighbor;
		tmp.weight=weight;
		graph[index-'A'].push_back(tmp);
	}
	int t;
	cin>>t;
	if(t==1){	
		cout<<"DFS:::::::::::::::::::::::::::::::::::::::::\n";
		dfs(start,final,graph);
	}else{	
		cout<<"BFS:::::::::::::::::::::::::::::::::::::::::\n";
		bfs(start,final,graph);
	}
	cout<<"UCS:::::::::::::::::::::::::::::::::::::::::\n";
	ucs(start,final,graph);
	return 0;
}