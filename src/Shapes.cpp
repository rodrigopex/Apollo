/*
 * shape2d.c
 *
 *  Created on: Nov 26, 2013
 *      Author: rodrigopex
 */
/*
 * shapes2d.c
 *
 *  Created on: 23/11/2013
 *      Author: Thiago Peixoto
 */

#include "Shapes.hpp"

namespace apollo {

	void drawPoint()
	{

	}

	void drawLine()
	{
		GLfloat vertices[] = {0.0f, 0.0f, 200.0f, 200.0f};
		glEnableClientState(GL_VERTEX_ARRAY);
		glPointSize(10.0);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_LINES, 0 , 2);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	void drawTriangle()
	{
		GLfloat vertices[] = {0.0f, 200.0f, -200.0f, -200.0f, 200.0f, -200.0f};
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_TRIANGLES, 0 , 3);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	void drawRectangle()
	{
		GLfloat vertices[] = {200.0f, 200.0f,
			-200.0f, -200.0f,
			200.0f, -200.0f,
			-200.0f, 200.0f,
			-200.0f, -200.0f,
			200.0f, 200.0f};
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_TRIANGLES, 0 , 6);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	static inline GLfloat degreesToRadians(GLfloat degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

	void drawCircle()
	{
		int i;
		GLfloat vertices[720];
		for (i = 0; i < 720; i+=2) {
			vertices[i] = cos(degreesToRadians(i)) * 200;
			vertices[i+1] = sin(degreesToRadians(i)) * 200;
		}
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glPushMatrix();
		//glScalef(0.7f, 0.7f, 1.0f);
		glDrawArrays(GL_TRIANGLE_FAN, 0 , 360);
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}
