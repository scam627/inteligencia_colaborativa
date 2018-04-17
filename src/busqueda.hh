#ifndef __BUSQUEDA_HH__
#define __BUSQUEDA_HH__

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

void dfs(node start,node final,vvii graph){
	stack<node> storage;
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

#endif