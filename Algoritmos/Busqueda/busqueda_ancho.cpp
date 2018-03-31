#include<bits/stdc++.h>


using namespace std;

int leerX(vector<int> nodes[],int edges){
	char a,b;
	
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		nodes[a-'A'].push_back(b-'A');
		nodes[b-'A'].push_back(a-'A');
	}
}

int imprimir(vector<int> nodes[], int edges){
	for(int i=0;i<1000;i++){
		if(!nodes[i].empty()){
			cout<<"[ "<<char(i+65)<<" ]"<<"-->";
			for(vector<int>::iterator it=nodes[i].begin(); it!=nodes[i].end();++it){
				cout<<char(*it+65)<<"-->";
			}
			cout<<"NULL"<<endl;
		}	
	}
}

int visitar(queue<int> que, bool visited[1000], vector<int> nodes[]){
	
	
	
	// inicialmente todos los nodos no están visitados
	for(int i=0;i<1000;i++)
		visited[i]=false;

	char start;
	cout<<"\nEnter the starting node"<<endl;
	cin>>start;

	//indica por donde se desea empezar
	que.push(start-'A');
	//señala los nodos visitados
	visited[start-'A']=true;


	cout<<"\nBFS Traversal\n";

	while(!que.empty()){
		//saca de la cola para imprimir
		int front = que.front();
		cout<<char(front+65)<<" ";
		que.pop();
		

	for(vector<int>::iterator it=nodes[front].begin();
		it!=nodes[front].end();++it)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				que.push(*it);
			}
		}
	}
}



int main(){
	int edges;
	vector<int> nodes[1000];
	queue<int> que;
	bool visited[1000];

	cout<<"Enter the no of edges"<<endl;
	cin>>edges;

	leerX(nodes, edges);

	imprimir(nodes, edges);
	visitar(que, visited, nodes);

	cout<<endl;
	return 0;
}