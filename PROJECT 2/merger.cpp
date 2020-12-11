#include <iostream>
#include <string>
#include <sstream>

class Node { 
	public: 
		int start_offset;
		int length;

		Node* next;
}; 

// add new node in between smaller start_offset and bigger start_offset
void AddNewNode (Node** head, int new_start_offset, int new_length) {
	Node* new_Node = new Node();

	new_Node->start_offset = new_start_offset;
	new_Node->length = new_length;
	
	// if new Node should locate for the first of linked list
	if (*head == NULL || (*head)->start_offset >= new_start_offset) {
		new_Node->next = *head;
		*head = new_Node;
	}

	else {
		Node* target = *head;
		// find proper position of new node to make linked list sorted
		while (target->next != NULL && target->next->start_offset < new_start_offset) {
			target = target->next;
		}

		new_Node->next = target->next;
		target->next = new_Node;
	}
}

void Merger (Node** head) {
	Node* target = *head;

	while(target != NULL && target->next != NULL) {
		// sum of start_offset and length of current Node
		int A = target->start_offset + target->length;
		// sum of start_offset and length of next Node
		int B = target->next->start_offset + target->next->length;
		
		// if A is equal or bigger than next Node's start_offset
		if (A >= target->next->start_offset) {
			// then target Node and next Node should be merged
			if (A < B) {
				// then length of target Node should be changed
				target->length = B - target->start_offset;
			}
			// if not length of target Node doesn't need to be changed
			target->next = target->next->next;
		}
		
		// if not target Node and next Node don't need to be merged
		else {
			target = target->next;
		}
	}
}

int main() {
	Node* head = NULL;

	std::string line;
	std::stringstream segment;	
	int num;

	while(getline(std::cin, line)){
		segment.clear(); 
		segment.str(line);

		int count = 0;
		int input[100];
		
		// get two integers from the line
		while(segment >> num){
			input[count] = num;
			count++;
		}

		// input should be only two integers
		if (count != 2) {
			std::cerr << "input error" << std::endl;
			return 0;
		}

		// start_offset should be nonnegative and length should be positive
		if (input[0] < 0 || input[1] < 1) {
			std::cerr << "input error" << std::endl;
			return 0;
		}
		
		// Add new node that consists input start_offset and length
		AddNewNode (&head, input[0], input[1]);
	}

	// merge all the Node that satisfies the problem condition
	Merger(&head);
	
	// print merged start_offset and length of all the Node
	Node* temp = head;
	while (temp != NULL) {
		std::cout << temp->start_offset << " " << temp->length << std::endl;
		temp = temp->next;
	}
}
