/*
Sort Binary Linked List

Problem Description
Given a Linked List A consisting of N nodes.
The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.
You need to sort the linked list and return the new linked list.

NOTE:

Try to do it in constant space.


Problem Constraints
 1 <= N <= 105

 A.val = 0 or A.val = 1



Input Format
First and only argument is the head pointer of the linkedlist A.



Output Format
Return the head pointer of the new sorted linked list.



Example Input
Input 1:

 1 -> 0 -> 0 -> 1
Input 2:

 0 -> 0 -> 1 -> 1 -> 0


Example Output
Output 1:

 0 -> 0 -> 1 -> 1
Output 2:

 0 -> 0 -> 0 -> 1 -> 1


Example Explanation
Explanation 1:

 The sorted linked list looks like:
  0 -> 0 -> 1 -> 1
Explanation 2:

 The sorted linked list looks like:
  0 -> 0 -> 0 -> 1 -> 1

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {

    ListNode* zeroHead = NULL;
    ListNode* zeroTail = NULL;
    ListNode* oneHead = NULL;
    ListNode* oneTail = NULL;
    
    while(A){
        if(A->val==0){
            if(zeroHead==NULL){
                zeroHead = zeroTail = A;
            }else{
                zeroTail->next = A;
                zeroTail = zeroTail->next;
            }
        }else{
            if(oneHead==NULL){
                oneHead = oneTail = A;
            }else{
                oneTail->next = A;
                oneTail = oneTail->next;
            }
        }
        A = A -> next;
    }
    
    if(zeroTail == NULL) return oneHead;
    zeroTail->next = oneHead;
    if(oneTail == NULL) return zeroHead;
    oneTail->next = NULL;
    return zeroHead;
}
Time taken: 3 min.
Score:
200
/
200
C++17 (Gcc-9.2)
Old view
