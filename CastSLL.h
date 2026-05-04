#pragma once
#include <iostream>
#include "CastNode.h"

using namespace std;

class CastSLL
{
private:
    CastNode* head;

public:
    CastSLL();
    void addActor(string name, string role);
    void printCast() const;

};

//Implementation

CastSLL::CastSLL()
{
    head = nullptr;
}

void CastSLL::addActor(string name, string role)
{
    CastNode* newNode = new CastNode(name,role);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    CastNode* temp = head;
    
    while(temp->getNext() != nullptr)
    {
        temp = temp->getNext();
    }
    
        temp->setNext(newNode);
    
}

void CastSLL::printCast() const
{
    if (head == nullptr)
    {
        cout << "No cast members added yet." << endl;
        return;
    }

    CastNode* temp = head;
    
    while (temp != nullptr)
    {
        cout << " - " << temp->getActorName() << " as " << temp->getRole() << endl;
        temp = temp->getNext();
    }
}