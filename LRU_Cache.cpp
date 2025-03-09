#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
	public:
		Node* prev;
		int data;
		int key;
		Node* next;
		Node(int key,int data){
			this->prev=NULL;
			this->data=data;
			this->key=key;
			this->next=NULL;		
		}
};

class LRU_cache{
	public:
		unordered_map <int,Node*> LRU;
		Node* head=new Node(-1,-1);
		Node* tail=new Node(-1,-1);
		int capacity;
		LRU_cache(int capacity){
			this->capacity=capacity;
			head->next=tail;
			tail->prev=head;
		}
		void insert_after_head(Node* node){
			if(head->next==tail){
				head->next=node;
				node->next=tail;
				node->prev=head;
				tail->prev=node;
				return;
			}
			Node* temp=head->next;
			head->next=node;
			node->next=temp;
			temp->prev=node;
			node->prev=head;
		}
		void delete_node(Node* node){
			Node* previous=node->prev;
			Node* nextnode=node->next;
			previous->next=nextnode;
			nextnode->prev=previous;
		}
		int get(int key){
			if(LRU.find(key) == LRU.end()){
				return -1;
			}
			Node* dataNode=LRU[key];
			int getdata=dataNode->data;
			delete_node(dataNode);
			insert_after_head(dataNode);
			return getdata;
		}
		void put(int key,int value){
			if(LRU.find(key) != LRU.end()){
				Node* temp=LRU[key];
				temp->data=value;
				delete_node(temp);
				insert_after_head(temp);
				(LRU[key])->data=value;
				return;
			}
			Node* temp=new Node(key,value);
			if(LRU.size()==capacity){
				if(tail->prev!=head){
					int oldkey=tail->prev->key;
					delete_node(tail->prev);
					LRU.erase(oldkey);
				}
				
			}
			insert_after_head(temp);
			LRU.insert(make_pair(key,temp));
		}
		void printCache(){
			Node* temp=head->next;
			while(temp!=tail){
				cout<<temp->key<< "->"<<temp->data<<endl;
				temp=temp->next;
			}
		}
};
int main(){
	LRU_cache myCache(3);
	cout<<"1) Insert a value "<<endl;
	cout<<"2)Get a value"<<endl;
	cout<<"3) Print the cache"<<endl;
	while(1){
		int choice;
		cout<<"Enter your choice: ";
		cin>>choice;
		if(choice==1){
			int key,value;
			cout<<"Enter the key and value: ";
			cin>>key>>value;
			myCache.put(key,value);
		}else if(choice==2){
			int key,value;
			cout<<"Enter the key: ";
			cin>>key;
			value=myCache.get(key);
			if(value==-1){
				cout<<"No value exist with that key"<<endl;
			}else{
				cout<<"Value at key "<<key<<" is "<<value<<endl;
			}
		}else if(choice==3){
			cout<<"The cache is: "<<endl;
			myCache.printCache();
		}
		else{
			break;
		}
	}
	return 0;
}
