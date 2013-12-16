class Seed{
  PVector pos;
  PVector vel;
  color c;
  
  Seed(){
    vel = new PVector(random(-2, 2), random(-2, 2));
    pos = new PVector(width/2, height/2);
    c = color(random(255), random(255), random(255));
  }
   
  void update(){
    pos.x += vel.x;
    pos.y += vel.y;
    
    if(pos.x < 0 || pos.x > width){
      vel.x *= -1;
    }
    if(pos.y < 0 || pos.y > height){
      vel.y *= -1;
    }
  }
  
  void drawSeed(){
    fill(255);
    noStroke();
    ellipse(pos.x, pos.y, 5, 5);
  }
}
