//This file defines the individual nodes the linked list uses and all the functions the linked list uses to modify each node

#include "GameNode.h"
#include <iostream>

using namespace std;

//Default contrucutor 
GameNode::GameNode()
{
    this -> link = nullptr;
}

//Creates a node with specified data and link
GameNode::GameNode(HalfGammonBoard theData, GameNode* theLink)
{
    this -> data = theData;
    this -> link = theLink;
}

//Returns the location of link of following node
GameNode* GameNode::getLink() const
{
    return link;
}

//Returns the data of the node
HalfGammonBoard GameNode::getData() const
{
    return data;
}

//Changes the value of the data for the current node
void GameNode::setData(HalfGammonBoard theData)
{
    this -> data = theData;
}

//Changes the value of link for the current node
void GameNode::setLink(GameNode* theLink)
{
    this -> link = theLink;
}
