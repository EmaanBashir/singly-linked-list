#include <iostream>
using namespace std;

//class node
class Node {
	//public fields
public:
	int value;
	Node* next;
};
//class List
class List {
	//private fields
private:
	Node* head;
	//public functions
public:
	//constructor with no parameters
	List() {
		head = NULL;
	}
	//method to insert a node at the beginning of the linked list
	void insertAtHead(int new_value) {
		Node* newNode;
		newNode = new Node;
		newNode->value = new_value;
		newNode->next = head;
		head = newNode;
	}
	//method to insert node at the specified location
	void insertAtLocation(int location, int new_value) {
		Node* newNode, * ptr;
		newNode = new Node;
		newNode->value = new_value;
		ptr = head;
		for (int i = 1; i < (location - 1); i++) {
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	//method to delete a specific value from the linked list
	void deleteValue(int del_value) {
		Node* node, * prevNode;
		if (!head) {
			return;
		}
		else {
			node = head;
			if (head->value == del_value) {
				head = head->next;
				delete node;
			}
			else {
				prevNode = head;
				while (node->value != del_value) {
					if (!node->next) {
						break;
					}
					prevNode = node;
					node = node->next;
				}
				if (node->value == del_value) {
					prevNode->next = node->next;
					delete node;
				}
			}
		}
		cout << "\nUpdated List : ";
		this->displayList();
	}
	//method to display the list
	void displayList() {
		Node* tempNode;
		tempNode = head;
		while (tempNode) {
			cout << tempNode->value << "  ";
			tempNode = tempNode->next;
		}
		cout << endl;
		delete tempNode;
	}
	//method to count the number of nodes in the linked list	
	int countList() {
		Node* tempNode;
		tempNode = head;
		int count = 0;
		while (tempNode) {
			count++;
			tempNode = tempNode->next;
		}
		delete tempNode;
		return count;
	}

};
//main function
int main() {
	//Creating the linked list and inserting values at head
	List list;
	list.insertAtHead(25);
	list.insertAtHead(4);
	list.insertAtHead(6);
	list.insertAtHead(9);
	list.insertAtHead(2);

	int option = 0;
	//loop to keep on displaying the menu until the user wants to exit
	while (option != 5) {
		//Display the menu
		cout << "\nWhat would you like to do?" << endl;
		cout << "1)Insert a node at 3rd location\n2)Display List\n3)Delete node\n4)Count the number of nodes present in the list\n5)Exit" << endl;
		cout << "Enter option number: ";
		cin >> option;
		cout << endl;
		//switch-case
		switch (option) {
			//case 1: Insert node at specified location
		case 1:
			cout << "Enter value of new node : ";
			int val;
			cin >> val;
			list.insertAtLocation(3, val);
			cout << "Updated List : ";
			list.displayList();
			break;
			//case 2: Display list
		case 2:
			list.displayList();
			break;
			//case 3: Delete node
		case 3:
			cout << "Enter value of the node to be deleted : ";
			int del_value;
			cin >> del_value;
			list.deleteValue(del_value);
			break;
			//case 4: Count nodes
		case 4:
			cout << "Total number of nodes in the list : " << list.countList() << endl;
			break;
			//Default case: Exit
		default:
			option = 5;
		}
	}
	return 0;
}
