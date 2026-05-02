#pragma once
#include "Order.h"
enum ActionType { ADD, REMOVE };
class Undo_Feature
{
private:
    struct Node
    {
        Order Data;
        ActionType Action;
        Node* Next;
        Node(Order o, ActionType a);
    };
    Node* top;
    int size;
public:
    Undo_Feature();
    void Push(Order o, ActionType a);
    ActionType TopAction();
    void Pop();           
    Order* Top();       
    ~Undo_Feature();
};

