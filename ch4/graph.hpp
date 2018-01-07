namespace ho {
	class graph {
		public:
			graph();
			~graph();
			void add_vertex(int index);
			void add_edge(int v1, int v2); // Add both vertices and add edge
			void print();
			std::vector<pair<int, vector<int>>> data();
		protected:
			std::vector<pair<int, vector<int>>> internal_data;
	};

	bool operator==(graph g1, graph g2);
}
