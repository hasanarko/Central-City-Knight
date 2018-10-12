#ifndef GOONS_H_INCLUDED
#define GOONS_H_INCLUDED
#include <iostream>
#include <cmath>
using namespace std;

struct Windows{

    double x1;
    double x2;
    double y1;
    double y2;

};



class Goons{

private:
    double tx;
    double ty;
    double bulletTx;
    double bulletTy;
    double bulletSx = 1;
    double bulletSy = 1;
    double coordX[4] = {-0.2f , 0.1f ,-0.2f , 0.1f};
    double coordY[4] = {0.6f , 0.6f ,0.25f ,  0.25f};
    int coordIndex = 0;
    Windows window[4];
public:
    Goons()
    {
        window[0].x1 = -0.21f; window[0].x2 = -0.045f; window[0].y1 = 0.57f; window[0].y2 = 0.78f;
        window[1].x1 =  0.04f; window[1].x2 =  0.206f; window[1].y1 = 0.57f; window[1].y2 = 0.78f;
        window[2].x1 = -0.21f; window[2].x2 = -0.045f; window[2].y1 = 0.24f; window[2].y2 = 0.45f;
        window[3].x1 =  0.04f; window[3].x2 =  0.206f; window[3].y1 = 0.24f; window[3].y2 = 0.45f;
    }
    void appear()
    {

       // glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(bulletSx , bulletSy , 0);
        glTranslatef(bulletTx , bulletTy  , 0.0f);
        drawBullet();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(tx , ty  , 0.0f);
        drawGoon();
        glPopMatrix();
       // glutSwapBuffers();
        //glFlush();
    }
    bool killed(double mx , double my)
    {
        //cout << mx << " == " << coordX[coordIndex] << "  "<< my << " == " << coordY[coordIndex] << endl;
        //cout << (mx == coordX[coordIndex]) << endl;
        if((mx >= window[coordIndex].x1 && mx <= window[coordIndex].x2) && (my >= window[coordIndex].y1 && my <= window[coordIndex].y2))
        {
           // cout << "Boom!" << endl;
            return true;
        }

        return false;
    }
    void respawn()
    {
        int newIndex = randRange(4,0);
        //cout << newIndex << endl;
        this->tx = coordX[newIndex] - coordX[0];
        this->ty = coordY[newIndex] - coordY[0];
        this->bulletTx = coordX[newIndex] - coordX[0];
        this->bulletTy = coordY[newIndex] - coordY[0];
        this->bulletSx = 1;
        this->bulletSy = 1;
        coordIndex = newIndex;
    }
    bool shoot()
    {
        bool hit_success = false;

        this->bulletTy -= 0.04f;
        bulletSx += 0.09;
        bulletSy += 0.09;
        if(this->bulletTy  + coordY[0] < -0.5f)
        {
            if(hit())
                hit_success = true;
            this->bulletTx = coordX[coordIndex] - coordX[0];
            this->bulletTy = coordY[coordIndex] - coordY[0];
            this->bulletSx = 1;
            this->bulletSy = 1;
        }
        return hit_success;
    }
    bool hit()
    {
        if(this->bulletTy < -0.5)
        {
            return true;
        }
        return false;
    }
    void drawGoon()
    {
       glBegin(GL_QUADS);
       glColor3f(1.0f , 0.0f , 0.0f);
       glVertex2f(-0.2f , 0.6f);
       glVertex2f(-0.2f , 0.75f);
       glVertex2f(-0.1f , 0.75f);
       glVertex2f(-0.1f , 0.6f);
       glEnd();
       glLoadIdentity();
    }
    void drawBullet()
    {
       /* glPointSize(10);
       glBegin(GL_POINTS);
       glColor3f(1.0f , 1.0f , 0.0f);
       glVertex2f(-0.1f , 0.7f);
       glEnd();*/
       glBegin(GL_QUADS);
       glColor3f(1.0f , 1.0f , 0.0f);
       glVertex2f(-0.1f , 0.6f);
       glVertex2f(-0.1f , 0.75f);
       glVertex2f(0.0f , 0.75f);
       glVertex2f(0.0f , 0.6f);
       glEnd();
       glLoadIdentity();
    }
    int randRange(int high,int low)
    {
        return rand() % (high-low)+low;
    }


};






#endif // GOONS_H_INCLUDED
