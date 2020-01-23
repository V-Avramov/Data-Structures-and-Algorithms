struct Node {
	int data;
	struct Node*next;
};

class LinkedList {
private:
	Node*head,*tail;
	
	void printReverse(Node*curr) {
		if (curr->next != NULL) {
			printReverse(curr->next);
		}
		cout << curr->data << " ";
	}
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void InsertAtEnd(int value) {
		Node*temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	void InsertAtStart(int value) {
		Node*temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}
	void InsertAtPosition(int value, int position) {
		Node*temp = new Node;
		Node*curr = head;
		Node*prev;
		temp->data = value;
		if (position == 1 || head == NULL && position > 0)
			InsertAtStart(value);
		for (int i = 0; i < position; i++) {
			prev = curr;
			curr = curr->next;
			if (curr == NULL)
				InsertAtEnd(value);
		}
		prev->next = temp;
		temp->next = curr;
	}
	void RemoveEnd() {
		Node*temp = head;
		Node*prev;
		if (head == NULL)
			return;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
	}
	void RemoveStart() {
		if (head != NULL) {
			Node*next = head->next;
			head = next;
		}
	}

	void RemoveAtPos(int position) {

		if (head == NULL)
			return;
		if (position == 0) {
			Node*next = head->next;
			head = next;
			return;
		}
		Node*curr = head;
		Node*following;
		for (int i = 0; curr != NULL && i < position - 1; i++) {
			curr = curr->next;
		}
		if (curr == NULL || curr->next == NULL) {
			return;
		}
		following = curr;
		curr = curr->next;
		following->next = curr->next;
		delete curr;
	}

	void RemoveAll(int value) {
		Node* prev = NULL;
		Node* curr = head;

		while (curr != NULL) {
			if (curr->data == value) {
				Node* tmp = curr;
				curr = curr->next;
				if (prev == NULL) {
					head = curr;
				}
				else {
					prev->next = curr;
				}
				delete tmp;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
	bool isEmpty() {
		return head == NULL;
	}

	Node*getMax() {
		Node*max = head;
		Node*curr = head;
		while (curr != NULL) {
			if (curr->data > max->data) {
				max = curr;
			}
			curr = curr->next;
		}
		return max;
	}

	void print() {
		Node*temp = head;
		while (temp != NULL) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void printBackwards() {
		Node*curr = head;
		printReverse(curr);
	}

	void reverse() {
		Node*prev = NULL;
		Node*curr = head;
		Node*following;
		tail = curr;
		while (curr != NULL) {
			following = curr->next;
			curr->next = prev;
			prev = curr;
			curr = following;
		}
		head = prev;
	}
};

int main() {

	LinkedList list;
	list.InsertAtEnd(1);
	list.InsertAtEnd(2);
	list.InsertAtEnd(3);
	list.InsertAtEnd(4);
	list.InsertAtEnd(5);
	//list.InsertAtPosition(3, 3);
	//list.RemoveAll(3);
	//list.RemoveEnd();
	list.RemoveAtPos(3);

	list.print();

	
	return 0;
}
