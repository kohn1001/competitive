/* taken from the comptetitive workshop website - Technion CS 234900 
 *   http://webcourse.cs.technion.ac.il/234900/Spring2017/ho/WCFiles/Graph.h
 *
 * */



#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

#define IN(u) (2*(u))
#define OUT(u) (2*(u)+1)

const int INF = 1 << 30;
const int INVALID_VALUE = -1;

#define FEV(it, V) for (vector<Vertex>::iterator it = V.begin(); it != V.end(); ++it)
#define FEE(it, E) for (vector<Edge>::iterator it = E.begin(); it != E.end(); ++it)
#define FEA(it, u) for (vector<int>::iterator it = V[u].adjacentEdges.begin(); it != V[u].adjacentEdges.end(); ++it)

#define FIV(i, V) for (int i = 0; i < (int) V.size(); ++i)

typedef pair<int, int> pii;

struct Vertex
{
	int d, p;					// BFS, Bellman-Ford
	bool discovered, explored;	// BFS, DFS
	vector<int> adjacentEdges;	// DFS
};

enum EdgeType
{
	Undiscovered,
	TreeEdge,
	BackEdge,
	CrossEdge,
};

struct Edge
{
	int u, v;
	int w;			// Kruskal, Bellman-Ford, Edmonds-Karp
	EdgeType type;  // DFS

	bool operator < (const Edge &other) const
	{
		return w < other.w;
	}
};

class Union
{
public:
	Union(int n) : parents(n), ranks(n)
	{
		//
	}

	void MakeSet(int x)
	{
		parents[x] = x;
		ranks[x] = 0;
	}	

	int Find(int x)
	{
		if (x != parents[x]) {
			parents[x] = Find(parents[x]);
		}

		return parents[x];
	}

	void Merge(int x, int y)
	{
		Link(Find(x), Find(y));
	}

private:
	void Link(int x, int y)
	{
		if (ranks[x] > ranks[y]) {
			parents[y] = x;
		}
		else {
			parents[x] = y;
		}

		if (ranks[x] == ranks[y]) {
			ranks[y]++;
		}
	}

	vector<int> parents;
	vector<int> ranks;
};

class Graph
{
public:
	// Adds ands edge to the graph, O(1)
	// Input: edge (u, v) with weight w. V[u] must exist.
	void AddEdge(int u, int v, int w = 1, bool directed = true)
	{
		Edge e = { u, v, w };
		E.push_back(e);
		V[u].adjacentEdges.push_back((int) E.size()-1);

		if (!directed) {
			V[v].adjacentEdges.push_back((int) E.size()-1);
		}
	}

	// Breadth-first search, O(E+V)
	// Input: source, target	
	// Output: the distance between them or INF
	int BFS(int s, int t, bool directed = false)
	{
		FEV(it, V) {
			it->d = INF;
			it->p = INVALID_VALUE;
			it->explored = false;
		}

		queue<int> Q;

		V[s].d = 0;
		Q.push(s);

		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();

			if (u == t) {
				return V[u].d;
			}

			FEA(it, u) {
				Edge& e = E[*it];
				int v = directed ? e.v : (e.u == u ? e.v : e.u);
				if (e.w > 0 && !(V[v].explored)) {
					V[v].explored = true;
					V[v].d = V[u].d + 1;
					V[v].p = u;
					Q.push(v);
				}
			}
		}

