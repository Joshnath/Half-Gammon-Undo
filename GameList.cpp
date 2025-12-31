//This file defines the linked list and all the functions to modify the list and it's nodes

#include "GameList.h"
#include "GameNode.h"
#include "HalfGammonBoard.h"
#include <iostream>

using namespace std;

//Default constructor
GameList::GameList()
{
    head= nullptr;
}

//Creates node and makes it the new head of the linked list
void GameList::addToBeginning(HalfGammonBoard Game)
{
    GameNode* newNode = new GameNode(Game, head);
    head = newNode;
}

//Deletes current head and makes the following node the new head
void GameList::removeFromBeginning()
{
    GameNode* temp =  head;
    head = head -> getLink();
    delete temp;
}

//Gets the value of node at specified index
HalfGammonBoard GameList::get(int index)
{
    GameNode* current = head;

    for(int i = 0; i < index; i++)
    {
        current = current -> getLink();
    }

    return current -> getData();
}

//Returns the length of the linked list
int GameList::size()
{
    GameNode* current = head;
    int size = 0;
    while (current != nullptr)
    {
        size++;

        current = current -> getLink();
    }

    return size;
}