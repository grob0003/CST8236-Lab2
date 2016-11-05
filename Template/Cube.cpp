#include "Cube.h"

Cube::Cube(GLuint textureID) : _horizontalAngle(0), _verticalAngle(0), _textureID(textureID)
{
	_textureOffset = 0.0f;
}

void Cube::Update(float dt, bool keyheld, int rotation)
{
	float angle = 0.0f;
	angle += 90.f *dt;
	_horizontalAngle += 90.0f * dt;
	_textureOffset += 0.5f * dt;

	GLfloat position[] = { 0.5f, 0.2f, 0.3f, 0.2f };
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	if (_textureOffset > 1.0f) {
		_textureOffset -= 1.0f;
	}
	if (keyheld){
		if (rotation == 1){
			glRotatef(-angle, 1.0f, 0.0f, 0.0f);

		}
		else if (rotation == -1){
			glRotatef(angle, 1.0f, 0.0f, 0.0f);
		}
	}
	else
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
}

void Cube::Draw(GLenum mode, bool isPurple)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float offset = 0.25f;

		float leftS = 0.3f;
		float rightS = 0.7f;
		float topT = 0.25f;
		float bottomT = 0.75f;

	//glBindTexture(GL_TEXTURE_2D, _textureID);
	GLenum error = glGetError();

	glPushMatrix();
	error = glGetError();
	

		// Begin our drawing block.
		glBegin(mode);

			// Front
			glColor3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(leftS, bottomT);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-offset, -offset, offset);

			glTexCoord2f(leftS, topT);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-offset, offset, offset);

			glTexCoord2f(rightS, topT);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(offset, offset, offset);

			glTexCoord2f(rightS, bottomT);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(offset, -offset, offset);

			// Right
			glColor3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(leftS, bottomT);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(offset, -offset, offset);

			glTexCoord2f(leftS, topT);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(offset, offset, offset);

			glTexCoord2f(rightS, topT);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(offset, offset, -offset);

			glTexCoord2f(rightS, bottomT);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(offset, -offset, -offset);

			// Left
			glColor3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(leftS, bottomT);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-offset, -offset, -offset);

			glTexCoord2f(leftS, topT);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-offset, offset, -offset);

			glTexCoord2f(rightS, topT);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-offset, offset, offset);

			glTexCoord2f(rightS, bottomT);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-offset, -offset, offset);

			// Back
			glColor3f(0.0f, 1.0f, 1.0f);
			glTexCoord2f(leftS, bottomT);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(offset, -offset, -offset);

			glTexCoord2f(leftS, topT);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(offset, offset, -offset);

			glTexCoord2f(rightS, topT);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(-offset, offset, -offset);

			glTexCoord2f(rightS, bottomT);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(-offset, -offset, -offset);

			// Top
			glColor3f(1.0f, 0.0f, 1.0f);
			glTexCoord2f(leftS, bottomT);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-offset, offset, offset);

			glTexCoord2f(leftS, topT);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-offset, offset, -offset);

			glTexCoord2f(rightS, topT);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(offset, offset, -offset);

			glTexCoord2f(rightS, bottomT);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(offset, offset, offset);

			// Bottom
			glColor3f(1.0f, 1.0f, 1.0f);
			glTexCoord2f(leftS, bottomT);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(-offset, -offset, -offset);

			glTexCoord2f(leftS, topT);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(-offset, -offset, offset);

			glTexCoord2f(rightS, topT);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(offset, -offset, offset);

			glTexCoord2f(rightS, bottomT);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(offset, -offset, -offset);

		// End our drawing block.
		glEnd();
	
	glPopMatrix();
}