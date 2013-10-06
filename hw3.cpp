/*===================================================================================
 PROGRAMMER:			Brett Story
 COURSE:				CSC 525/625
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	Oct. 5, 2013
 DESCRIPTION:			Demo: drawing points.
 NOTE:					N/A
 FILES:					h3.cpp, (hwProject.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on labProject.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
===================================================================================*/
#define _USE_MATH_DEFINES
#include <GL/glut.h>				// include GLUT library
#include <cmath>					// include math library

//***********************************************************************************

GLubyte WallPaperPattern[128] = {0X00, 0X00, 0X00, 0X00,
								0X00, 0X00, 0X00, 0X00,
								0X00, 0X00, 0X00, 0X00,
								0X00, 0X00, 0X00, 0X00,

								0X00, 0X0F, 0XF0, 0X00,
								0X00, 0X0F, 0XF0, 0X00,
								0X00, 0X0F, 0XF0, 0X00,
								0X00, 0X0F, 0XF0, 0X00,

								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,

								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,

								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,

								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,
								0X00, 0XFF, 0XFF, 0X00,

								0X00, 0X0F, 0XF0, 0X00,
								0X00, 0X0F, 0XF0, 0X00,
								0X00, 0X0F, 0XF0, 0X00,
								0X00, 0X0F, 0XF0, 0X00,

								0X00, 0X00, 0X00, 0X00,
								0X00, 0X00, 0X00, 0X00,
								0X00, 0X00, 0X00, 0X00,
								0X00, 0X00, 0X00, 0X00};

static unsigned char image_bits[256] = {
   0xac, 0x10, 0x40, 0x00, 0xe8, 0xa8, 0x40, 0x00, 0xf8, 0x5a, 0x41, 0x00,
   0xe8, 0xff, 0x01, 0x80, 0xf0, 0xdf, 0x22, 0xc0, 0xf0, 0xff, 0x43, 0xd8,
   0xe0, 0xbf, 0x2d, 0xa4, 0xe0, 0xff, 0xf5, 0xe8, 0xe0, 0x3f, 0xfd, 0xd6,
   0xc0, 0xbf, 0xfa, 0xca, 0xc0, 0x7f, 0xfc, 0xab, 0x80, 0x5f, 0xfd, 0x8b,
   0x00, 0x3f, 0xfe, 0xa7, 0x80, 0x2e, 0xfe, 0x85, 0x00, 0x51, 0x7e, 0x85,
   0x06, 0x12, 0xbe, 0x04, 0x0c, 0x20, 0x3e, 0x00, 0x06, 0x00, 0x7e, 0x00,
   0x0f, 0x10, 0x3e, 0x00, 0x0e, 0x10, 0x7e, 0x00, 0x0f, 0x00, 0x3e, 0x00,
   0x0a, 0x00, 0x3e, 0x00, 0x0d, 0x00, 0x3e, 0x00, 0x09, 0x00, 0x14, 0x00,
   0x04, 0x00, 0x02, 0x00, 0x09, 0x00, 0x06, 0x00, 0x08, 0x00, 0x00, 0x00,
   0x09, 0x00, 0x03, 0x00, 0x12, 0x00, 0x02, 0x02, 0x3a, 0x00, 0x02, 0x00,
   0x34, 0x00, 0x02, 0x01, 0x7a, 0x00, 0x00, 0x02, 0x7c, 0x00, 0x00, 0x00,
   0x7c, 0x00, 0x00, 0x02, 0xfc, 0x00, 0x00, 0x08, 0x7c, 0x01, 0x00, 0x00,
   0xfc, 0x02, 0x00, 0x02, 0xfe, 0x03, 0x00, 0x04, 0xfe, 0x06, 0x00, 0xea,
   0xfe, 0x03, 0x00, 0x86, 0xff, 0x07, 0x80, 0x73, 0x7d, 0x03, 0x80, 0x46,
   0xe3, 0x07, 0xe0, 0x03, 0x07, 0x03, 0x50, 0x03, 0x81, 0x06, 0xf0, 0x01,
   0x07, 0x02, 0xf8, 0x01, 0x00, 0x02, 0xec, 0x00, 0x00, 0x00, 0xfc, 0x00,
   0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7e, 0x00,
   0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3f, 0x00,
   0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x00, 0x00, 0x09, 0x00, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x02, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x14, 0x00,
   0x00, 0x00, 0x7c, 0x00 };

