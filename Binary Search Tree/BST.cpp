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

	Node* _remove(Node* current, int value) {
		if (!current) {
			return nullptr;
		}

		if (value < current->data) {
			current->left = _remove(current->left, value);
		}
		else if (value > current->data) {
			current->right = _remove(current->right, value);
		}
		else { // value = current->data;
			if (!current->left && !current->right) {
				delete current;
				return nullptr;
			}
			else if (!current->left) {
				Node* tempRight = current->right;
				delete current;
				return tempRight;
			}
			else if (!current->right) {
				Node* tempLeft = current->left;
				delete current;
				return tempLeft;
			}
			else {
				Node* swapWith = current->right;
				//go to the lowest cost element of the right sub-tree
				while (swapWith->left) {
					swapWith = swapWith->left;
				}
				current->data = swapWith->data;
				current->right = _remove(current->right, swapWith->data);
			}
		}

		return current;
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
		root = _remove(root, value);
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
