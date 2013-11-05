//
//  Card.cpp
//  w07_homework_Solitaire
//
//  Created by Mirte Becker on 10/20/13.
//
//

#include "Card.h"

Card::Card(){
    card.loadImage("queen.png");
    pos.set(850, 40);
    mouse.set(ofGetWindowSize()/2);
}

void Card::update(ofVec2f _mouse){
    mouse = _mouse;
    
    frc.set(-0.01f, 0.9f);
    acc += frc;
    vel += acc;
    pos += vel;
    
    if( pos.x < 0 || pos.x > ofGetWindowWidth()-card.getWidth()){
        vel.x *= -1;
    }
    if(pos.y < 0 || pos.y > ofGetWindowHeight()-card.getHeight()){
        vel.y *= -1;
    }
    
    acc.set(0);
}

void Card::draw( bool _useMouse ){
    if(_useMouse == true){
        card.draw(mouse);
    }else{
        card.draw(pos);
    }
}