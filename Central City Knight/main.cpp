#include<cstdio>
#include<math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "scene_objects.h"
#include "Goons.h"
#include "Flash.h"
#include "intro.h"
#include "Arrow.h"
#include "Zoom.h"
#include "Joker.h"
#include "ReverseFlash.h"
using namespace std;

Goons goon;
Flash flash;
Arrow arrow;
Zoom zoom;
ReverseFlash rf;
Joker joker;
float mouseX;
float mouseY;
int score = 0;
int lifes = 5;
bool gameover = true;
bool gamestart = false;
bool isArrow = false;
bool isZoom = false;
bool isJoker = false;
bool isrf = false;
int level = 1;

void Sprint(double red , double green , double blue ,  float x, float y, string st)
{
    glColor3f(red,green,blue);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for(int i=0; i < st.length(); i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);

    }
     glEnd();
    glFlush();
}

void update(int _)
{
    if(!gameover)
    {
       if(goon.shoot())
          lifes--;
       if(isArrow && arrow.attack())
            lifes-=2;
       if(isZoom && zoom.attack())
            lifes-=2;
       if(isJoker && joker.attack())
            lifes-=2;
       if(isrf && rf.attack())
            lifes-=2;
    }
    if(lifes <= 0)
    {

        gameover = true;
        //gamestart = false;
    }


    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}



