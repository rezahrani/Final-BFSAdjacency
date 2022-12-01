class Graph{
	int numVertices;
	vector< vector<int> > adjList;
	
	public:
	//graph constructor
	Graph(int numVertices);
	//graph functions
	void addEdge(int u, int v);
	void BFS(int src);
};

//constructor
Graph::Graph(int numVertices){
	this->numVertices = numVertices;
	adjList.resize(numVertices);
}
void Graph::BFS(int src){
	//initialize all nodes as unvisited
	vector<bool> visited(numVertices, false);
	
	//initialize queue for bfs
	queue<int> q;
	
	//mark src node as visited and push to queue
	visited[src] = true;
	q.push(src);
	
	//loop until queue is empty
	while(!q.empty()){
		int temp = q.front();
		//print the visited nodes
		cout << "Visited: " << temp << endl;
		q.pop();
		
		//traverse adjlist
		for(int i = 0; i < adjList[temp].size(); i++){
			int v = adjList[temp][i];
			//if not yet visited
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}