		return INF;
	}

	// Depth-first search, O(E+V)
	// Input: source, target	
	// Output: true if target is reachable from source. The edge types are updated during the run.
	bool DFS(int s, int t)
	{
		FEV(it, V) {
			it->discovered = false;
			it->explored = false;
		}

		FEE(it, E) {
			it->type = Undiscovered;
		}

		stack<int> S;
		V[s].discovered = true;
		S.push(s);

		while (!S.empty()) {
			int u = S.top();

			if (u == t) {
				return true;
			}

			bool discovered = false;
			FEA(it, u) {
				Edge& e = E[*it];
				if (e.type == Undiscovered) {
					int v = e.u == u ? e.v : e.u;
					if (!V[v].discovered && !V[v].explored) {
						e.type = TreeEdge;
						V[v].discovered = true;
						S.push(v);
						discovered = true;
						break;
					}
					else if (V[v].discovered) {
						e.type = BackEdge;
					}
					else {
						e.type = CrossEdge;
					}
				}
			}

			if (discovered) {
				continue;
			}

			V[u].explored = true;
			S.pop();
		}

		return false;
	}

	// Kruskal algorithm for MST, O(ElogV)
	// Input: 
	// Output: The weight of the graph and the edges of the MST
	int Kruskal(vector<Edge>& T)
	{
		int weight = 0;

		Union u(V.size());

		FIV(i, V) {
			u.MakeSet(i);
		}

		sort(E.begin(), E.end());

		FIV(i, E) {
			Edge& e = E[i];

			if (u.Find(e.u) != u.Find(e.v)) {
				T.push_back(e);
				u.Merge(e.u, e.v);
				weight += e.w;
			}
		}

		return weight;
	}

	// Dijkstra algorithm for shortest path finding, O(V+ElogV)
	// Input: source node, (optional destination node)
	// Output: distance from source to each node
	int Dijkstra(int s, int t = -1)
	{
		FEV(it, V) {
			it->d = INF;
			it->p = INVALID_VALUE;
			it->explored = false;
		}

		priority_queue<pii, vector<pii>, greater<pii> > Q;

		V[s].d = 0;
		Q.push(pii(0, s));

		while (!Q.empty()) {
			pii p = Q.top();
			Q.pop();

			int u = p.second;
			V[u].explored = true;

			FEA(it, u) {
				Edge& e = E[*it];

				int d = V[u].d + e.w;
				if (d < V[e.v].d && !V[e.v].explored) {
					V[e.v].d = d;
					V[e.v].p = u;

					if (e.v == t) {
						return d;
					}

					Q.push(pii(d, e.v));
				}
			}
		}

		return INF;
	}

	// Bellman-Ford algorithm for shortest path finding, O(VE)
	// Input: source node
	// Output: distance from source to each node
	void BellmanFord(int s)
	{
		FEV(it, V) {
			it->d = INF;
			it->p = INVALID_VALUE;
		}

		V[s].d = 0;

		FIV(i, V) {
			FEE(it, E) {
				if (V[it->u].d + it->w < V[it->v].d) {
					V[it->v].d = V[it->u].d + it->w;
					V[it->v].p = it->u;
				}
			}
		}
	}

	// Checks if there is a cycle in the graph, , O(VE)
	// Output: true if there is a cycle
	bool HasCycle()
	{
		BellmanFord(0);

		FEE(it, E) {
			if (V[it->u].d + it->w < V[it->v].d) {
				return true;
			}
		}

		return false;
	}

	// Strongly Connected Components, O(E+V)
	// Output: the number of SCC and a list of them
	int SCC(vector<vector<int> >& scc)
	{
		scc.clear();

		stack<int> S;
		
		FEV(it, V) {
			it->explored = false;
		}

		FIV(i, V) {
			if (!V[i].explored) {
				_FillOrder(i, S);
			}
		}

		Transpose();

		FEV(it, V) {
			it->explored = false;
		}

		while (!S.empty()) {
			int u = S.top();
			S.pop();

			if (!V[u].explored) {
				vector<int> c;
				_GetSCC(u, c);
				scc.push_back(c);
			}
		}

		return scc.size();
	}

	void _FillOrder(int u, stack<int>& S)
	{
		V[u].explored = true;
		FEA(it, u) {
			int v = E[*it].v;
			if (!V[v].explored) {
				_FillOrder(v, S);
			}
		}

		S.push(u);
	}

	void _GetSCC(int u, vector<int>& scc)
	{
		scc.push_back(u);

		V[u].explored = true;
		FEA(it, u) {
			int v = E[*it].v;
			if (!V[v].explored) {
				_GetSCC(v, scc);
			}
		}
	}

	// Reverses the edges direction for the current Graph, O(V+E)
	void Transpose()
	{
		vector<Edge> Temp = E;

		FEV(it, V) {
			it->adjacentEdges.clear();
		}

		E.clear();

		FEE(it, Temp) {
			AddEdge(it->v, it->u, it->w);
		}
	}
	
public:
	vector<Vertex> V;
	vector<Edge> E;
};


