#include<iostream>
using namespace std;
class Graph{
    int V;              
    bool** adjMatrix;   
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int v, int w);
    void DFS(int startVertex);
    void DFSUtil(int v, bool visited[]);
};
Graph::Graph(int vertices){
    V = vertices;
    adjMatrix = new bool*[V];
    for (int i = 0; i <V; i++){
        adjMatrix[i] = new bool[V];
        for(int j =0; j<V; j++){
            adjMatrix[i][j] =false; 
        }
    }
}
Graph::~Graph(){
    for(int i =0; i<V; i++){
        delete[] adjMatrix[i]; 
    }
    delete[] adjMatrix; 
}
void Graph::addEdge(int v, int w){
    adjMatrix[v][w] = true; 
}
void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true; 
    cout<<v<<" ";  
    for(int i= 0; i<v; i++){
        if(adjMatrix[v][i] && !visited[i]){
            DFSUtil(i, visited);
        }
    }
}
void Graph::DFS(int startVertex){
    bool* visited =new bool[V]; 
    for(int i=0; i<V; i++){
        visited[i]= false; 
    }
    DFSUtil(startVertex, visited); 
    delete[] visited; 
}
int main(){
    Graph g(6); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout<<"DFS traversal starting from vertex 0:"<<endl;
    g.DFS(0);
    return 0;
}