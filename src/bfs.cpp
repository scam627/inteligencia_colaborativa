#include <bits/stdc++.h>

using namespace std;

struct node{
	char index;
	string rute;
	int weight;
};

typedef vector<node> vii;
typedef vector<vii> vvii;

void bfs(node start,node final,vvii graph){
	queue<node> storage;
	vector<bool> memo(graph.size(),false);
	storage.push(start);
	while(!storage.empty() and storage.front().index != final.index){
		node front=storage.front();
		memo[front.index-'A']=true;
		cout<<front.index<<" ";		// estado del tope de la cola
		storage.pop();
		for(auto item : graph[front.index-'A']){
			if(!memo[item.index-'A']){
				item.rute+=front.rute;
				item.weight+=front.weight;
				storage.push(item);
			}
		}
	}
	if(storage.empty())
		cout<<"Not solution\n";
	else
		cout<<storage.front().rute<<" "<<storage.front().weight<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--){	
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
		bfs(start,final,graph);
	}
	return 0;
}