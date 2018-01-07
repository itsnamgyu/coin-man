#include <string>

namespace ho {
	struct b_node {
		int key;
		b_node *left;
		b_node *right;
	};

	class b_tree {
		public:
			tree();
			~tree();
			void insert(int key);
			void print();
		protected:
			b_node *root;

			void destroy(b_node *n);
			void insert(int key, b_node *n);
	};

	class bs_tree : public b_tree {
		public:
			void insert(int key);
		protected:
			void insert(int key, b_node *n);
			void search(int key, b_node *n);
	};


	bool operator==(tree t1, tree t2);
}
