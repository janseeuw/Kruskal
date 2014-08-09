#include "graph.h"
#include "UnionFind.h"
#include <queue>

template<EdgeType ET, class T>
class Kruskal{
public:
	Kruskal(GraphWithEdgedata<ET, T> &g):g(g),uf(g.numberOfVertices()),mst(g.numberOfVertices()-1){
		int V = g.numberOfVertices();
		int E = g.numberOfEdges();
		
		// Insert all edges in the priority queue
		for(int i=0; i<V; i++){
			map<int,int>::iterator it = g[i].begin();
			while(it != g[i].end()){
				int j = it->first;
				T distance = *g.getEdgedata(i, j);
				pair<int, int> edge(i,j);
				pq.push(pair<T, pair<int, int>>(distance, edge));
				it++;
			}
		}
		
		// Take edge with shortest distance each time, discarding those that create loops
		// Until we have V-1 edges

		int E = g.aantalVerbindingen();
		int V = g.aantalKnopen();
		for(int i = 0, k = 0; i < E && k < V-1; i++){
			pair<T, pair<int, int>> edge = pq.top();
			int startvertex = edge.second.first;
			int endvertex = edge.second.second;
			if(!uf.find(startvertex, endvertex)){
				uf.unite(startvertex, endvertex);
				mst[k++]=edge;
			}
			pq.pop();
		}
	}
	void print(){
		for(int i=0; i<mst.size(); i++){
			printf("%d --[%d]-- %d\n", mst[i].second.first, mst[i].first, mst[i].second.second);
		}
	}
private:
	class myComparer
	{
	public:
		bool operator() (const pair<T, pair<int,int> > &a, pair<T, pair<int,int> >&b) const
		{
			return (a.first>b.first);
		}
	};
	const GraphWithEdgedata<ET, T> g;
	UnionFind uf;
	priority_queue<pair<T, pair<int,int> >, vector<pair<T, pair<int,int>>>, myComparer> pq;
	vector<pair<T, pair<int, int>>> mst;
};