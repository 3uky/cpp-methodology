namespace containers
{

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList 
{
    public:
        LinkedList() : head(nullptr), tail(head) {};
        ~LinkedList() 
        {                
                while(head)
                {
                    Node* deleteNode = head;
                    head = head->next;    
                    delete deleteNode;
                }
                head = nullptr;
                tail = nullptr;
        }

        void push_front(int value)
        {
            Node* newNode = new Node(value);

            newNode->next = head;

            if(!head)
            {
                tail = newNode;
            }
            else
            {
                head->prev = newNode;
            }

            head = newNode;           
        }

        void push_back(int value)
        {
            Node* newNode = new Node(value);

            newNode->next = nullptr;
            newNode->prev = tail;

            if (!tail) 
            {
                head = newNode;
            } 
            else 
            {      
                tail->next = newNode;
            }

            tail = newNode;
        }

        Node* find(int value)
        {
            Node* currentNode = head;
            while(currentNode)
            {
                if(currentNode->data == value)
                {
                    return currentNode;
                }        
                currentNode = currentNode->next;                
            }
            return nullptr;
        }

        void removeNode(int value)
        {
            Node* removeNode = find(value);
            if(!removeNode)
                return;         
            
            if(head == removeNode)
            {
                head = head->next;
            }
            else
            {
                removeNode->prev->next = removeNode->next;
                if(removeNode->next)
                    removeNode->next->prev = removeNode->prev;
            }
            delete removeNode;
        }

        Node* head;
        Node* tail;
};


}