void drawPoints()
{
		// Following section draws a polygon pattern as background wall paper
		glEnable(GL_POLYGON_STIPPLE);				//Enables polygon stipple
		glPolygonStipple(WallPaperPattern);			//Loads custom pattern
		glBegin(GL_POLYGON);
			glColor3f(0.5, .6, 0);						//Creates polygon from vertices
			glVertex2i(-300, 300);						//and changes color for each point.
			glColor3f(0.5, 0.5, .1);	
			glVertex2i(-300, -300);
			glColor3f(0.5, .6, 0);	
			glVertex2i(300, -300);
			glColor3f(0.5, 0.5, .1);	
			glVertex2i(300, 300);
		glEnd();
		glDisable(GL_POLYGON_STIPPLE);

		// Following draws shadow beneath desk
		glPolygonMode(GL_CCW, GL_FILL);				//Changes mode to fill
		glEnable(GL_BLEND);							//Enables alpha blending
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
			glColor4f(0, 0, 0, .75);
			glVertex2i(-300, -175);
			glVertex2i(300, -175);
			glVertex2i(300, -300);
			glVertex2i(-300, -300);
		glEnd();
		glDisable(GL_BLEND);						//Disables Alpha blending

		// Following section draws a rectangle for the desk surface

		glBegin(GL_POLYGON);							//Creates polygon from vertices
			glColor3f(.5, .3, .1);						//and changes color for each point.
			glVertex2i(-300, -50);
			glVertex2i(300, -50);
			glVertex2i(300, -150);
			glVertex2i(-300, -150);
		glEnd();

		// Following draws dark area of desk front
		glBegin(GL_POLYGON);
			glColor3f(.4, .2, .05);
			glVertex2i(-300, -150);
			glVertex2i(300, -150);
			glVertex2i(300, -175);
			glVertex2i(-300, -175);
		glEnd();

		// Following draws line on desk for psuedo-perspective
		int CurrentLineStartX = 600;
		int TotalSurfaceLines = 12;
		glLineWidth(4);
		for (int i = 0; i < TotalSurfaceLines; i++){
			glBegin(GL_LINES);
				glColor3f(.45, .25, 0.08);
				glVertex2i(CurrentLineStartX, -50);
				glVertex2i(CurrentLineStartX - 400, -150);
			glEnd();
			CurrentLineStartX -= 100;
		}

		glBegin(GL_LINES);
			glVertex2i(-300, -50);
			glVertex2i(300, -50);
		glEnd();
		glBegin(GL_LINES);
			glVertex2i(-300, -150);
			glVertex2i(300, -150);
		glEnd();

		//Following draws computer monitor w/o screen
		glBegin(GL_POLYGON);
			glColor3f(0.6, 0.6, 0.5);
			glVertex2i(150, -100);
			glVertex2i(150, 100);
			glVertex2i(200, 100);
			glVertex2i(200, -75);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(0.8, 0.8, 0.7);
			glVertex2i(-50, -100);
			glVertex2i(150, -100);
			glVertex2i(150, 100);
			glVertex2i(-50, 100);
		glEnd();

		//Following draws buttons onto the computer monitor bezel
		float radius = 1;
		float x_offset = 130;
		float y_offset = -62;
		glBegin(GL_POINTS);
		glColor3f(0.85, 0.55, 0.55);
		for (int x=0; x<360; x++){
			float radians = x*(M_PI/180);
			glVertex2f(cos(radians)*radius+x_offset, sin(radians)*radius+y_offset);
		}
		glEnd();


		radius = 4.5;
		x_offset = -31;
		y_offset = -62;
		glBegin(GL_POINTS);
		glColor3f(0.6, 0.6, 0.6);
		for (int x=0; x<360; x++){
			float radians = x*(M_PI/180);
			glVertex2f(cos(radians)*radius+x_offset, sin(radians)*radius+y_offset);
		}
		glEnd();

		radius = 4;
		x_offset = -32;
		y_offset = -62;
		glBegin(GL_POINTS);
		glColor3f(0.65, 0.65, 0.65);
		for (int x=0; x<360; x++){
			float radians = x*(M_PI/180);
			glVertex2f(cos(radians)*radius+x_offset, sin(radians)*radius+y_offset);
		}
		glEnd();



		//Following draws screen onto computer monitor (black)
		glBegin(GL_POLYGON);
			glColor3f(0, 0, 0);
			glVertex2i(-25, -50);
			glVertex2i(125, -50);
			glVertex2i(125, 75);
			glVertex2i(-25, 75);
		glEnd();

		//Adds detail lines to computer monitor
		glBegin(GL_LINES);
			glColor3f(0.6, 0.6, 0.5);
			glVertex2i(-50, -50);
			glVertex2i(150, -50);
		glEnd();

		glBegin(GL_LINES);
			glVertex2i(125, 75);
			glVertex2i(149, 99);
		glEnd();

		glBegin(GL_LINES);
			glVertex2i(-25, 75);
			glVertex2i(-49, 99);
		glEnd();

		// Draws a multicolor bitmap
		glRasterPos2i(-256, -256);
		glDrawPixels(32, 64, GL_COLOR_INDEX, GL_UNSIGNED_BYTE, image_bits);

}

//***********************************************************************************
void myInit()
{
	glClearColor(0, .3, .4, 0);			// specify a background clor: blueish-green
	gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawPoints();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void main(int argc, char ** argv)
{
	glutInit(& argc, argv);

	glutInitWindowSize(512, 512);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Simple Point Drawing");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}