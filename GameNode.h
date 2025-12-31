//This file creates all the functions and varaibles for the node

#pragma once
#include "HalfGammonBoard.h"

class GameNode
{
    private:
        HalfGammonBoard data;
        GameNode* link;
    public:
        GameNode();
        GameNode(HalfGammonBoard theData, GameNode* theLink);
        GameNode* getLink() const;
        HalfGammonBoard getData() const;
        void setData(HalfGammonBoard theData);
        void setLink(GameNode* theLink);
};