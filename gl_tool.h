#ifndef GL_TOOL_H
#define GL_TOOL_H


#include<opengl/glew.h>
#include<Windows.h>
#include<iostream>
using namespace std;
namespace gl {


inline void InitGLContext(HWND hWnd,HGLRC& m_hRC , HDC &m_hDC)
{
    m_hDC = GetDC(hWnd);
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
    wglMakeCurrent(m_hDC, m_hRC);
}

inline bool InitGlew(){
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        cerr << "Error initializing GLEW: " << glewGetErrorString(err) << endl;
        return false;
    }
    return true;
}



}

#endif // GL_TOOL_H
