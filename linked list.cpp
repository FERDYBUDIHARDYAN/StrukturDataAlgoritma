#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		
		void inserttohead(char data){
			
			Node *node = new Node();
			node->id = data;
			
			Node *tmp = head;
			head = node;
			node->next = tmp;
		}
		
		void inserttotail(char data){
			
			Node *node = new Node();
			node->id = data;
			
			tail->next = node;
			tail = node;
		}
		
		void printall(){
			if(head!=NULL){
				Node *tmp = head;
				do{
					cout << tmp->id << "->";
					tmp = tmp->next;
				}while(tmp!=NULL);
			}
		}
};


int main(int argc, char** argv) {
	
	LinkedList *link1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	link1->head = node1;
	link1->tail = node1;
	
	cout << link1->head->id << endl;
	cout << node1 << endl;
	
	Node *node2 = new Node();
	node2->id = 'B';
	
	link1->tail->next = node2;
	link1->tail = node2;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	Node *nodeX = new Node();
	nodeX->id = 'X';
	
	Node *tmp = link1->head;
	link1->head = nodeX;
	nodeX->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->inserttohead('Y');
	link1->inserttotail('C');
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->printall();
	
	return 0;
}