#ifndef STAGE4_H_INCLUDED
#define STAGE4_H_INCLUDED

class Stage4{

private:
    float door = -0.3f;
    int doorline = 17;

public:
    void draw_circle(float x, float y, float radius) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2f(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
    }
    void draw_sky()
    {
       glBegin(GL_QUADS);
       glColor3f(0.0f , 0.0f , 0.05f);
       glVertex2f(-1.0f , -0.3f);
       glVertex2f(-1.0f , 1.0f);
       glVertex2f(1.0f , 1.0f);
       glVertex2f(1.0f , -0.3f);
       glEnd();
    }
    void draw_road()
    {
       glBegin(GL_QUADS);
       glColor3f(0.66f , 0.66f , 0.66f);
       glVertex2f(-1.0f , -1.0f);
       glVertex2f(-1.0f , -0.3f);
       glVertex2f(1.0f , -0.3f);
       glVertex2f(1.0f , -1.0f);
       glEnd();

       glBegin(GL_QUADS);
       glColor3f(1.0f , 1.0f , 1.0f);
       for(double i = 0.0 , x = 0.75f , y = 0.5f; i < 3.0; i++,x-=0.6f)
       {
          glVertex2f(-x , -y);
          glVertex2f(-x , -y+0.1f);
          glVertex2f(-x+0.3f , -y+0.1f);
          glVertex2f(-x+0.3f , -y);

          glVertex2f(-x , -y-0.3f);
          glVertex2f(-x , -y-0.2f);
          glVertex2f(-x+0.3f , -y-0.2f);
          glVertex2f(-x+0.3f , -y-0.3f);
       }
       glEnd();
    }
    void draw_fence()
    {
        glPointSize(3.0f);

        /* Left Side Fence */

       glBegin(GL_QUADS); //Left Horizontal Bar
       glColor3f(1.0f , 0.6f , 0.2f);
       glVertex2f(-0.99f , -0.1f);
       glVertex2f(-0.99f , 0.0f);
       glVertex2f(-0.3f , 0.0f);
       glVertex2f(-0.3f , -0.1f);
       glEnd();

       for(double i = 0.0 ,x = 0.98f ,y = 0.3f; i <10.0; i++ , x-=0.07f)
       {
          glBegin(GL_QUADS); //Vertical Bar
          glColor3f(1.0f , 0.6f , 0.2f);
          glVertex2f(-x , -y);
          glVertex2f(-x , y - 0.3f);
          glVertex2f(-x+0.04f , y - 0.3f);
          glVertex2f(-x+0.04f , -y);
          glEnd();

          glBegin(GL_TRIANGLES); //Top of each bars
          glColor3f(1.0f , 0.6f , 0.2f);
          glVertex2f(-x , y - 0.3f);
          glVertex2f((-x+(-x+0.04f))/2.0f , 0.1f);
          glVertex2f(-x+0.04f , y - 0.3f);
          glEnd();

          glBegin(GL_POINTS); //Screws
          glColor3f(0.0f , 0.0f , 0.0f);
          glVertex2f(-x+0.01f , y - 0.3f-0.02f);
          glVertex2f(-x-0.01f+0.04f , y - 0.3f-0.02f);
          glVertex2f(-x+0.01f , y - 0.3f-0.08f);
          glVertex2f(-x-0.01f+0.04f , y - 0.3f-0.08f);
          glEnd();

       }


       /* Right Side Fence */

       glBegin(GL_QUADS); //Right Horizontal Bar
       glColor3f(1.0f , 0.6f , 0.2f);
       glVertex2f(1.0f , -0.1f);
       glVertex2f(1.0f , 0.0f);
       glVertex2f(0.3f , 0.0f);
       glVertex2f(0.3f , -0.1f);
       glEnd();

       for(double i = 0.0 ,x = 0.95f ,y = 0.3f; i <10.0; i++ , x-=0.07f)
       {
          glBegin(GL_QUADS);
          glColor3f(1.0f , 0.6f , 0.2f);
          glVertex2f(x , -y);
          glVertex2f(x , y - 0.3f);
          glVertex2f(x+0.04f , y - 0.3f);
          glVertex2f(x+0.04f , -y);
          glEnd();

          glBegin(GL_TRIANGLES);
          glColor3f(1.0f , 0.6f , 0.2f);
          glVertex2f(x , y - 0.3f);
          glVertex2f((x+(x+0.04f))/2.0f , 0.1f);
          glVertex2f(x+0.04f , y - 0.3f);
          glEnd();

          glBegin(GL_POINTS); //Screws
          glColor3f(0.0f , 0.0f , 0.0f);
          glVertex2f(x + 0.01f , y - 0.3f - 0.02f);
          glVertex2f(x -0.01f + 0.04f , y - 0.3f - 0.02f);
          glVertex2f(x + 0.01f , y - 0.3f - 0.08f);
          glVertex2f(x - 0.01f + 0.04f , y - 0.3f - 0.08f);
          glEnd();

       }
    }

