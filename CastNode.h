#ifndef CASTNODE_H
#define CASTNODE_H


#include <string>
#include <iostream>


class Cast 
{
private:

    std::string actorName;
    std::string role;
    Cast* next;

public:
    Cast(std::string name, std::string r);      //constructor

    //Getters
    std:: string getActorName();
    std::string getRole();
    Cast* getNext();

    //Setters
     void setNext(Cast* n);

};

//Implementation

Cast::Cast(std::string name, std::string r)
{
    actorName = name;
    role = r;
    next = nullptr;
}

std::string Cast::getActorName()
{
    return actorName;
}

std::string Cast::getRole()
{
    return role;
}

Cast* Cast::getNext()
{
    return next;
}

void Cast::setNext(Cast* n)
{
    next = n;
}



#endif 