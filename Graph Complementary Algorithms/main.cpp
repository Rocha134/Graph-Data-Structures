// Francisco Rocha Juárez - A01730560
// Iker Guerrero Gonzalez - A00830026
// Aldo Mauricio Cruz Lozada - A01732372

#include <bits/stdc++.h>
using namespace std;

int char_number (char c){
int number;
if (c=='A') {
  number = 0;
} else if (c=='B') {
  number = 1;
} else if (c=='C') {
  number = 2;
} else if (c=='D') {
  number = 3;
} else if (c=='E') {
  number = 4;
} else if (c=='F') {
  number = 5;
} else if (c=='G') {
  number = 6;
} else if (c=='H') {
  number = 7;
} else if (c=='I') {
  number = 8;
} else if (c=='J') {
  number = 9;
} else if (c=='K') {
  number = 10;
} else if (c=='L') {
  number = 11;
} else if (c=='M') {
  number = 12;
} else if (c=='N') {
  number = 13;
} else if (c=='O') {
  number = 15;
} else if (c=='P') {
  number = 16;
} else if (c=='Q') {
  number = 17;
} else if (c=='R') {
  number = 18;
} else if (c=='S') {
  number = 19;
} else if (c=='T') {
  number = 20;
} else if (c=='U') {
  number = 21;
} else if (c=='V') {
  number = 22;
} else if (c=='W') {
  number = 23;
} else if (c=='X') {
  number = 24;
} else if (c=='Y') {
  number = 25;
} else if (c=='Z') {
  number = 26;
}
return number;
}

char number_char (int n){
char letter;
if (n==0) {
  letter = 'A';
} else if (n==1) {
  letter = 'B';
} else if (n==2) {
  letter = 'C';
} else if (n==3) {
  letter = 'D';
} else if (n==4) {
  letter = 'E';
} else if (n==5) {
  letter = 'F';
} else if (n==6) {
  letter = 'G';
} else if (n==7) {
  letter = 'H';
} else if (n==8) {
  letter = 'I';
} else if (n==9) {
  letter = 'J';
} else if (n==10) {
  letter = 'K';
} else if (n==11) {
  letter = 'L';
} else if (n==12) {
  letter = 'M';
} else if (n==13) {
  letter = 'N';
} else if (n==15) {
  letter = 'O';
} else if (n==16) {
  letter = 'P';
} else if (n==17) {
  letter = 'Q';
} else if (n==18) {
  letter = 'R';
} else if (n==19) {
  letter = 'S';
} else if (n==20) {
  letter = 'T';
} else if (n==21) {
  letter = 'U';
} else if (n==22) {
  letter = 'V';
} else if (n==23) {
  letter = 'W';
} else if (n==24) {
  letter = 'X';
} else if (n==25) {
  letter = 'Y';
} else if (n==26) {
  letter = 'Z';
}
return letter;
}

// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj_topological; // Pointer to an array for adjacency lists
    list<int> *adj_tree; // Pointer to an array for adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge_topological(int v, int w);   // to add an edge to graph
    void addEdge_tree(int u, int v);
    bool isTree();   // returns true if graph is tree
    void topologicalSort();
    void load(int vertices, int arcos);
};

Graph::Graph(int V)
{
    this->V = V;
    adj_topological = new list<int>[V];
    adj_tree = new list<int>[V];
}

void Graph::addEdge_tree(int v, int w)
{
    adj_tree[v].push_back(w); // Add w to v’s list.
    adj_tree[w].push_back(v); // Add v to w’s list.
}

void Graph::addEdge_topological(int u, int v)
{
    adj_topological[u].push_back(v);
}

// A recursive function that uses visited[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj_tree[v].begin(); i != adj_tree[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for
        // that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }

        // If an adjacent is visited and not parent of current
        // vertex, then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}

// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
    // Mark all the vertices as not visited and not part of
    // recursion stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // The call to isCyclicUtil serves multiple purposes.
    // It returns true if graph reachable from vertex 0
    // is cyclcic. It also marks all vertices reachable
    // from 0.
    if (isCyclicUtil(0, visited, -1))
             return false;

    // If we find a vertex which is not reachable from 0
    // (not marked by isCyclicUtil(), then we return false
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;

    return true;
}

// The function to do
// Topological Sort.
void Graph::topologicalSort()
{
    // Create a vector to store
    // indegrees of all
    // vertices. Initialize all
    // indegrees as 0.
    vector<int> in_degree(V, 0);

    // Traverse adjacency lists
    // to fill indegrees of
    // vertices.  This step
    // takes O(V+E) time
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj_topological[u].begin();
             itr != adj_topological[u].end(); itr++)
            in_degree[*itr]++;
    }

    // Create an queue and enqueue
    // all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Initialize count of visited vertices
    int cnt = 0;

    // Create a vector to store
    // result (A topological
    // ordering of the vertices)
    vector<int> top_order;

    // One by one dequeue vertices
    // from queue and enqueue
    // adjacents if indegree of
    // adjacent becomes 0
    while (!q.empty()) {
        // Extract front of queue
        // (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its
        // neighbouring nodes
        // of dequeued node u and
        // decrease their in-degree
        // by 1
        list<int>::iterator itr;
        for (itr = adj_topological[u].begin();
             itr != adj_topological[u].end(); itr++)

            // If in-degree becomes zero,
            // add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);

        cnt++;
    }

    // Check if there was a cycle
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << number_char(top_order[i]) << " ";
    cout << endl;
}

void Graph::load(int vertices, int arcos){

  std::vector<char> l;
  std::vector<char> l2;

  char l_letter;
  char l2_letter;
  for (int i = 0; i < arcos; i++) {
    std::cin >> l_letter >> l2_letter;
    l.push_back(l_letter);
    l2.push_back(l2_letter);
  }
  // l = {'A','B','C','C','D','D','E','E','E','F','F','G','H','H','I','J','J','K'};
  // l2 = {'D','D','A','B','G','H','A','D','F','J','K','I','I','J','L','L','M','J'};

  for (int i = 0; i < arcos; i++) {
    addEdge_tree(char_number(l[i]),char_number(l2[i]));
    addEdge_topological(char_number(l[i]),char_number(l2[i]));
  }

}

int main(int argc, char const *argv[]) {

    int vertices;
    int arcos;

    std::cin >> vertices;
    std::cin >> arcos;

    //We create the graph with the number of vertex
    Graph graph(vertices);

    //We ask the user for the data to load the graph
    graph.load(vertices,arcos);

    //We determine if the given graph is a tree.
    graph.isTree()? cout << "true\n":
                 cout << "false\n";

    //We do the topological sorting and print the graph sorted
    graph.topologicalSort();


  return 0;
}
