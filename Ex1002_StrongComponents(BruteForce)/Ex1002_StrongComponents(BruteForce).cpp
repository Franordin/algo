﻿#include <iostream>
#include <list>
#include <vector>
#include <iomanip>

using namespace std;

struct Vertex {
	Vertex(int v) { value = v; }

	int value = -1;// 변수 이름은 value지만 실질적으로는 배열에 이 정점이 저장된 인덱스입니다.
	bool visited = false;

	vector<Vertex*> out_neighbors; // 나가는 방향의 이웃 vertex들에 대한 포인터
	vector<Vertex*> in_neighbors;  // 들어오는 방향의 이웃 vertex들에 대한 포인터
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

	void AddDiEdge(int v, int w) { // 단방향 간선
		vertices[v]->out_neighbors.push_back(vertices[w]);
		vertices[w]->in_neighbors.push_back(vertices[v]);
	}

	bool HasPath(int start, int target) {
		for (auto* v : vertices)
			v->visited = false;
		return HasPathHelper(vertices[start], vertices[target]);
	}

	void BruteForceStrongComponents() {
		int count = 0;
		vector<int> id(vertices.size(), -1);

		for (auto* v : vertices) {
			if (id[v->value] < 0) {
				id[v->value] = count;
				for (int w = v->value + 1; w < vertices.size(); w++)
					if (HasPath(v->value, w) && HasPath(w, v->value))
						id[w] = count;
				count++;
			}
		}

		// 결과 정리 후 출력
		vector<vector<int>> components(count);
		for (int s = 0; s < vertices.size(); s++)
			components[id[s]].push_back(s);
		cout << count << " strong components" << endl;
		for (int i = 0; i < components.size(); i++) {
			cout << "Strong component " << i + 1 << ": ";
			for (auto v : components[i])
				cout << v << " ";
			cout << endl;
		}
	}

private:
	vector<Vertex*> vertices;

	bool HasPathHelper(Vertex* v, Vertex* t) {
		v->visited = true;

		if (v == t) return true;

		for (auto* w : v->out_neighbors) {
			if (!w->visited) {
				if (HasPathHelper(w, t)) return true;
			}
		}

		return false;
	}
};

int main() {
	// Sedgewick p569
	// 방향(directed) 그래프
	vector<vector<int>> edges = {
		{4, 2}, {2, 3}, {3, 2}, {6, 0}, {0, 1}, {2, 0}, {11, 12}, {12, 9}, {9, 10},
		{9, 11}, {7, 9}, {10, 12}, {11, 4}, {4, 3}, {3, 5}, {6, 8}, {8, 6}, {5, 4},
		{0, 5}, {6, 4}, {6, 9}, {7, 6}
	};

	Graph g(13);

	for (vector<int>& p : edges)
		g.AddDiEdge(p[0], p[1]);

	g.BruteForceStrongComponents();

	return 0;
}
