    Node* connect(Node* root) {
        //iterative approach 
        //Stimulate a queue using the next pointer
        //keep track the first child Node you encounter as the start point of Next Level
        //use dummy head to connect child's next relationship 
        
        Node* dummyHead = new Node(-1);
        Node* tempHead = root;
        Node* prevNode = dummyHead;
        //thinking this as level order travel 
        //tempHead is the start point of the current level, when tempHead is NULL. we are done
        while(tempHead)
        {
            //inner while loop to traverse each Node in the current Level
            while(tempHead)
            {
                
                if(tempHead->left)
                {
                    prevNode->next = tempHead->left;
                    prevNode = prevNode->next;
                }
                if(tempHead->right)
                {
                     prevNode->next = tempHead->right;
                     prevNode = prevNode->next;
                }
                
                tempHead = tempHead->next;
            }
            
            //update the tempHead to next level's first node 
            tempHead = dummyHead->next;
            dummyHead->next = NULL;
            //reset PrevNode
            prevNode = dummyHead;
        }
        
        
        
        return root;
    }