void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(8.0f);
   glLoadIdentity();

   if(!gamestart)
   {
      draw_flash();
      drawHead();
      /* Start Button */
      glBegin(GL_QUADS);
      glColor3f(1.0f , 0.0f , 0.0f);
      glVertex2f(0.3f , -0.6f);
      glVertex2f(0.3f , -0.4f);
      glVertex2f(0.7f , -0.4f);
      glVertex2f(0.7f , -0.6f);
      glEnd();

      Sprint(0.0f , 0.0f , 0.0f , 0.38f , -0.52f , "START GAME");
      Sprint(1.0f , 0.0f , 0.0f , 0.38f ,  0.7f , "CENTRAL CITY KNIGHT");
      Sprint(1.0f , 1.0f , 0.0f , 0.4f ,  0.6f , "ZAPPING!");

   }
   else
   {
       if(level == 1)
       {
                 /* Sky */
           lvl1.draw_sky();

           /* draw_plant */
           lvl1.draw_plant();


           /* Road */
           lvl1.draw_road();

           /* Fence */
           lvl1.draw_fence();

           /* Building */
           lvl1.draw_building();
       }
        if(level == 2)
       {
                 /* Sky */
           lvl2.draw_sky();

           /* draw_plant */
           lvl2.draw_plant();


           /* Road */
           lvl2.draw_road();

           /* Fence */
           lvl2.draw_fence();

           /* Building */
           lvl2.draw_building();
       }
        if(level == 3)
       {
                 /* Sky */
           lvl3.draw_sky();

           /* draw_plant */
           lvl3.draw_plant();


           /* Road */
           lvl3.draw_road();

           /* Fence */
           lvl3.draw_fence();

           /* Building */
           lvl3.draw_building();
       }
        if(level == 4)
       {
                 /* Sky */
           lvl4.draw_sky();

           /* draw_plant */
           lvl4.draw_plant();


           /* Road */
           lvl4.draw_road();

           /* Fence */
           lvl4.draw_fence();

           /* Building */
           lvl4.draw_building();
       }




       flash.appear();
       goon.appear();
       if(isArrow)
        arrow.appear();
       if(isZoom)
        zoom.appear();
       if(isJoker)
        joker.appear();
       if(isrf)
        rf.appear();

       if(score % 250 == 0 && score > 0)
        {
            if(level == 1)
               isArrow = true;
            if(level == 2)
               isZoom = true;
            if(level == 3)
               isJoker = true;
            if(level == 4)
               isrf = true;

        }

        /* Lives */
       glBegin(GL_QUADS);
       glColor3f(1.0f , 0.0f , 0.0f);
       for(float x = 0.9f , i = 0.0f; i < lifes; i++,x-=0.1f)
       {
          glVertex2f(x , 0.9f);
          glVertex2f(x , 1.0f);
          glVertex2f(x + 0.05f , 1.0f);
          glVertex2f(x + 0.05f , 0.9f);
       }
       glEnd();

       ostringstream convert;
       convert << score;

       if(gameover)
       {
           glBegin(GL_QUADS);
           glColor3f(0.0f , 0.0f , 0.0f);
           glVertex2f(-0.21f , -0.3f);
           glVertex2f(-0.21f , 0.14f);
           glVertex2f(0.204f , 0.14f);
           glVertex2f(0.204f , -0.3f);
           glEnd();
           Sprint(1.0f , 0.0f , 0.0f , -0.15 , 0.0 , "GAME OVER!");
           Sprint(1.0f , 0.0f , 0.0f , -0.15 , -0.1 , "Your Score: " + convert.str());

       }
       Sprint(1.0f , 0.0f , 0.0f , -1.0f , 0.9f , "SCORE: " + convert.str());




       glutPostRedisplay();
   }





   glFlush();
}
void nextLevel()
{
    level++;
    lifes = 5;
    score = 0;
}
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
	    if(state == GLUT_DOWN && !gamestart)
        {
            if((mouseX >= 0.3f && mouseX <= 0.7f) && (mouseY >= -0.6f && mouseY <= -0.4f))
            {
                gamestart = true;
                gameover = false;
            }
        }
		if (state == GLUT_DOWN && !gameover)
		{
		    //cout << mouseX << " " << mouseY << endl;
		    if(goon.killed(mouseX , mouseY))
            {
                goon.respawn();
                score+=10;
                if(score % 50 == 0)
                {
                    if(level ==1 && !isArrow)
                        lvl1.door_open();
                    if(level ==2 && !isZoom)
                        lvl2.door_open();
                    if(level ==3 && !isJoker)
                        lvl3.door_open();
                    if(level ==4 && !isrf)
                        lvl4.door_open();
                }

            }
            if(isArrow)
            {
                if(arrow.killed(mouseX , mouseY))
                {
                    score+=10;
                    arrow.respawn();
                    if(arrow.isDead())
                    {
                        isArrow = false;
                        nextLevel();
                    }
                }
            }
            if(isZoom)
            {
                if(zoom.killed(mouseX , mouseY))
                {
                    score+=10;
                    zoom.respawn();
                    if(zoom.isDead())
                    {
                        isZoom = false;
                        nextLevel();
                    }
                }
            }
             if(isJoker)
            {
                if(joker.killed(mouseX , mouseY))
                {
                    score+=10;
                    joker.respawn();
                    if(joker.isDead())
                    {
                        isJoker = false;
                        nextLevel();
                    }
                }
            }
            if(isrf)
            {
                if(rf.killed(mouseX , mouseY))
                {
                    score+=10;
                    rf.respawn();
                    if(rf.isDead())
                    {
                        isrf = false;
                        gameover = true;
                    }
                }
            }

		}

	}
}
void handleKeypress(unsigned char key, int x, int y) {

    if(!gameover)
    {
        if(key == 'd')
        {
          flash.moveRight();
          glutPostRedisplay();
        }
        else if(key == 'a')
        {
          flash.moveLeft();
          glutPostRedisplay();
        }
    }

   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}
void setMouseLocation(int x , int y)
{
    mouseX =  x *(2/ (float) 1366) - 1;
    mouseY =  (y * (2/ (float) 768) - 1) * -1;
    mouseX = (int)(mouseX * 100.0)/100.0;
    mouseY = (int)(mouseY * 100.0)/100.0;
//cout << mouseX << " " << mouseY << endl;
}


int main(int argc, char** argv) {
   srand(time(0));
   glutInit(&argc, argv);
   glutInitWindowSize(1366, 768);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Downtown Zapping");
   glutDisplayFunc(display);
   glutPassiveMotionFunc(setMouseLocation);
   glutMouseFunc(handleMouse);
   glutFullScreen();
//   glutKeyboardFunc(keyboard);
   glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, update, 0);
   init();
  // glutKeyboardFunc(handleKeypress);
   //glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
