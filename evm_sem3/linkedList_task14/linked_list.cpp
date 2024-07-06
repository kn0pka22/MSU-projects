 
#include<iostream>
#include<cstring>
#include <fstream>
#include "linked_list.hpp"
#include  <cmath>






ListNode* Process(ListNode* head) {
    ListNode* cur=head, *tmp, *prev;
   
    if ((head!=nullptr) && (head->next!=nullptr)){
    	head=head->next;
    	tmp=head->next;
    	head->next=cur;
    	cur->next=tmp;
    }
    	
		while ((cur->next!=nullptr)){
			prev=cur->next;
			if (cur->next->next!=nullptr){
			 cur->next=cur->next->next;
			cur=cur->next;
			tmp=cur->next;
			cur->next=prev;		
			cur=cur->next;
			cur->next=tmp;
		}
		else break;
		
		
		/*	if (cur==head){
				head=head->next;
				tmp=head->next;
				head->next=cur;
				prev=cur;
				cur->next=tmp;
				//cur=cur->next;
			}
			cur->next=cur->next->next;
			cur->next=cur;
			tmp=cur->next;
			cur->next=tmp;
			cur=cur->next;
			*/	
		}
		
		
    return head;
}
