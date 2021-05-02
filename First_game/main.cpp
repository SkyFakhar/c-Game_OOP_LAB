#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<time.h>

using namespace sf;
using namespace std;
class doodle{
private:
    struct Point{int x,y;};
    int score;
public:
    doodle2(){
        score=0;
        }
        void Game()
    {
        srand(time(0));

    RenderWindow app(VideoMode(400,533),"Doodle Game");
    app.setFramerateLimit(60);

                      Texture t1, t2, t3;
                      t1.loadFromFile("images/background.jpg");
                      t2.loadFromFile("images/platform.png");
                      t3.loadFromFile("images/doodle2.png");

                      Sprite sBack(t1), sPlat(t2), sPers(t3);

                      Point Plat[8];

                      for(int i=0; i<8; i++){
                        Plat[i].x = rand()% - 350;
                        Plat[i].y = rand()% - 500;
                      }

                      int x=100, y=100, h=200;
                      float dx=0,dy=0;

                      while (app.isOpen()){
                        Event e;
                        while(app.pollEvent(e))
                        {if(e.type==Event::Closed)
                            app.close();
                      }

                      if(Keyboard::isKeyPressed(Keyboard::Right))
                        x+=3;
                      if(Keyboard::isKeyPressed(Keyboard::Left))
                        x-=3;

                      dy+=0.2;
                      y+=dy;

                      if(y>500)
                        dy=-10;

                      if(y<h)
                      for(int i=0; i<8; i++){
                        y=h;
                        Plat[i].y=Plat[i].y-dy;
                        if(Plat[i].y>500){
                            Plat[i].y=0;
                            Plat[i].x=rand()%350;
                        }
                      }

                      for(int i=0; i<8; i++)
                        if((x+50>Plat[i].x) &&
                           (x+20<Plat[i].x+68) &&
                           (y+70>Plat[i].y) &&
                           (y+70<Plat[i].y+14) &&
                           (dy>0)
                      ){
                      dy=-10;
                      score++;}


                      sPers.setPosition(x,y);

                      app.draw(sBack);
                      app.draw(sPers);
                      for(int i=0; i<8; i++){
                        sPlat.setPosition(Plat[i].x, Plat[i].y);
                        app.draw(sPlat);
                      }

                      Font arial;
                      arial.loadFromFile("arial.ttf");
                          ostringstream ssScore;
                      ssScore<<"Score: "<<score;
                      Text lblScore;
                      lblScore.setCharacterSize(30);
                      lblScore.setPosition(10,10);
                      lblScore.setFont(arial);
                      lblScore.setColor(Color::Blue);
                      lblScore.setString(ssScore.str());
                      app.draw(lblScore);


                      app.display();
                      }
    }
};

int main(){

doodle d;
d.Game();

return 0;

}

