struct Node {
	int data;
	struct Node*next;
};

class LinkedList {
private:
	Node*head,*tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void insertAtEnd(int value) {
		Node*temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
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
		if (head == NULL)
			return;
		while (head->data == value && head != NULL) {
			head = head->next;
		}
		//Node*prev;
		Node*curr = head;
		while (curr->next != NULL) {
			if (curr->next->data == value) {
				curr->next = curr->next->next;
				continue;
			}
			curr = curr->next;
		}
		if (curr->data == value) {
			curr = NULL;
			return;
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

	void TeamSelection(int k) {
		int team = 1;
		Node*temp = head;
		while (!isEmpty()) {
			if (temp == getMax()) {
				temp->data = team;
				while
			}
		}
	}

	void print() {
		Node*temp = head;
		while (temp != NULL) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void printBackwards() {
		Node*temp = tail;
		while (temp != head) {
			std::cout << temp->data << " ";
			temp = temp->prev;
		}
		std::cout << temp->data << " ";
	}
};
