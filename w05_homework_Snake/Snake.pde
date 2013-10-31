class Snake {
    float catchUpSpeed;
    float angle;
    float radius;
    float parts;
    
    PVector pos;
    PVector mousePos;
    
  Snake(){
    catchUpSpeed = 0.005;
    radius = 15;
    parts = 20;
    
    pos = new PVector();
    mousePos = new PVector();
  }
  
  void draw(){
    pushMatrix();
      translate((float)pos.x, (float)pos.y);
      
      mousePos.x = mouseX;
      mousePos.y = mouseY;
      
      float dx = mousePos.x - pos.x;
      float dy = mousePos.y - pos.y;
      
      angle = atan2(dy, dx);
      rotate(radians(angle+PI));
      
      pos.x = catchUpSpeed * mousePos.x + (1-catchUpSpeed) * pos.x;
      pos.y = catchUpSpeed * mousePos.y + (1-catchUpSpeed) * pos.y;
      
      //snake
      fill(255);
      for(int i = 0; i < parts; i++){
        float angle = (millis()*0.003)+(TWO_PI/parts*i);
        float add = radius * sin(angle);
        fill(255);
        ellipse(5*i, 0+add, 5, 5);
      }
    popMatrix(); 
  }
}
