struct Node {
	int data;
	Node*left, *right;

	Node(int value, Node*left = NULL, Node*right = NULL) {
		data = value;
		this->left = left;
		this->right = right;
	}
};
class BST {
private:
	Node*root;
	
	Node*insert(Node*root, int value) {
		if (root == NULL) {
			return new Node(value);
		}
		if (value > root->data) {
			root->right = insert(root->right, value);
		}
		else {
			root->left = insert(root->left, value);
		}
		return root;
	}

	Node*findMax(Node*root) {
		if (root->right == NULL) {
			return root;
		}
		return findMax(root->right);
	}

	Node*remove(Node*root, int value) {
		if (root == NULL) {
			return NULL;
		}
		if (value > root->data) {
			root->right = remove(root->right, value);
		}
		else if (value < root->data) {
			root->left = remove(root->left, value);
		}
		else {
			if (root->left == NULL) {
				Node*tmp = root->right;
				delete root;
				return tmp;
			}
			Node*MaxInLeftSubTree = findMax(root->left);
			root->data = MaxInLeftSubTree->data;
			root->left = remove(root->left, root->data);
		}
		return root;
	}
  
  bool contains(Node*root, int value) {
		if (value == root->data)
			return true;
		else if (value < root->data) {
			if (root->left == NULL)
				return false;
			else
				return contains(root->left, value);
		}
		else if (value > root->data) {
			if (root->right == NULL)
				return false;
			else
				return contains(root->right, value);
		}
	}

	void printInOrder(Node*root) {
		if (root->left != NULL) {
			return printInOrder(root->left);
		}
		std::cout << root->data << " ";
		if (root->right != NULL) {
			return printInOrder(root->right);
		}
	}
public:
	BST(int value) {
		root = NULL;
	}
	void insert(int value) {
		if (root == NULL) {
			root = new Node(value);
		}
		else {
			root = insert(root, value);
		}
	}
  
  int findMax() {
		return findMax(root)->data;
	}
  
  bool contains(int value) {
		return contains(root, value);
	}

	void remove(int value) {
		root = remove(root, value);
	}

	void printInOrder() {
		printInOrder(root);
	}
};

int main() {

	BST tree(5);
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.remove(30);
	//std::cout << tree.contains(4);
	tree.printInOrder();
	
	return 0;
}
