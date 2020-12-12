class Trie {
public:
    /** Initialize your data structure here. */
    //want to make Trie class friend of trieTreeNode class 
    //have access to all member functions and variable
   
    class trieTreeNode
    {
        //lowerCase -> 26 characters 
        friend class Trie;
        trieTreeNode()
        {
            for(int i = 0; i < 26;i++)
            {
                nodes[i] = NULL;
            }
            isWord = false;
        }
        private:
            trieTreeNode* nodes[26] ;
            bool isWord;
    };
    
    trieTreeNode* root;
    Trie() {
        root = new trieTreeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieTreeNode* temp = root;
        for(int i = 0; i < word.size();i++)
        {
            int index = word[i]-'a';
            if(temp->nodes[index] == NULL)
            {
                temp->nodes[index] = new trieTreeNode();
            }
            
            temp = temp->nodes[index];
        }
        temp->isWord = true;
    }
    /*   app 
          *
       temp  a
       temp   p
        temp   p
       temp      ->app (word)  
    */
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieTreeNode* temp = root;
        for(int i = 0 ; i < word.size();i++)
        {
            int index = word[i] - 'a';
            if(temp->nodes[index]==NULL)
                return false;
             temp = temp->nodes[index];
        }
        
        return temp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        trieTreeNode* temp = root;
        for(int i = 0 ; i < word.size();i++)
        {
            int index = word[i] - 'a';
            if(temp->nodes[index]==NULL)
                return false;
             temp = temp->nodes[index];
        }
        //as long as we finish iterating the word, we know there exist such words start with the prefix
        return true;
       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
