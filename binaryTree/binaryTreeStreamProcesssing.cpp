//Giving you an input Stream
//Want to design two functionalty 

// 1. add Number (int x) 
// 2. count number of smaller numbers(int target)

//add(1)
//add(4)
//add(2)
//count(3) -> return 2
//add(5)
//count(7) ->return 4
//count(0) ->return 0

//Data Strucuture
// Binary Search Tree
struct treeNode
{
    int val;
    int duplicate;
    int smallNumbers;
    treeNode* left;
    treeNode* right;
    treeNode(): val(0),left(NULL),right(NULL),duplicate(0),smallNumbers(0){}
    treeNode(int _val,int dup, int sm):val(_val),left(NULL),right(NULL),duplicate(dup),smallNumbers(sm){}
    treeNode(int _val, treeNode* l, treeNode* r): val(_val), left(NULL),right(NULL){}
};

class bst
{   
    private:
        treeNode* root;
    public:
    void addNode(int _val)
    {
        //corner case
       
        
        if(root == NULL)
        {
            root =  new treeNode(_val,1,0);
            return;
        }
        
        treeNode* cur = root;
        treeNode* prev = NULL;
        //1. find correct place to insert 
        //2. update the root attribute if root->val > target
        //Note: becaree full when root is NULL
        // 1(1,0)
        //   4(1,0)
        //
        int smallerCount = 0;
        while(cur)
        {
            if(cur->val > _val)
            {
                //4 2 
                //update smaller number count for cur Root
                cur->smallNumbers++;
                prev = cur;
                cur = cur->left;
            }
            else if(cur->val <_val)
            {
                //smallerCount+= cur->smallNumbers;
                prev = cur;
                cur = cur->right;
            }
            else
            {
                cur->duplicate++;
                return;
            }            
        }
        
        if(prev->val > _val)
        {
            prev->left = new treeNode(_val,1,smallerCount);
        }
        else if(prev->val < _val)
        {
             prev->right = new treeNode(_val,1,smallerCount);
        }
        return ;
    }
    int queryNode(int _val)
    {
        /*
                    1 (0,1)
                        4 (1,1)
                      2(0,1)   5   (0,1)
        */
        int result = 0;
        treeNode* cur = root;
        while(cur)
        {
            //cout<<cur->val<<" "<<cur->smallNumbers<<" "<<cur->duplicate<<endl;
            if(cur->val == _val)
            {
                return result;
            }
            //root > _val
            else if(cur->val > _val)
            {
                cur = cur->left;
            }
            else
            {
                result = result + cur->smallNumbers + cur->duplicate;
                cur = cur->right;
            }   
        }
        
        return result;
    }
    
};

class streamManager{
    private: 
        bst* bstManager;
    public:
        streamManager(){
            bstManager = new bst();
        }
        void add(int input)
        {
            bstManager->addNode(input);
        }
        int query(int target)
        {
            return bstManager->queryNode(target);
        }
};



//add(1)
//add(4)
//add(2)
//count(3) -> return 2
//add(5)
//count(7) ->return 4
//count(0) ->return 0

int main() {
    std::cout << "Hello World!\n";
    streamManager s1;
    s1.add(3);
    s1.add(4);
    s1.add(4);
    s1.add(2);
    cout<<s1.query(3)<<endl;
    s1.add(5);
    cout<<s1.query(4)<<endl;
    cout<<s1.query(1000)<<endl;
    return 0;
}
