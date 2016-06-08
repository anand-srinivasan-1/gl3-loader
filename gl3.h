#ifndef GL3_H_LOADER
#define GL3_H_LOADER

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
//#include <GL/glext.h>

/*
#ifdef _WIN32
#include <GL/wglext.h>
#else
#include <GL/glxext.h>
#endif
*/

void LoadFunctions(void);

// GL_API
typedef void (* PFN_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (* PFN_glClear)(GLbitfield mask);

// GL_TEXTURE
typedef void (* PFN_glActiveTexture)(GLenum texture);
typedef void (* PFN_glGenTextures)(GLsizei n, GLuint* textures);
typedef void (* PFN_glBindTexture)(GLenum target, GLuint texture);
typedef void (* PFN_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data);
typedef void (* PFN_glTexParameteri)(GLenum target, GLenum pname, GLint param);
typedef void (* PFN_glGenerateMipmap)(GLenum target);

// GL_VBO
typedef void (* PFN_glGenBuffers)(GLsizei n, GLuint* buffers);
typedef void (* PFN_glBindBuffer)(GLenum target, GLuint buffer);
typedef void (* PFN_glBufferData)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (* PFN_glEnableVertexAttribArray)(GLuint index);
typedef void (* PFN_glDisableVertexAttribArray)(GLuint index);
typedef void (* PFN_glDrawArrays)(GLenum mode, GLsizei first, GLsizei count);
typedef void (* PFN_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

// GL_VAO
typedef void (* PFN_glGenVertexArrays)(GLsizei n, GLuint* arrays);
typedef void (* PFN_glBindVertexArray)(GLuint array);

// GL_GLSL
typedef void (* PFN_glDetachShader)(GLuint program, GLuint shader);
typedef void (* PFN_glDeleteShader)(GLuint shader);
typedef GLuint (* PFN_glCreateProgram)(void);
typedef GLuint (* PFN_glCreateShader)(GLenum shaderType);
typedef void (* PFN_glShaderSource)(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
typedef void (* PFN_glAttachShader)(GLuint program, GLuint shader);
typedef void (* PFN_glLinkProgram)(GLuint program);
typedef GLint (* PFN_glGetUniformLocation)(GLuint program, const GLchar* name);
typedef GLint (* PFN_glGetAttribLocation)(GLuint program, const GLchar* name);
typedef void (* PFN_glUniform1f)(GLint location, GLfloat v0);
typedef void (* PFN_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
typedef void (* PFN_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (* PFN_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (* PFN_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (* PFN_glBindAttribLocation)(GLuint location, GLuint index, const GLchar* name);
typedef void (* PFN_glUseProgram)(GLuint program);
typedef void (* PFN_glCompileShader)(GLuint shader);
typedef void (* PFN_glGetShaderiv)(GLuint shader, GLenum pname, GLint* params);
typedef void (* PFN_glGetProgramiv)(GLuint program, GLenum pname, GLint* params);
typedef void (* PFN_glGetShaderInfoLog)(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
typedef void (* PFN_glGetProgramInfoLog)(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
typedef void (* PFN_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);

// GL_FBO
typedef void (* PFN_glGenFramebuffers)(GLsizei n, GLuint* ids);
typedef void (* PFN_glBindFramebuffer)(GLenum target, GLuint framebuffer);

// WGL

#ifdef _WIN32
typedef HGLRC (* PFN_wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int* attribList);
#endif

//====================================================

// GL_API
extern PFN_glClearColor _glClearColor;
extern PFN_glClear _glClear;

// GL_TEXTURE
extern PFN_glActiveTexture _glActiveTexture;
extern PFN_glGenTextures _glGenTextures;
extern PFN_glBindTexture _glBindTexture;
extern PFN_glTexImage2D _glTexImage2D;
extern PFN_glTexParameteri _glTexParameteri;
extern PFN_glGenerateMipmap _glGenerateMipmap;

// GL_VBO
extern PFN_glGenBuffers _glGenBuffers;
extern PFN_glBindBuffer _glBindBuffer;
extern PFN_glBufferData _glBufferData;
extern PFN_glEnableVertexAttribArray _glEnableVertexAttribArray;
extern PFN_glDisableVertexAttribArray _glDisableVertexAttribArray;
extern PFN_glDrawArrays _glDrawArrays;
extern PFN_glVertexAttribPointer _glVertexAttribPointer;

// GL_VAO
extern PFN_glGenVertexArrays _glGenVertexArrays;
extern PFN_glBindVertexArray _glBindVertexArray;

// GL_GLSL
extern PFN_glDetachShader _glDetachShader;
extern PFN_glDeleteShader _glDeleteShader;
extern PFN_glCreateProgram _glCreateProgram;
extern PFN_glCreateShader _glCreateShader;
extern PFN_glShaderSource _glShaderSource;
extern PFN_glAttachShader _glAttachShader;
extern PFN_glLinkProgram _glLinkProgram;
extern PFN_glGetUniformLocation _glGetUniformLocation;
extern PFN_glGetAttribLocation _glGetAttribLocation;
extern PFN_glUniform1f _glUniform1f;
extern PFN_glUniform2f _glUniform2f;
extern PFN_glUniform3f _glUniform3f;
extern PFN_glUniform4f _glUniform4f;
extern PFN_glUniformMatrix4fv _glUniformMatrix4fv;
extern PFN_glBindAttribLocation _glBindAttribLocation;
extern PFN_glUseProgram _glUseProgram;
extern PFN_glCompileShader _glCompileShader;
extern PFN_glGetShaderiv _glGetShaderiv;
extern PFN_glGetProgramiv _glGetProgramiv;
extern PFN_glGetShaderInfoLog _glGetShaderInfoLog;
extern PFN_glGetProgramInfoLog _glGetProgramInfoLog;
extern PFN_glDispatchCompute _glDispatchCompute;

// GL_FBO
extern PFN_glGenFramebuffers _glGenFramebuffers;
extern PFN_glBindFramebuffer _glBindFramebuffer;

// WGL
#ifdef _WIN32
extern PFN_wglCreateContextAttribsARB _wglCreateContextAttribsARB;
#endif

//====================================================

// gl-prefixed functions in libGL; do redirecting to _gl functions before linker

// GL_API
#define glClearColor _glClearColor
#define glClear _glClear

// GL_TEXTURE
#define glActiveTexture _glActiveTexture
#define glGenTextures _glGenTextures
#define glBindTexture _glBindTexture
#define glTexImage2D _glTexImage2D
#define glTexParameteri _glTexParameteri
#define glGenerateMipmap _glGenerateMipmap

// GL_VBO
#define glGenBuffers _glGenBuffers
#define glBindBuffer _glBindBuffer
#define glBufferData _glBufferData
#define glEnableVertexAttribArray _glEnableVertexAttribArray
#define glDisableVertexAttribArray _glDisableVertexAttribArray
#define glDrawArrays _glDrawArrays
#define glVertexAttribPointer _glVertexAttribPointer

// GL_VAO
#define glGenVertexArrays _glGenVertexArrays
#define glBindVertexArray _glBindVertexArray

// GL_GLSL
#define glDetachShader _glDetachShader
#define glDeleteShader _glDeleteShader
#define glCreateProgram _glCreateProgram
#define glCreateShader _glCreateShader
#define glShaderSource _glShaderSource
#define glAttachShader _glAttachShader
#define glLinkProgram _glLinkProgram
#define glGetUniformLocation _glGetUniformLocation
#define glGetAttribLocation _glGetAttribLocation
#define glUniform1f _glUniform1f
#define glUniform2f _glUniform2f
#define glUniform3f _glUniform3f
#define glUniform4f _glUniform4f
#define glUniformMatrix4fv _glUniformMatrix4fv
#define glBindAttribLocation _glBindAttribLocation
#define glUseProgram _glUseProgram
#define glCompileShader _glCompileShader
#define glGetShaderiv _glGetShaderiv
#define glGetProgramiv _glGetProgramiv
#define glGetShaderInfoLog _glGetShaderInfoLog
#define glGetProgramInfoLog _glGetProgramInfoLog
#define glDispatchCompute _glDispatchCompute

// GL_FBO
#define glGenFramebuffers _glGenFramebuffers
#define glBindFramebuffer _glBindFramebuffer

// WGL
#ifdef _WIN32
#define wglCreateContextAttribsARB _wglCreateContextAttribsARB
#endif

#endif /* GL3_H_LOADER */
