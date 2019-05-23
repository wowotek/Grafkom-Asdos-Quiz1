#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

#define POINTS glBegin(GL_POINTS)
#define POLYGON glBegin(GL_POLYGON)
#define LINES glBegin(GL_LINES)

void myInit(void);
void myDisplay(void);

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Quiz - 1");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

	return 0;
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //TANAH
    glColor3f(0.7, 0.5, 0);
    POLYGON;
        glVertex2f(0, 0);
        glVertex2f(0, 45);
        glVertex2f(100, 45);
        glVertex2f(100, 0);
    glEnd();

    for(float i=0; i<55; i+= 0.01){
        glColor3f(0.1+(i/50), 0.5+(i/100), 1.0-(i/50));
        LINES;
            glVertex2f(100, 100-i);
            glVertex2f(0, 100-i);
        glEnd();
    }
    // POHON
    glColor3f(0.3, 1.0, 0.0);
    for(int i=0; i<=30; i+= 10){
        POLYGON;
            glVertex2f(2.5, 20+(i/2));
            glVertex2f(27.5, 20+(i/2));
            glVertex2i(15, 30+i);
        glEnd();
    }
    for(float i=0; i<40; i+= 0.001){
        glColor3f(1.0-(i/50), 0.5+(i/75), 0.04);
        LINES;
            glVertex2f(10.0+(i-(i/1.1)), 10.0+i);
            glVertex2f(20.0-(i-(i/1.1)), 10.0+i);
        glEnd();
    }
    //--------------------------------------
    // RUMAH
    glColor3f(0.6, 0.3, 0.15);
    POLYGON;
        glVertex2i(35, 20);
        glVertex2i(70, 20);
        glVertex2i(70, 40);
        glVertex2i(35, 40);
    glEnd();
    glColor3f(0.8, 0.45, 0.1);
    POLYGON;
        glVertex2i(35, 40);
        glVertex2i(70, 40);
        glVertex2i(52.5, 60);
    glEnd();
    glColor3f(0.7, 0.4, 0.15);
    POLYGON;
        glVertex2i(75, 70);
        glVertex2i(92.5, 50);
        glVertex2i(70, 40);
        glVertex2i(52.5, 60);
    glEnd();
    glColor3f(0.6, 0.35, 0.2);
    POLYGON;
        glVertex2i(70, 20);
        glVertex2i(92.5, 30);
        glVertex2i(92.5, 50);
        glVertex2i(70, 40);
    glEnd();
    glColor3f(0.8, 0.45, 0.1);
    POLYGON;
        glVertex2i(55, 20);
        glVertex2i(65, 20);
        glVertex2i(65, 35);
        glVertex2i(55, 35);
    glEnd();
    // ----------
    // PAGER
    for(float j=0; j<90; j+=5){
        glColor3f(1.0, 0.8, 0.0);
        POLYGON;
            glVertex2f(4.75+j, 5);
            glVertex2f(5+j, 13);
            glVertex2f(6+j, 16);
            glVertex2f(7+j, 13);
            glVertex2f(7.25+j, 5);
        glEnd();
    }
    for(float j=0; j<87.5; j+=2.5){
        for(float i=0; i<1; i+= 0.001){
            glColor3f(0.8+(i/5), 0.4, 0.0);
            LINES;
                glVertex2f(4+j, 6.5+i);
                glVertex2f(8+j, 6.5+i);
            glEnd();
        }

        for(float i=0; i<0.8; i+= 0.001){
            glColor3f(0.8+(i/3), 0.4, 0.0);
            LINES;
                glVertex2f(4+j, 10.5+i);
                glVertex2f(8+j, 10.5+i);
            glEnd();
        }
    }
    // ----------

    glFlush();
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}
	
