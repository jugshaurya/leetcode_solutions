/*
Given a linked list A , reverse the order of all nodes at even positions.

Problem Constraints
1 <= Size of linked list <= 100000

Input Format
First and only argument is the head of the Linked-List A.

Output Format
Return the head of the new linked list.

Example Input
Input 1:
A = 1 -> 2 -> 3 -> 4

Input 2:
A = 1 -> 2 -> 3

Example Output
Output 1:
 1 -> 4 -> 3 -> 2

Output 2:
 1 -> 2 -> 3

Example Explanation
Explanation 1:
Nodes are positions 2 and 4 have been swapped.

Explanation 2:
No swapping neccassary here.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = next;
    }
    
    return prev;
}

ListNode* Solution::solve(ListNode* head) {
    if(head==NULL or head->next==NULL) return head;
     
    ListNode* oddHead = head;
    ListNode* oddTail = head;
    ListNode* evenHead = head->next;
    ListNode* evenTail = head->next;
    
    ListNode* start = evenHead->next;
    int cnt = 0;
    while(start){
        cnt++;
        if(cnt&1){
            oddTail->next = start;
            oddTail = oddTail->next;
        } else{
            evenTail->next = start;
            evenTail = evenTail->next;
        }   
        start = start->next;
    }
    oddTail->next = NULL;
    evenTail->next = NULL;

    evenHead = reverseList(evenHead);
    
    ListNode* ans = oddHead;
    
    while(evenHead){
        ListNode* oddTemp = oddHead->next;
        oddHead->next = evenHead;
        ListNode* evenTemp = evenHead->next; 
        evenHead->next = oddTemp;
        oddHead = oddTemp;
        evenHead = evenTemp;
    }
    
    return ans;
}
