#include <iostream>
/****************************************/
/*                                      */
/* Lab 3 starter file                   */
/* V 1.1.1:fixed back_ typo in line 150 */
/* V 1.1: updated Sentinel::print()     */
/*        and sentinel::reversePrint()  */
/*                                      */
/*                                      */
/****************************************/
template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	DList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~DList();
};


template <typename T>
void DList<T>::push_front(const T& data){

	Node* nn=new Node(data,front_);
	if(front_){
		front_->prev_=nn;
	}
	else{
		back_=nn;
	}
	front_=nn;

}
template <typename T>
void DList<T>::push_back(const T& data){

}
template <typename T>
void DList<T>::pop_front(){
	if(front_){
		Node* rm = front_;
		front_=rm->next_;
		if(front_)
			front_->prev_=nullptr;
		}
		else{
			back_=nullptr;
		}
		delete rm;
	}
}
template <typename T>
void DList<T>::pop_back(){

}
template <typename T>
void DList<T>::print() const{
	Node* curr=front_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(!front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
void DList<T>::reversePrint() const{
	Node* curr=back_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	if(!back_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
DList<T>::~DList(){

}
template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~Sentinel();
};


template <typename T>
void Sentinel<T>::push_front(const T& data){

	Node* nn=new Node(data, front_->next_, front_);
	front_->next_=nn;
	nn->next_->prev_=nn;

}
template <typename T>
void Sentinel<T>::push_back(const T& data){

}
template <typename T>
void Sentinel<T>::pop_front(){
	if(front_->next_!=back_){
		Node* rm = front_->next_;
		rm->next_->prev_=rm->prev_;
		rm->prev_->next_=rm->next_;
/* v2:

		Node* rm = front_->next_;
		Node* n=rm->next_;
		Node* p=rm->prev_;
		n->prev_=p;
		p->next_=n;

*/		
		delete rm;
	}
}
template <typename T>
void Sentinel<T>::pop_back(){

}
template <typename T>
void Sentinel<T>::print() const{
	Node* curr=front_->next_;
	while(curr!=back_){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(front_->next_==back_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
void Sentinel<T>::reversePrint() const{
	Node* curr=back_->prev_;
	while(curr!=front_){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	if(back_->prev_==front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
Sentinel<T>::~Sentinel(){

}
