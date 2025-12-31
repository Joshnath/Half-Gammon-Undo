//This file creates all the variables and functions the the linked list

#pragma once
#include "GameNode.h"
#include "HalfGammonBoard.h"

class GameList
{
    private:
        GameNode* head;
    public:
        GameList();

        void addToBeginning(HalfGammonBoard Game);
        void removeFromBeginning();
        HalfGammonBoard get(int index);
        int size();
};