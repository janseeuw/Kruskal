class UnionFind {
public:
	UnionFind(int N){
		subsets.resize(N);
		for(int i=0; i<N; i++){
			subsets[i].parent=i;
			subsets[i].rank=0;
		}
	}
	bool find(int p, int q){
		int x = find(p);
		int y = find(q);
		return x==y;
	}
	void unite(int p, int q){
		int pRoot = find(p);
		int qRoot = find(q);
		// Attach smaller rank tree under root of high rank tree
		// (Union by Rank)
		if (subsets[pRoot].rank < subsets[qRoot].rank)
			subsets[pRoot].parent = qRoot;
		else if (subsets[pRoot].rank > subsets[qRoot].rank)
			subsets[qRoot].parent = pRoot;
		
		// If ranks are same, then make one as root and increment
		// its rank by one
		else
		{
			subsets[qRoot].parent = pRoot;
			subsets[pRoot].rank++;
		}
	}
private:
	struct subset
	{
		int parent;
		int rank;
	};
	std::vector<subset> subsets;
	int find(int x){
		// find root and make root as parent of x (path compression)
		if (subsets[x].parent != x)
			subsets[x].parent = find(subsets[x].parent);
		
		return subsets[x].parent;
	}
};