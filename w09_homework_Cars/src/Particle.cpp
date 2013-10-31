//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle() {
//    setParams(0,0,0);
    damping = ofVec2f( 0.01f );
}

void Particle::setParams( ofVec2f _pos, ofVec2f _vel, float _speed, float _force ){
    pos.set( _pos );
    vel.set( _vel );
    
    maxSpeed = _speed;
    maxForce = _force;
    
    lastPos.set( pos );
}

void Particle::addForce( ofVec2f force ){
    acc += force;       // F = MA
}

void Particle::seek( ofVec2f dest ) {
    float slowDownRadius = 200.0;
    
    ofVec2f desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }

    ofVec2f steer = desired - vel;
    steer.limit( maxForce );
    
    addForce( steer );
}

//------------------------------------------------------------
void Particle::addRepulsionForce( float px, float py, float radius, float strength){
	
	ofVec2f posOfForce;
	posOfForce.set(px, py);
	
	ofVec2f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
        
		frc.x += diff.x * pct * strength;
		frc.y += diff.y * pct * strength;
	}
	
}

void Particle::update() {
    vel = vel + acc;
    pos = pos + vel;
    
    vel *= 0.97;
    
    acc *= 0;
    
    lastPos.set( pos );
}

void Particle::draw() {
//    ofCircle(pos.x, pos.y, 4);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
        float rotAmt = atan2( vel.y, vel.x );
        ofRotate( ofRadToDeg(rotAmt) + 90 );
        ofRectRounded(0, 0, 20, 40, 5);
        //ofRect( 0,0, 20, 40);
    
        ofEllipse(10, 0, 5, 2);
        ofEllipse(-10, 0, 5, 2);
    
        ofSetColor(0);
        ofRectRounded(0, -4, 15, 8, 2);
    
    ofPopMatrix();
}