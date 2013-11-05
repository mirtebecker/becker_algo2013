//
//  Card.h
//  w07_homework_Solitaire
//
//  Created by Mirte Becker on 10/20/13.
//
//

#pragma once
#include "ofMain.h"

class Card{
public:
    
    Card();
    
    void update(ofVec2f _mouse);
    void draw(bool _useMouse);
    
    ofImage card;
    
    ofVec2f pos;
    ofVec2f mouse;
    
    ofVec2f vel;
    ofVec2f acc;
    ofVec2f frc;
    
};