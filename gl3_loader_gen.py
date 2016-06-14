import os
import sys

funcs = [
    # GL_API
    ['void', 'ClearColor', '(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)'],
    ['void', 'Clear', '(GLbitfield mask)'],
    # GL_TEXTURE
    ['void', 'ActiveTexture', '(GLenum texture)'],
    ['void', 'GenTextures', '(GLsizei n, GLuint* textures)'],
    ['void', 'BindTexture', '(GLenum target, GLuint texture)'],
    ['void', 'TexImage2D', '(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data)'],
    ['void', 'TexParameteri', '(GLenum target, GLenum pname, GLint param)'],
    ['void', 'GenerateMipmap', '(GLenum target)'],
    # GL_VBO
    ['void', 'GenBuffers', '(GLsizei n, GLuint* buffers)'],
    ['void', 'BindBuffer', '(GLenum target, GLuint buffer)'],
    ['void', 'BufferData', '(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)'],
    ['void', 'EnableVertexAttribArray', '(GLuint index)'],
    ['void', 'DisableVertexAttribArray', '(GLuint index)'],
    ['void', 'DrawArrays', '(GLenum mode, GLsizei first, GLsizei count)'],
    ['void', 'VertexAttribPointer', '(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)'],
    # GL_VAO
    ['void', 'GenVertexArrays', '(GLsizei n, GLuint* arrays)'],
    ['void', 'BindVertexArray', '(GLuint array)'],
    # GL_GLSL
    ['void', 'DetachShader', '(GLuint program, GLuint shader)'],
    ['void', 'DeleteShader', '(GLuint shader)'],
    ['GLuint', 'CreateProgram', '(void)'],
    ['GLuint', 'CreateShader', '(GLenum shaderType)'],
    ['void', 'ShaderSource', '(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length)'],
    ['void', 'AttachShader', '(GLuint program, GLuint shader)'],
    ['void', 'LinkProgram', '(GLuint program)'],
    ['GLint', 'GetUniformLocation', '(GLuint program, const GLchar* name)'],
    ['GLint', 'GetAttribLocation', '(GLuint program, const GLchar* name)'],
    ['void', 'Uniform1f', '(GLint location, GLfloat v0)'],
    ['void', 'Uniform2f', '(GLint location, GLfloat v0, GLfloat v1)'],
    ['void', 'Uniform3f', '(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)'],
    ['void', 'Uniform4f', '(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)'],
    ['void', 'UniformMatrix4fv', '(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)'],
    ['void', 'BindAttribLocation', '(GLuint location, GLuint index, const GLchar* name)'],
    ['void', 'UseProgram', '(GLuint program)'],
    ['void', 'CompileShader', '(GLuint shader)'],
    ['void', 'GetShaderiv', '(GLuint shader, GLenum pname, GLint* params)'],
    ['void', 'GetProgramiv', '(GLuint program, GLenum pname, GLint* params)'],
    ['void', 'GetShaderInfoLog', '(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog)'],
    ['void', 'GetProgramInfoLog', '(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog)'],
    # GL_FBO
    ['void', 'GenFramebuffers', '(GLsizei n, GLuint* ids)'],
    ['void', 'BindFramebuffer', '(GLenum target, GLuint framebuffer)']
]

pwd = os.getenv('PWD')

if len(sys.argv) != 2:
    print('usage: %s [x11|win32]' % sys.argv[0])
    sys.exit(1)

platform = sys.argv[1]

def do_write_types_and_constants(_file):
    hdr = open('gl3_consts_and_types.h', 'r')
    _file.write(hdr.read())

def do_platform_x11():
    f = open('gl3-x11.h', 'w')
    f.write('''#ifndef _gl3_x11_h_
#define _gl3_x11_h_

''')
    do_write_types_and_constants(f)
    f.write('\n')
    for func_entry in funcs:
        f.write(func_entry[0] + ' gl' + func_entry[1] + func_entry[2] + ';\n')
    f.write('''
#endif /* _gl3_x11_h_ */''')

def do_platform_win32():
    f = open('gl3-win32.h', 'w')
    f.write('''#ifndef _gl3_win32_h_
#define _gl3_win32_h_

''')
    do_write_types_and_constants(f)
    f.write('\n')
    for func_entry in funcs:
        f.write('typedef ' + func_entry[0] + ' (*PFN_gl' + func_entry[1] + ')' + func_entry[2] + ';\n')
    f.write('\n')
    for func_entry in funcs:
        f.write('PFN_gl' + func_entry[1] + ' _gl' + func_entry[2] + ';\n')
    f.write('\n')
    for func_entry in funcs:
        f.write('#define gl' + func_entry[1] + ' _gl' + func_entry[1] + '\n')
    f.write('''

typedef (*PFN_wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int* attribList);
PFN_wglCreateContextAttribsARB _wglCreateContextAttribsARB;
#define wglCreateContextAttribsARB _wglCreateContextAttribsARB

#endif /* _gl3_win32_h_ */''')
    # why does only windows need this
    f = open('gl3-win32.c', 'w')
    f.write('''#include "gl3.h"

void* GetProc(char *name) {
    void *addr = wglGetProcAddress(name);
    if(!addr) {
        printf("error: could not load \\"%s\\"\\n", name);
    }
    return addr;
}

''')
    for func_entry in funcs:
        f.write('_gl' + func_entry[1] + ' = NULL;\n')
    f.write('''

void LoadFunctions(void) {
''')
    for func_entry in funcs:
        f.write('    ')
        f.write('_gl' + func_entry[1] + ' = GetProc("gl' + func_entry[1] + '");\n')
    f.write('''}''')

if platform == 'x11':
    do_platform_x11()
elif platform == 'win32':
    do_platform_win32()
elif platform == 'cocoa':
    print('cocoa opengl header at <OpenGL/gl3.h>')
    sys.exit(1)
else:
    print('error, invalid platform')
    sys.exit(1)
