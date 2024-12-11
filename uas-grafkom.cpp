#include <glut.h>

const int width = 640;
const int height = 480;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // start code here

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ini Judul Window");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}