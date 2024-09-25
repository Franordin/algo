#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

struct Vertex {
	Vertex(int v) { value = v; }

	int value = -1;
	bool visited = false;

	vector<Vertex*> out_neighbors;
};

class Graph {
public:
	Graph(int num_vertices) {
		vertices.resize(num_vertices);
		for (int i = 0; i < num_vertices; i++)
			vertices[i] = new Vertex(i);
	}

	~Graph() {
		for (auto* v : vertices)
			delete v;
	}

	void AddDiEdge(int v, int w) {
		vertices[v]->out_neighbors.push_back(vertices[w]);
	}

	void AddBiEdge(int v, int w) {
		vertices[v]->out_neighbors.push_back(vertices[w]);
		vertices[w]->out_neighbors.push_back(vertices[v]);
	}

	void DFS(int source) {
		for (auto* v : this->vertices)
			v->visited = false;

		current_time = 0;
		DFS(vertices[source], 0);
	}

	void DFS(Vertex* source, int level) {
		current_time++;
		cout << setw(2) << current_time << ": ";
		cout << string(2 * level, ' ');
		cout << "DFS(" << source->value << ")" << endl;

		source->visited = true;
		for (auto* w : source->out_neighbors)
			if (!w->visited)
				DFS(w, level + 1);

		current_time++;
		cout << setw(2) << current_time << ": ";
		cout << string(2 * level, ' ');
		cout << source->value << " done" << endl;
	}

private:
	vector<Vertex*> vertices;
	int current_time = 0;
};

int main() {

	//// simple case
	//{
	//	// 0: Appetizer
	//	// 1: Main dish
	//	// 2: Dessert
	//
	//	Graph g(3);
	//
	//	g.AddDiEdge(0, 1); // Appetizer → Main dish
	//	g.AddDiEdge(1, 2); // Main dish → Dessert
	//	g.AddDiEdge(0, 2); // Appetizer → Dessert
	//
	//	g.DFS(0);
	//}

	// Sedgewick Algorithm 4.1 p.536 (It's a little different)
	{
		Graph g(6);

		g.AddDiEdge(0, 2);
		g.AddDiEdge(2, 1);
		g.AddDiEdge(2, 3);
		g.AddDiEdge(3, 4);
		g.AddDiEdge(1, 5);
		g.AddDiEdge(2, 4);
		g.AddBiEdge(3, 5);

		g.DFS(2);
	}

	return 0;
}