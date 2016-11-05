#ifndef _CUBE_H_
#define _CUBE_H_

#include <SFML\OpenGL.hpp>

class Cube
{
public:
  Cube(GLuint textureID);

  float _verticalAngle;

  void Update(float dt, bool keyheld, int rotation);
  void Draw(GLenum mode, bool isPurple);

private:
  float _horizontalAngle;
  GLuint _textureID;

  float _textureOffset;
};

#endif //_CUBE_H_