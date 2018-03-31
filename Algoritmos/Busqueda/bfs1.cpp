#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int leerX(vector<int> nodes[],int edges){
	int a,b;
	
	
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
}

int imprimir(vector<int> nodes[], int edges){
	for(int i=0;i<1000;i++){
		if(!nodes[i].empty()){
			cout<<"[ "<<i<<" ]"<<"-->";
			for(vector<int>::iterator it=nodes[i].begin(); it!=nodes[i].end();++it){
				cout<<*it<<"-->";
			}
			cout<<"NULL"<<endl;
		}	
	}
}

int visitar(queue<int> que, bool visited[1000], vector<int> nodes[]){
	
	
	
	// inicialmente todos los nodos no están visitados
	for(int i=0;i<1000;i++)
		visited[i]=false;

	int start;
	cout<<"\nEnter the starting node"<<endl;
	cin>>start;

	//indica por donde se desea empezar
	que.push(start);
	//señala los nodos visitados
	visited[start]=true;


	cout<<"\nBFS Traversal\n";

	while(!que.empty()){
		//saca de la cola para imprimir
		int front = que.front();
		cout<<front<<" ";
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