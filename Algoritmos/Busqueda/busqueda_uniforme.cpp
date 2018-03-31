#include <bits/stdc++.h>

using namespace std;


struct node{
	char index;
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

void ufs(node start,node final,vvii graph){
	priority_queue<node> storage;
	vector<bool> memo(graph.size(),false);
	storage.push(start);
	while(!storage.empty() and storage.top().index != final.index){
		node tope=storage.top();
		memo[tope.index-'A']=true;
		cout<<tope.index<<" ";
		storage.pop();
		for(auto item : graph[tope.index-'A']){
			if(!memo[item.index-'A']){
				item.weight+=tope.weight;
				storage.push(item);
			}
		}
	}
	cout<<"\n";
}


int main(){
	int nodes,edges;
	node start,final;
	cin>>nodes>>edges;
	vvii graph(nodes+1);
	start.index='J';
	start.weight=0;
	final.index='E';
	final.weight=0;
	while(edges--){
		int weight;
		char index,neighbor;
		node tmp;
		cin>>index>>neighbor>>weight;
		tmp.index=neighbor;
		tmp.weight=weight;
		graph[index-'A'].push_back(tmp);
	}
	ufs(start,final,graph);
	/*for(auto item : graph){
		for(auto element : item)
			cout<<"vecino: "<<element.index<<" peso:"<<element.weight<<" ";
		cout<<"\n";
	}*/
	return 0;
}