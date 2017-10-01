#include "GLRender.h"
#include <windows.h>
#include <opengl/glew.h>
#include <iostream>
#include <QDebug>
using namespace std;
GLRender::GLRender(HWND hWnd):
    m_glProgramHandle(-1),
    m_vaoHandle(-1),
    m_glslFlagShader(-1),
    m_height(100),
    m_width(100)
{
    m_hWnd =hWnd;
    InitGLContext();
    InitGlew();
    CreateVAO();
    //CreateGLSL();
    loadGlslCode(this->GLSL_FLAG_DEFUAT);

    qDebug()<<this->m_glProgramHandle   <<this->m_glslFlagShader    <<this->m_vaoHandle
           <<this->m_hDC                <<this->m_hRC               <<this->m_hWnd    ;
}

void GLRender::InitGLContext()
{
    m_hDC = GetDC(m_hWnd);
    //��ʼ�����ظ�ʽ
    static    PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR),    //������ʽ�������Ĵ�С
        1,                                //�汾��
        PFD_DRAW_TO_WINDOW |              //��ʽ֧�ִ���
        PFD_SUPPORT_OPENGL |              //��ʽ����֧��OpenGL
        PFD_DOUBLEBUFFER,                 //����֧��˫����
        PFD_TYPE_RGBA,                    //����RGBA ��ʽ
        24,                               //ѡ��ɫ�����
        0, 0, 0, 0, 0, 0, 0, 0,           //����RGBA
        0,                                //���ۼӻ���
        0, 0, 0, 0,                       //���Ծۼ�λ
        32,                               //32λZ-����(��Ȼ���)
        0,                                //���ɰ建��
        0,                                //�޸�������
        PFD_MAIN_PLANE,                   //����ͼ��
        0,                                //Reserved
        0, 0, 0                           //���Բ�����
    };
    //ѡ��һ�����ʺ�pfd���������ظ�ʽ����ֵ
    int nPixelFormat = ChoosePixelFormat(m_hDC, &pfd);
    //ΪDC�������ظ�ʽ
    SetPixelFormat(m_hDC, nPixelFormat, &pfd);
    //����RC
    m_hRC = wglCreateContext(m_hDC);

    useContext();
}

bool GLRender::InitGlew(){
    useContext();
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        cerr << "Error initializing GLEW: " << glewGetErrorString(err) << endl;
        return false;
    }
    return true;
}

void GLRender::CreateVAO(){
    useContext();

    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint positionBufferHandle = vboHandles[0];
    GLuint indexesHandle	=vboHandles[1];
    //��VBO�Թ�ʹ��
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    //�������ݵ�VBO
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat),VAO_Points2d, GL_STATIC_DRAW);
    glGenVertexArrays(1, &m_vaoHandle);
    glBindVertexArray(m_vaoHandle);
    glEnableVertexAttribArray(0);//��������
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexesHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), VAO_Indexes, GL_STATIC_DRAW);

    clearContext();
}

void GLRender::CreateGLSL(){
    useContext();
    if(m_glProgramHandle!=-1)
        glDeleteProgram(m_glProgramHandle);
    qDebug()<<"m_glProgramHandle"<<(m_glProgramHandle=glCreateProgram());
    if (!m_glProgramHandle){
        cerr << "ERROR : create program failed" << endl;
    }
    clearContext();

    //resize(m_width,m_height);
}

