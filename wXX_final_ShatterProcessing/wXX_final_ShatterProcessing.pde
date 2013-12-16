Seed[] seedList;

void setup(){
  size(500, 500);
  smooth();
  
  seedList = new Seed[10];
  for(int i = 0; i < seedList.length; i++){
    seedList[i] = new Seed();
  }
}
 
void draw(){
  drawCell();
  for(int i = 0; i < seedList.length; i++){
    Seed s = seedList[i];
    s.update();
  }
  
  for(int i = 0; i < seedList.length; i++){
    Seed s = seedList[i];
    s.drawSeed();
  }
}
 
void drawCell(){
  loadPixels();
  for(int x = 0; x < width; x++){
    for(int y = 0; y < height; y++){
      float minDist = width + height;
      int closest = 0;
      for(int i = 0; i < seedList.length; i++){
        Seed s = seedList[i];
        PVector tmp = new PVector(x, y);
        float d = dist(tmp.x, tmp.y, s.pos.x, s.pos.y);
        if (d < minDist){
          closest = i;
          minDist = d;
        }
      }
      pixels[y * width + x] = seedList[closest].c;
    }
  }
  updatePixels();
}

