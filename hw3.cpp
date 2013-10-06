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

void drawPoints()
{
		// Following section draws a polygon pattern as background wall paper
		glEnable(GL_POLYGON_STIPPLE);				//Enables polygon stipple
		glPolygonStipple(WallPaperPattern);			//Loads custom pattern
		glBegin(GL_POLYGON);
			glColor3f(0.5, .6, 0);						//Creates polygon from vertices
			glVertex2i(-200, 200);						//and changes color for each point.
			glColor3f(0.5, 0.5, .1);	
			glVertex2i(-200, -200);
			glColor3f(0.5, .6, 0);	
			glVertex2i(200, -200);
			glColor3f(0.5, 0.5, .1);	
			glVertex2i(200, 200);
		glEnd();
		glDisable(GL_POLYGON_STIPPLE);

		// Following draws shadow beneath desk
		glPolygonMode(GL_CCW, GL_FILL);				//Changes mode to fill
		glEnable(GL_BLEND);							//Enables alpha blending
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
			glColor4f(0, 0, 0, .75);
			glVertex2i(-200, -175);
			glVertex2i(200, -175);
			glVertex2i(200, -200);
			glVertex2i(-200, -200);
		glEnd();
		glDisable(GL_BLEND);						//Disables Alpha blending

		// Following section draws a rectangle for the desk surface

		glBegin(GL_POLYGON);							//Creates polygon from vertices
			glColor3f(.5, .3, .1);						//and changes color for each point.
			glVertex2i(-200, -50);
			glVertex2i(200, -50);
			glVertex2i(200, -150);
			glVertex2i(-200, -150);
		glEnd();

		// Following draws dark area of desk front
		glBegin(GL_POLYGON);
			glColor3f(.4, .2, .05);
			glVertex2i(-200, -150);
			glVertex2i(200, -150);
			glVertex2i(200, -175);
			glVertex2i(-200, -175);
		glEnd();

		// Following draws line on desk for psuedo-perspective
		int CurrentLineStartX = 375;
		int TotalSurfaceLines = 12;
		glLineWidth(4);
		for (int i = 0; i < TotalSurfaceLines; i++){
			glBegin(GL_LINES);
				glColor3f(.45, .25, 0.08);
				glVertex2i(CurrentLineStartX, -50);
				glVertex2i(CurrentLineStartX - 200, -150);
			glEnd();
			CurrentLineStartX -= 50;
		}

		glBegin(GL_LINES);
			glVertex2i(-200, -50);
			glVertex2i(200, -50);
		glEnd();
		glBegin(GL_LINES);
			glVertex2i(-200, -150);
			glVertex2i(200, -150);
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
}

//***********************************************************************************
void myInit()
{
	glClearColor(0, .3, .4, 0);			// specify a background clor: blueish-green
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
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