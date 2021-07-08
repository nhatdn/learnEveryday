#include <iostream>
#include <glut.h>
// glBegin(GL_POLYGON); // Bat dau ve hinh = Tham so truyen vao la loai can ve
// GL_POINTS: ve 1 diem tuong ung vs 1 pixel
// GL_LINES: ve 1 duong thang
// GL_LINE_STRIP: noi cac diem lai vs nhau nhung k noi diem dau va diem cuoi
// GL_LINE_LOOP: noi cac diem lai vs nhau thanh 1 vong
// GL_TRIANGLES: ve 1 tam giac va to mau tam giac do
// GL_TRIANGLE_STRIP: tuong tu nhu GL_TRIANGLES
// GL_POLYGON: ve 1 da giac duoc to mau phan dien tich
// GL_QUADS: ve 1 hinh tu giac
// glClearColor(0, 0.5, 0.2, 0.7):  change background color 
// glColor3f(1.0, 0.34, 0.1): change shape color
// glClear(GL_COLOR_BUFFER_BIT); Kich hoat bo dem de ve mau.
// glFinish(); same same glFlush();
void display() {
	// hinh vuong
	glClearColor(74.0/255, 79.0/255, 85.0/255, 1);
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON);
	glColor3f(140.0 / 255, 250.0 / 255, 30.0 / 255);

	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.3, -0.5);
	glVertex2f(-0.3, 0);
	glVertex2f(-0.8, 0);
	glEnd();
	glFlush();
	// hinh tam giac
	glBegin(GL_POLYGON);
	glColor3f(255.0 / 255, 83.0 / 255 , 217.0 / 255);
	glVertex2f(-0.55, 0.18);
	glVertex2f(-0.2, 0);
	glVertex2f(-0.9, 0);

	glEnd();
	glFlush();
	// hinh binh hanh - mai nha phia truoc
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.34, 0.51);
	glVertex2f(-0.2, 0);
	glVertex2f(0.65, 0.15);
	glVertex2f(-0.55, 0.18);
	glVertex2f(0.2, 0.32);
	glVertex2f(0.2, 0.32);
	glVertex2f(0.65, 0.15);
	//glVertex2f(0.55, -0.35);
	//glVertex2f(0.55, 0.15);
	//glVertex2f(-0.3, -0.5);
	//glVertex2f(0.55, -0.35);
	glEnd();
	glFlush();
	
	// hinh binh hanh - mai nha phia truoc
	glBegin(GL_POLYGON);
	glColor3f(135.0 / 255, 25.0 / 255, 56.0 / 255);
	glVertex2f(0.55, -0.35);
	glVertex2f(-0.3, -0.5);
	glVertex2f(-0.3, -0.5);
	glVertex2f(-0.3, 0);
	glVertex2f(-0.3, 0);
	glVertex2f(-0.2, 0);
	glVertex2f(-0.2, 0);
	glVertex2f(0.55, 0.13);
	glVertex2f(0.55, 0.13);
	glVertex2f(0.55, -0.35);
	glEnd();
	glFlush();
}
int main() {
	glutCreateWindow("Title");
	glutDisplayFunc(display);
	glutMainLoop();
}