#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<typename T> // template 사용
class Stack : public LinkedList<T>{
	public:
		bool Delete (int &element){
			//first가 0이면 false반환
			if(this->first == 0) return false; // 첫번째 노드 주소가0 인 경우

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T>* tmp = this->first; // 첫번째 노드를 tmp에 저장
			element = tmp->data; // tmp의 data를 element에 저장
			this->first = tmp->link; // 첫번째 노드를 tmp->link로 바꿈
			delete tmp; // tmp에 할당된 메모리 해제
			this->current_size -= 1; // delete 하면 LinkedList 크기가 1 감소함

			return true; // delete에 성공할 경우 true 반환
			}
};
