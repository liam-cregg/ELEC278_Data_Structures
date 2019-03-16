    #include <stdio.h>
    #include <stdlib.h>

    typedef struct node{
        double coef;
        int exp;
        struct node* next;
    } Node;

    typedef struct LinkedList{
        Node *head;
    } LinkedList;

    LinkedList* init(LinkedList *l)
    {
        l = (LinkedList*)malloc(sizeof(LinkedList));
        l->head = NULL;
        return l;
    }

    int isEmpty(LinkedList* l)
    {
        return(l == NULL || l->head == NULL);
    }

    void removeElements(LinkedList* l)
    {
        while(!isEmpty(l)){
        Node* ptr = l->head;
        l->head = l->head->next;
        free(ptr);
        }
        l->head = NULL;
    }

    void destroy(LinkedList* l)
    {
        removeElements(l);
        free(l); //removes elements and frees linked list
    }

    Node* createNode(int _exp, int _coef, Node* nxt)
    {
        Node* pNode = (Node*)malloc(sizeof(Node));
        if (pNode != NULL){
            pNode->exp = _exp;
            pNode->coef = _coef;
            pNode->next = nxt;
        }
        return pNode;
    }

    void add(LinkedList* l, int _exp, int _coef)
    {
        if(l->head == NULL){
            l->head = createNode(_exp, _coef, NULL);
            return;
        }
        Node* ptr = l->head;           
        //code to add to front
        if(_exp > ptr->exp){
            l->head = createNode(_exp, _coef, l->head);
            return;
        }
        if(_exp == ptr->exp){
            ptr->coef += _coef;
            return;
        }
        while(ptr->exp > _exp){
            if(ptr->next == NULL)
                break;
            if(ptr->next->exp < _exp)
                break;
            else
                ptr = ptr->next;
        }
        if(ptr->exp == _exp){
            ptr->coef += _coef; //add coefficients if same degree
            return;
        }
        else
            if(ptr->next == NULL){
                ptr->next = createNode(_exp, _coef, NULL);
                return;
            }
            else{
                ptr->next = createNode(_exp, _coef, ptr->next->next);
                return;
            }
    }

    void plus(LinkedList* ll1, LinkedList* ll2, LinkedList* ll3)
    {
        Node* ptr1 = ll1->head;
        Node* ptr2 = ll2->head;
        removeElements(ll3);
        ll3->head = createNode(ptr1->exp, ptr1->coef, NULL); //since head became NULL
        Node* ptr3 = ll3->head;

        while(ptr1 != NULL){
            ptr3->next = createNode(ptr1->exp, ptr1->coef, NULL);
            ptr1 = ptr1->next;
        }

        while(ptr2 != NULL){
            add(ll3, ptr2->exp, ptr2->coef);
            ptr2 = ptr2->next;
        }
    }

    //TEST LATER

int main(){
    LinkedList* ll;
    ll = init(ll);

    add(ll, 3, 4);
    add(ll, 2, 5);
    add(ll, 3, 2);
    add(ll, 1, 5);

    LinkedList* ll2;
    ll2 = init(ll2);

    add(ll2, 3, 4);
    add(ll2, 2, 5);
    add(ll2, 5, 2);
    add(ll2, 4, 2);

    LinkedList* ll3;
    ll3 = init(ll3);

    plus(ll, ll2, ll3);

    Node* ptr = ll3->head;

    for(int i = 0; i < 5; i++){
        printf("%d^%d" , ptr->coef, ptr->exp);
        ptr = ptr->next;
    }

}
