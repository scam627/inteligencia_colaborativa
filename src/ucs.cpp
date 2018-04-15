#include <bits/stdc++.h>

using namespace std;


struct node{
	char index;
	string rute;
	int weight;
	bool operator < (const node &other) const {
		if(other.weight < weight)
			return true;
		else
			return false;
	}
};

typedef vector<node> vii;
typedef vector<vii> vvii;

void ucs(node start,node final,vvii graph){
	priority_queue<node> storage;
	vector<bool> memo(graph.size(),false);
	storage.push(start);
	while(!storage.empty() and storage.top().index != final.index){
		node top=storage.top();
		memo[top.index-'A']=true;
		cout<<top.index<<" ";		// estado del tope de la cola
		storage.pop();
		for(auto item : graph[top.index-'A']){
			if(!memo[item.index-'A']){
				item.rute+=top.rute;
				item.weight+=top.weight;
				storage.push(item);
			}
		}
	}
	if(storage.empty())
		cout<<"Not solution\n";
	else
		cout<<storage.top().rute<<" "<<storage.top().weight<<"\n";
}


int main(){
	int nodes,edges;
	node start,final;
	cin>>nodes>>edges;
	vvii graph(nodes+1);
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
	ucs(start,final,graph);
	return 0;
}