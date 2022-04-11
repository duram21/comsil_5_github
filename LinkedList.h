#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

template <typename T> // template 사용
//LinkedList Node
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){
		  data = element; // data에 element 삽임
		  link = 0; // link를 NULL로 설정
		}
	};

template <typename T> // template 사용
//LinkedList Class
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first; 
		int current_size; // current_size는 LinkedList의 크기
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0; // 첫번째 원소의 주소를 NULL로 함
			current_size = 0; // LinkedList 크기 초기화
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size; // LinkedList 크기 반환 -> 노드 개수
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};

template <typename T> // template 사용
//새 노드를 맨 앞에 붙이고 값을 넣음
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first; // newnode가 가르키는 link를 first로 설정
	first = newnode; // 첫 노드의 주소를 newnode로 변경
	current_size++; // LinkedList 크기를 하나 늘려줌
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <typename T> // template 사용
bool LinkedList<T>::Delete(T &element){

	if (first == 0) // 첫번째 노드의 주소가 NULL이면
		return false; // false를 반환
	
	Node<T> *current = first; // current에 첫번째 노드 주소 저장
	Node<T> *previous = 0; // current 이전의 노드는 NULL 값
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous) // previous가 NULL 이 아님
				previous -> link = current -> link; // 이전 노드 link를 현재 노드의 link로 변경
			else // previous가 NULL 값이면
				first = first -> link; // 첫번째 노드를 다음 노드로 변경
			break;
		}
		previous = current; // 이전 노드를 현재 노드로 변경
		current = current -> link; // 현재 노드의 링크를 다음 노드 링크로 변경
	}
	element = current -> data; // 현재 노드의 값 저장
	delete current; // 현재 노드의 메모리 해제
	current_size--; // LinkedList 크기를 하나 줄임

	return true; // delete 되면 true 반환
}

//리스트를 출력하는 Print 함수
template <typename T> // template 이용
void LinkedList<T>::Print(){
	Node<T> *i; // 현재 노드 주소
	int index = 1; // 

	if (current_size != 0){ // LinkedList 원소가 있다면
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){ // 마지막 원소를 출력할 때
				cout << "[" << index << "|"; // 원소 출력
				cout << i -> data <<"]"; // 대괄호로 출력을 끝냄
			}
			
			else {
				cout << "[" << index << "|"; // 원소 출력
				cout << i -> data << "]->"; // 다음 원소를 계속 출력하기 위해 화살표 출력
				index++; // 인덱스를 늘려줌
			}
		}
		cout << endl; // 줄바꿈
	}

}


#endif
