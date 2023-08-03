class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        //step 1 -> make nodes and club them with original nodes
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        //step 2->join the random ptrs of new nodes
        Node* iter = head;
        while(iter != NULL){
            if(iter->random != NULL)  
                iter->next->random = iter->random->next;//point the the nodes to random ptr
            iter = iter->next->next;
        }

        //step 3-> segregate the original and copy list
        Node* dummy = new Node(0);
        iter = head;
        temp = dummy;
        while(iter != NULL){
            Node* front = iter->next->next;
            temp->next = iter->next;

            iter->next = front;
            temp = temp->next;
            iter = iter->next;
        }
        return dummy->next;
    }
};
//TC - O(3N)
//SC - O(1)
