#include "gl3.h"

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <GL/glx.h>
#endif

#ifdef _WIN32
static void* GetProc(char *name) {
    void *addr = wglGetProcAddress(name);
    if(!addr) {
	printf("error: could not load \"%s\"\n", name);
	return NULL;
    }
    return addr;
}
#else
static void* GetProc(char *name) {
    void *addr = glXGetProcAddress((const GLubyte*) name);
    if(!addr) {
	printf("error: could not load \"%s\"\n", name);
	return NULL;
    }
    return addr;
}
#endif

// GL_API
PFN_glClearColor _glClearColor = NULL;
PFN_glClear _glClear = NULL;

// GL_TEXTURE
PFN_glActiveTexture _glActiveTexture = NULL;
PFN_glGenTextures _glGenTextures = NULL;
PFN_glBindTexture _glBindTexture = NULL;
PFN_glTexImage2D _glTexImage2D = NULL;
PFN_glTexParameteri _glTexParameteri = NULL;
PFN_glGenerateMipmap _glGenerateMipmap = NULL;

// GL_VBO
PFN_glGenBuffers _glGenBuffers = NULL;
PFN_glBindBuffer _glBindBuffer = NULL;
PFN_glBufferData _glBufferData = NULL;
PFN_glEnableVertexAttribArray _glEnableVertexAttribArray = NULL;
PFN_glDisableVertexAttribArray _glDisableVertexAttribArray = NULL;
PFN_glDrawArrays _glDrawArrays = NULL;
PFN_glVertexAttribPointer _glVertexAttribPointer = NULL;

// GL_VAO
PFN_glGenVertexArrays _glGenVertexArrays = NULL;
PFN_glBindVertexArray _glBindVertexArray = NULL;

// GL_GLSL
PFN_glDetachShader _glDetachShader = NULL;
PFN_glDeleteShader _glDeleteShader = NULL;
PFN_glCreateProgram _glCreateProgram = NULL;
PFN_glCreateShader _glCreateShader = NULL;
PFN_glShaderSource _glShaderSource = NULL;
PFN_glAttachShader _glAttachShader = NULL;
PFN_glLinkProgram _glLinkProgram = NULL;
PFN_glGetUniformLocation _glGetUniformLocation = NULL;
PFN_glGetAttribLocation _glGetAttribLocation = NULL;
PFN_glUniform1f _glUniform1f = NULL;
PFN_glUniform2f _glUniform2f = NULL;
PFN_glUniform3f _glUniform3f = NULL;
PFN_glUniform4f _glUniform4f = NULL;
PFN_glUniformMatrix4fv _glUniformMatrix4fv = NULL;
PFN_glBindAttribLocation _glBindAttribLocation = NULL;
PFN_glUseProgram _glUseProgram = NULL;
PFN_glCompileShader _glCompileShader = NULL;
PFN_glGetShaderiv _glGetShaderiv = NULL;
PFN_glGetProgramiv _glGetProgramiv = NULL;
PFN_glGetShaderInfoLog _glGetShaderInfoLog = NULL;
PFN_glGetProgramInfoLog _glGetProgramInfoLog = NULL;
PFN_glDispatchCompute _glDispatchCompute = NULL;

// GL_FBO
PFN_glGenFramebuffers _glGenFramebuffers = NULL;
PFN_glBindFramebuffer _glBindFramebuffer = NULL;

// WGL
#ifdef _WIN32
PFN_wglCreateContextAttribsARB _wglCreateContextAttribsARB = NULL;
#endif

void LoadFunctions(void) {
    _glClearColor = GetProc("glClearColor");
    _glClear = GetProc("glClear");
    
    _glActiveTexture = GetProc("glActiveTexture");
    _glGenTextures = GetProc("glGenTextures");
    _glBindTexture = GetProc("glBindTexture");
    _glTexImage2D = GetProc("glTexImage2D");
    _glTexParameteri = GetProc("glTexParameteri");
    _glGenerateMipmap = GetProc("glGenerateMipmap");
    
    _glGenBuffers = GetProc("glGenBuffers");
    _glBindBuffer = GetProc("glBindBuffer");
    _glBufferData = GetProc("glBufferData");
    _glEnableVertexAttribArray = GetProc("glEnableVertexAttribArray");
    _glDisableVertexAttribArray = GetProc("glDisableVertexAttribArray");
    _glDrawArrays = GetProc("glDrawArrays");
    _glVertexAttribPointer = GetProc("glVertexAttribPointer");

    _glGenVertexArrays = GetProc("glGenVertexArrays");
    _glBindVertexArray = GetProc("glBindVertexArray");

    _glDetachShader = GetProc("glDetachShader");
    _glDeleteShader = GetProc("glDeleteShader");
    _glCreateProgram = GetProc("glCreateProgram");
    _glCreateShader = GetProc("glCreateShader");
    _glShaderSource = GetProc("glShaderSource");
    _glAttachShader = GetProc("glAttachShader");
    _glLinkProgram = GetProc("glLinkProgram");
    _glGetUniformLocation = GetProc("glGetUniformLocation");
    _glGetAttribLocation = GetProc("glGetAttribLocation");
    _glUniform1f = GetProc("glUniform1f");
    _glUniform2f = GetProc("glUniform2f");
    _glUniform3f = GetProc("glUniform3f");
    _glUniform4f = GetProc("glUniform4f");
    _glUniformMatrix4fv = GetProc("glUniformMatrix4fv");
    _glBindAttribLocation = GetProc("glBindAttribLocation");
    _glUseProgram = GetProc("glUseProgram");
    _glCompileShader = GetProc("glCompileShader");
    _glGetShaderiv = GetProc("glGetShaderiv");
    _glGetProgramiv = GetProc("glGetProgramiv");
    _glGetShaderInfoLog = GetProc("glGetShaderInfoLog");
    _glGetProgramInfoLog = GetProc("glGetProgramInfoLog");
    _glDispatchCompute = GetProc("glDispatchCompute");

    _glGenFramebuffers = GetProc("glGenFramebuffers");
    _glBindFramebuffer = GetProc("glBindFramebuffer");
    
#ifdef _WIN32
    _wglCreateContextAttribsARB = GetProc("wglCreateContextAttribsARB");
#endif
}
