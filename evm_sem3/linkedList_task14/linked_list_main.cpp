#include <iostream>
#include "linked_list.hpp"


int main(){



		int value;
    ListNode* head = nullptr;
    ListNode* Now = nullptr;
    int i, size;
    std::cout << "Input number of elements" << std::endl;
    std::cin >> size;
    std::cout << "Input elements of list" << std::endl;
    for (i = 0; i < size; i++) 
    {
        std::cin >> value;
        ListNode* New = new ListNode;
        New->value = value;
        New->next = nullptr;
        if (head == nullptr) head = New;
        else {
            Now = head;
            while (Now->next != nullptr) Now = Now->next;
            Now->next = New;
        }
    }
    
    head = Process(head);

    std::cout << "Result" << std::endl;
    while (head != nullptr) {
        std::cout << head->value << std::endl;
        head = head->next;
    }

		/*int size,value;
    std::cout << "Input number of elements\n" << std::endl;
    std::cin >> size;
    ListNode* head=new ListNode;
    ListNode* cur=head;
    std::cout << "Input elements of list\n" << std::endl;
    std::cin >> value;
    cur->value = value;
    
    for (int i = 1; i < size-1; i++){
    	ListNode* New = new ListNode;
    	cur->next=New;	
    	cur=cur->next;
    	std::cin >> value;
    	cur->value=value;
    }
    cur=cur->next;
    std::cin >> value;
    cur->value=value;
    cur->next=nullptr;*/
    return 0;
}
