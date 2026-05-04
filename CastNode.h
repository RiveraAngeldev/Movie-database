#ifndef CASTNODE_H
#define CASTNODE_H


#include <string>
#include <iostream>


class CastNode 
{
private:

    std::string actorName;
    std::string role;
    CastNode* next;

public:
    CastNode(std::string name, std::string r);      //constructor

    //Getters
    std:: string getActorName();
    std::string getRole();
    CastNode* getNext();

    //Setters
     void setNext(CastNode* n);

};

//Implementation

CastNode::CastNode(std::string name, std::string r)
{
    actorName = name;
    role = r;
    next = nullptr;
}

std::string CastNode::getActorName()
{
    return actorName;
}

std::string CastNode::getRole()
{
    return role;
}

CastNode* CastNode::getNext()
{
    return next;
}

void CastNode::setNext(CastNode* n)
{
    next = n;
}



#endif 