    void draw_building()
    {
        /* Cement */
        glBegin(GL_QUADS);
        glColor3f(0.6f , 0.29f , 0.0f);
        glVertex2f(-0.3f , -0.3f);
        glVertex2f(-0.3f , 1.0f);
        glVertex2f(0.3f ,  1.0f);
        glVertex2f(0.3f , -0.3f);
        glEnd();

        /* Bricks */
        glBegin(GL_QUADS);
        glColor3f(0.6f , 0.29f , 0.0f);
        for(double i = 0.0 , y = 0.9f; i < 10.0; i+=0.84,y-=0.108f)
        {
            double x = 0.294f;
            for(int j = 0; j < 7; j++,x-=0.084f)
            {
              glVertex2f(-x , y);
              glVertex2f(-x , y+0.1f);
              glVertex2f(-x+0.08f , y+0.1f);
              glVertex2f(-x+0.08f , y);
            }
        }
        glEnd();

        /* Roof */
        glBegin(GL_QUADS);
        glColor3f(1.0f , 1.0f , 0.4f);
        glVertex2f(-0.35f , 0.9f);
        glVertex2f(-0.35f , 1.0f);
        glVertex2f(0.35f , 1.0f);
        glVertex2f(0.35f , 0.9f);
        glEnd();

        /* Windows */

        for(double i = 0.0 , x = 0.21f ,  y = 0.57f; i < 2.0; i++ , y-=0.33f)
        {
            glBegin(GL_QUADS);
            glColor3f(0.0f , 0.0f , 0.0f);
            glVertex2f(-x , y);
            glVertex2f(-x , y+0.21f);
            glVertex2f(x-0.255f , y+0.21f);
            glVertex2f(x-0.255f , y);

            glVertex2f(x -0.17f , y);
            glVertex2f(x-0.17f , y+0.21f);
            glVertex2f(x-0.004f , y+0.21f);
            glVertex2f(x-0.004f , y);
            glEnd();

            glLineWidth(8.0f);
            glBegin(GL_LINES);
            glColor3f(1.0f , 1.0f , 0.0f);
            glVertex2f(-x-0.01f , y+0.21f);
            glVertex2f(x-0.255f+0.01f , y+0.21f);

            glVertex2f(x-0.17f -0.01f, y+0.21f);
            glVertex2f(x-0.004f+0.01f , y+0.21f);
            glEnd();
        }

        /* Garage */
        glBegin(GL_QUADS);
        glColor3f(0.0f , 0.0f , 0.0f);
        glVertex2f(-0.21f , -0.3f);
        glVertex2f(-0.21f , 0.14f);
        glVertex2f(0.204f , 0.14f);
        glVertex2f(0.204f , -0.3f);

        glColor3f(0.97f , 0.97f , 1.0f);
        glVertex2f(-0.2f , door);
        glVertex2f(-0.2f , 0.12f);
        glVertex2f(0.198f , 0.12f);
        glVertex2f(0.198f , door);
        glEnd();

        glLineWidth(1.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f , 0.0f , 0.0f);
        for(double i = 0 , y = 0.1f; i < doorline; i++ , y-=0.02f)
        {
            glVertex2f(-0.2f , y);
            glVertex2f(0.198f , y);
        }
        glEnd();
        glLineWidth(8.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.1f , -0.25f);
        glVertex2f(0.1f, -0.25f);
        glEnd();
    }

    void draw_plant()
    {
        double x = -0.95f;
        for(int i = 0; i < 7; i++ , x+= 0.3f)
        {
            glBegin(GL_QUADS);
            glColor3f(0.55f , 0.27f , 0.07f);
            glVertex2f(x+0.08f , -0.3f);
            glVertex2f(x+0.08f , 0.2f);
            glVertex2f(x+0.12f , 0.2f);
            glVertex2f(x+0.12f , -0.3f);
            glEnd();

            glBegin(GL_TRIANGLES);
            glColor3f(0.13f , 0.55f , 0.13f);
            glVertex2f(x , -0.2f);
            glVertex2f(x+0.1f ,  0.2f);
            glVertex2f(x+0.2f , -0.2f);

            glVertex2f(x , 0.0f);
            glVertex2f(x+0.1f , 0.4f);
            glVertex2f(x+0.2f , 0.0f);
            glEnd();

        }



    }
    void door_open()
    {
        door+= 0.1f;
        doorline -= 2;
    }


};


#endif // STAGE1_H_INCLUDED
