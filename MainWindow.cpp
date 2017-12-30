#include "MainWindow.h"
#include "ui_MainWindow.h"

#include<QDebug>
#include <Qsci/qsciscintilla.h>
#include "QsciLexerGlsl.h"
#include <Qsci/qscilexercpp.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 0
    /** ���ô���༭�� **/
    m_code_edit =new QsciScintilla(this);
    m_code_edit->setGeometry(200,0,920,720);
    QsciLexerGLSL *textLexer = new QsciLexerGLSL;//����һ���ʷ�������
    QsciAPIs*apis = new QsciAPIs(textLexer);
    if(!apis->load(QString("glsl.api")))
          qDebug()<<"��ȡ�ļ�ʧ��";
       else
          apis->prepare();
    m_code_edit->setLexer(textLexer);//��QsciScintilla���ôʷ�������
    m_code_edit->setMarginType(0,QsciScintilla::NumberMargin);//���ñ��Ϊ0��ҳ����ʾ�кš�
    m_code_edit->setMarginLineNumbers(0,true);//�Ը�ҳ�������к�
    m_code_edit->setMarginWidth(0,50);//����ҳ�߿��
    m_code_edit->setAutoCompletionSource(QsciScintilla::AcsAll);   //����Դ
    m_code_edit->setAutoCompletionCaseSensitivity(false);   //�����Զ���ȫ��Сд����
    m_code_edit->setAutoCompletionThreshold(1);    //����ÿ����һ���ַ��ͻ�����Զ���ȫ����ʾ
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}
