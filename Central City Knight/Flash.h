#ifndef FLASH_H_INCLUDED
#define FLASH_H_INCLUDED


class Flash{

private:
    double tx;
    double ty;

public:
    void appear()
    {
        glPushMatrix();
        glTranslatef(tx , ty , 0.0f);
        draw_flash();
        drawHead();
        glPopMatrix();
    }
    void moveLeft()
    {
        this->tx -= 0.05f;
    }
    void moveRight()
    {
        this->tx += 0.05f;
    }
    float topLeftX()
    {
        return (tx);
    }
    float topRightX()
    {
        return ty;
    }
    float drawCurve(float p1, float p2, float p3,float p4, float t)
    {
        float pf=0;
        float s=1-t;
        pf=p1*pow(s,3) + 3*p2*pow(s,2)*t+ 3*s*pow(t,2)*p3 + pow(t,3)*p4;
        return pf;
    }

    float drawCurve2(float p1, float p2, float p3, float t)
    {
        float pf=0;
        float s=1-t;
        pf=p1*pow(s,2) + 3*p2*s*t+ pow(t,2)*p3;
        return pf;
    }


    void draw_flash()
    {
        glPushMatrix(); //Save the current state of transformations
        glTranslatef(1.8, 0.8, 0.0);
        glScalef(2.0, 3.0, 0.0);
        //glTranslatef(0.0+flashx, 0.0+flashy, 0.0);
        glPushMatrix(); //Save the current state of transformations
        glScalef(0.06, 0.10, 0.02);
        glTranslatef(-15.0, -4.5, 0.0);

        glPushMatrix(); //Save the current state of transformations
        glTranslatef(0.0, 1.0, 0.0);
        glColor3f(0.921, 0, 0.050);
        glScalef(0.40, 0.50, 0.50); //Scale by 0.7 in the x, y, and z directions
        glutSolidCube(1);///head
        glPopMatrix(); //Undo the move to the center of the pentagon/*

        glPushMatrix();
        glScalef(0.7, 1.00, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(1.0,0.7,0.8);
        glTranslatef(0.0, 0.3, 0.0);
        glutSolidCube(1);///body
        glPopMatrix();

        glPushMatrix();
        glScalef(0.33, 0.40, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.921, 0, 0.050);
        glTranslatef(1.53, 1.5, 0.0);
        glutSolidCube(1);///right arm
        glPopMatrix();

        glPushMatrix();
        glScalef(0.33, 0.40, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.921, 0, 0.050);
        glTranslatef(-1.53, 1.5, 0.0);
        glutSolidCube(1);///left arm
        glPopMatrix();

        glPushMatrix();
        glScalef(0.2, 0.60, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.3,0.4,0.8);
        glTranslatef(2.60, 0.2, 0.0);
        glutSolidCube(1);///right hand
        glPopMatrix();

        glPushMatrix();
        glScalef(0.2, 0.60, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.3,0.4,0.8);
        glTranslatef(-2.60, 0.2, 0.0);
        glutSolidCube(1);///left hand
        glPopMatrix();

        glPushMatrix();
        glScalef(0.3, 0.40, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(0.60, -0.9, 0.0);
        glutSolidCube(1);///right leg
        glPopMatrix();

        glPushMatrix();
        glScalef(0.3, 0.40, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(-0.60, -0.9, 0.0);
        glutSolidCube(1);///left leg
        glPopMatrix();

        glPushMatrix();
        glScalef(0.2, 0.60, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(-0.91, -1.4, 0.0);
        glutSolidCube(1);///left under leg
        glPopMatrix();

        glPushMatrix();
        glScalef(0.2, 0.60, 0.5);
        glColor3f(0.921, 0, 0.050);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(0.91, -1.4, 0.0);
        glutSolidCube(1);///right under leg
        glPopMatrix();


        glPushMatrix();
        glScalef(0.2, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(0.91, -35.4, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.2, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(-0.91, -35.4, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.304, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(-0.6, -18.4, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.304, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(0.60, -18.4, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.7, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(0.0, -6.10, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.32, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(1.590, 13.10, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.32, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(-1.590, 13.10, 0.0);
        glutSolidCube(1);

        glPopMatrix();

        glPushMatrix();
        glScalef(0.47, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(-0.93, 26.50, 0.0);
        glutSolidCube(1);

        glPopMatrix();

        glPushMatrix();
        glScalef(0.47, 0.03, 0.5);
        glColor3f(0.243, 0.219, 0.219);
        //glColor3f(0.7,0.4,0.8);
        glTranslatef(0.93, 26.50, 0.0);
        glutSolidCube(1);

        glPopMatrix();
        glTranslatef(1.0, 0.50, 0.0);
        glPopMatrix();
        ///back logo
            ///drawing logo
        glPushMatrix();
        glScalef(0.12, 0.11, 0.02);
        glTranslatef(-7.502, -3.68, 0.0);
        glColor3f(0.941, 0.870, 0.019);

        glBegin(GL_LINE_STRIP);

        //glColor3f(0.0, 0.666, 0.031);
        glVertex3f(0.0, 0.29, 0);///I
        glVertex3f(0.2, 0.29, 0);///I
        glVertex3f(0.09, 0.0, 0);///I
        glVertex3f(0.16, 0.0, 0);///I
        glVertex3f(0.06, -0.24, 0);///I
        glVertex3f(0.13, -0.24, 0);///I
        glVertex3f(0.0, -0.54, 0);///I
        glEnd();
        glBegin(GL_LINE_STRIP);
        //glColor3f(0.0, 0.666, 0.031);
        glVertex3f(-0.0, 0.29, 0);///I
        glVertex3f(-0.2, 0.29, 0);///I
        glVertex3f(-0.09, 0.0, 0);///I
        glVertex3f(-0.16, 0.0, 0);///I
        glVertex3f(-0.06, -0.24, 0);///I
        glVertex3f(-0.13, -0.24, 0);///I
        glVertex3f(-0.0, -0.54, 0);///I
        glEnd();


        glScalef(0.52, 0.91, 0.02);
        glBegin(GL_POLYGON);

        //glColor3f(0.0, 0.666, 0.031);
        glVertex3f(0.0, 0.29, 0);///I
        glVertex3f(0.2, 0.29, 0);///I
        glVertex3f(0.09, 0.0, 0);///I
        glVertex3f(0.16, 0.0, 0);///I
        glVertex3f(0.06, -0.26, 0);///I
        glVertex3f(0.11, -0.26, 0);///I
        glVertex3f(0.0, -0.58, 0);///I
        glEnd();
        glBegin(GL_POLYGON);
        //glColor3f(0.0, 0.666, 0.031);
        glVertex3f(-0.0, 0.29, 0);///I
        glVertex3f(-0.2, 0.29, 0);///I
        glVertex3f(-0.09, 0.0, 0);///I
        glVertex3f(-0.16, 0.0, 0);///I
        glVertex3f(-0.06, -0.26, 0);///I
        glVertex3f(-0.11, -0.26, 0);///I
        glVertex3f(-0.0, -0.58, 0);///I
        glEnd();
        ///_logo
        ///till this back logo
        glPopMatrix();
    }
    void drawHead()
    {


            float x,y;
            float oldx=0.0;
            float oldy=0.0;
            float t=0;
        glPushMatrix();
        glTranslatef(-0.283, 0.5, 0.0);
        glScalef(0.26, 1.60, 0.02);
        glColor3f(0.615, 0.027, 0.027);
                x=drawCurve(0,0,0.6,0.6,t);
                y=drawCurve(0,20.6,0.26,0,t);
                glBegin(GL_POLYGON);
                glVertex2f(oldx, oldy);
                glVertex2f(x, y);
                t=t+0.01;
            while(t<=1)
            {
                x=drawCurve(0,-0.2,0.8,0.6,t);
                y=drawCurve(0,0.2,0.2,0,t);

                glVertex2f(x, y);


                t=t+0.01;
            }

                glEnd();

        glPopMatrix();
        glPopMatrix();

    }


};



#endif // FLASH_H_INCLUDED
