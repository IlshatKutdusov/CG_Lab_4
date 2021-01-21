#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14
//переменные для угла объекта/источника света, позиции источника света
GLfloat objAngle = 0;
GLfloat lightAngle = 0;
GLfloat rX = 0;
GLfloat rZ = 0;
//переменные состояния объекта/источника света
bool ObjRotState = false;
bool LightRotState = false;
//функция инициализация
void init(void)
{
	glClearColor(0.3, 0.5, 0.3, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//установка перспективы
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//функция исполняема при изменении размеров окна
void FormReshape(int width, int height)
{
	if (width / height < 1) glViewport(0, 0, width, width);
	else glViewport(0, 0, height, height);
}
//функция рендера всей сцены
void SceneRender()
{
	//значения параметров материала для источника света
	GLfloat diffuse[] = { 0.4, 0.4, 0.4, 1 };
	GLfloat specular[] = { 0.774597, 0.774597, 0.774597, 1 };
	GLfloat ambient[] = { 0.25, 0.25, 0.25, 1 };
	GLfloat shininess[] = { 76.8 };
	//позиция источника
	GLfloat LightPosition[] = { 3.0 * rX, 3.0 , 3.0 * rZ, 1.0 };
	//устанавливаем параметры материала для FRONT/BACK
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glMaterialfv(GL_BACK, GL_SHININESS, shininess);

	glPushMatrix();
	//очищаем буффер
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//включаем вычисление невидимых частей
	glEnable(GL_DEPTH_TEST);
	//устанавливаем наблюдателя
	gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	//источник света
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
	//поворот объекта вокруг Оy
	glRotatef(objAngle, 0, 1, 0);
	
	//Буква A
	// Лицевая сторона
	{
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(0.3, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, 0);
		glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0); glVertex3f(1.2, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(1.5, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, 0);
		glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0); glVertex3f(0.3, 0.6, 0);
		glTexCoord2f(0, 1); glVertex3f(0.45, 0.9, 0);
		glTexCoord2f(1, 0); glVertex3f(1.05, 0.9, 0);
		glTexCoord2f(1, 1); glVertex3f(1.2, 0.6, 0);
		glEnd();
	}
	// задняя сторона
	{
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -0.5);
		glTexCoord2f(0, 1); glVertex3f(0.3, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, -0.5);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(1.2, 0, -0.5);
		glTexCoord2f(0, 1); glVertex3f(1.5, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, -0.5);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(0.3, 0.6, -0.5);
		glTexCoord2f(0, 1); glVertex3f(0.45, 0.9, -0.5);
		glTexCoord2f(1, 0); glVertex3f(1.05, 0.9, -0.5);
		glTexCoord2f(1, 1); glVertex3f(1.2, 0.6, -0.5);
		glEnd();
	}

	{
		//левая А
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(0.3, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(0.3, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.9, 1.5, 0);
		glEnd();
		//правая А
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(1.5, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(1.5, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.9, 1.5, 0);
		glEnd();

		//верх
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(0.9, 1.5, 0);
		glTexCoord2f(0, 1); glVertex3f(0.9, 1.5, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.9, 1.5, 0);
		glEnd();
	}
	{
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(0, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.6, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(1.2, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(1.2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(0.6, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
		glEnd();
	}

	// K
	{
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(-1.6, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(-1.6, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(-1.6, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(-1.6, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(-1.4, 0.9, 0);
		glTexCoord2f(0, 1); glVertex3f(-1.4, 0.9, -0.5);
		glTexCoord2f(1, 0); glVertex3f(-0.2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(-0.2, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
		glTexCoord2f(0, 1); glVertex3f(-1.3, 0.6, -0.5);
		glTexCoord2f(1, 0); glVertex3f(-0.4, 0, -0.5);
		glTexCoord2f(1, 1); glVertex3f(-0.4, 0, 0);
		glEnd();
	}
	// передняя стенка
	{glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-1.6, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(-1.3, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(-1.6, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, 0);
	glTexCoord2f(1, 0); glVertex3f(-0.4, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, 0);
	glTexCoord2f(1, 0); glVertex3f(-0.1, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(-0.4, 0, 0);
	glEnd(); }
	// задняя стенка
	{glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(-1.6, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-1.3, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-1.6, 1.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); (-1.3, 0.6, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.4, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); (-1.3, 0.6, -0.5);
	glTexCoord2f(0, 1); (-1.3, 0.9, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.1, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.4, 0, -0.5);
	glEnd(); }
	//право верх
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0.6, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.1, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, 0);
	glEnd(); }
	//право низ
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.3, 0.9, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.1, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.1, 0, 0);
	glEnd(); }
	//право
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.3, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-1.3, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-1.3, 1.5, 0);
	glEnd(); }

	//верх
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.7, 1.5, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.7, 1.5, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-1.7, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-1.7, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-0.4, 1.5, 0);
	glTexCoord2f(0, 1); glVertex3f(-0.4, 1.5, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.1, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, 0);
	glEnd(); }

	//Буква И
	//Лицевая сторона
	{
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0); glVertex3f(1.7, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(2, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(2, 1.5, 0);
		glTexCoord2f(1, 1); glVertex3f(1.7, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0); glVertex3f(1.7, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(2, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, 0);
		glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0); glVertex3f(2.9, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(3.2, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, 0);
		glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
		glEnd();
	}


	//Задняя сторона
	{
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(1.7, 0, -0.5);
		glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(1.7, 1.5, -0.5);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(1.7, 0, -0.5);
		glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, -0.5);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(2.9, 0, -0.5);
		glTexCoord2f(0, 1); glVertex3f(3.2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, -0.5);
		glEnd();
	}

	//правая сторона
	{
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0, 0); glVertex3f(2, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(2, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0.5, 0.5, 0);
		glTexCoord2f(0, 0); glVertex3f(2, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(3.2, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0, 0); glVertex3f(3.2, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(3.2, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(3.2, 1.5, 0);
		glEnd();
	}

	//левая сторона
	{
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glTexCoord2f(0, 0); (1.7, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(1.7, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(1.7, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(1.7, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1, 1, 0);
		glTexCoord2f(0, 0); glVertex3f(1.7, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(1.7, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(2.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0, 0); glVertex3f(2.9, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(2.9, 0, -0.5);
		glTexCoord2f(1, 0); glVertex3f(2.9, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
		glEnd();
	}

	//верх
	{
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(1.7, 1.5, 0);
		glTexCoord2f(0, 1); glVertex3f(1.7, 1.5, -0.5);
		glTexCoord2f(1, 0); glVertex3f(2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(2, 1.5, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0, 0); glVertex3f(2.9, 1.5, 0);
		glTexCoord2f(0, 1); glVertex3f(2.9, 1.5, -0.5);
		glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
		glTexCoord2f(1, 1); glVertex3f(3.2, 1.5, 0);
		glEnd();
	}

	//справа блоки
	// верх
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, 0);
	glTexCoord2f(0, 1); glVertex3f(7.75, 1.65, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.25, 1.65, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.25, 1.65, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, 0);
	glTexCoord2f(0, 1); glVertex3f(7.3, 1.05, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.55, 1.05, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.55, 1.05, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, 0);
	glTexCoord2f(0, 1); glVertex3f(5.05, 0.45, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.55, 0.45, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.55, 0.45, 0);
	glEnd(); }
	// низ
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(3.55, 1.2, 0);
	glTexCoord2f(0, 1); glVertex3f(3.55, 1.2, -0.5);
	glTexCoord2f(1, 0); glVertex3f(7.45, 1.2, -0.5);
	glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(3.55, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(3.55, 0.6, -0.5);
	glTexCoord2f(1, 0); glVertex3f(7, 0.6, -0.5);
	glTexCoord2f(1, 1); glVertex3f(7, 0.6, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(3.25, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(3.25, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(4.75, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(4.75, 0, 0);
	glEnd(); }
	// передняя стешка
	{glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, 0);
	glTexCoord2f(0, 1); glVertex3f(3.25, 1.65, 0);
	glTexCoord2f(1, 0); glVertex3f(3.55, 1.2, 0);
	glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, 0);
	glTexCoord2f(0, 1); glVertex3f(3.55, 1.05, 0);
	glTexCoord2f(1, 0); glVertex3f(3.55, 0.6, 0);
	glTexCoord2f(1, 1); glVertex3f(7, 0.6, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, 0);
	glTexCoord2f(0, 1); glVertex3f(3.55, 0.45, 0);
	glTexCoord2f(1, 0); glVertex3f(3.25, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(4.75, 0, 0);
	glEnd(); }
	// задняя стенка
	{glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, -0.5);
	glTexCoord2f(0, 1); glVertex3f(3.25, 1.65, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.55, 1.2, -0.5);
	glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, -0.5);
	glTexCoord2f(0, 1); glVertex3f(3.55, 1.05, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.55, 0.6, -0.5);
	glTexCoord2f(1, 1); glVertex3f(7, 0.6, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, -0.5);
	glTexCoord2f(0, 1); glVertex3f(3.55, 0.45, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.25, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(4.75, 0, -0.5);
	glEnd(); }
	// правая стенка
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(3.25, 1.65, -0.5);
	glTexCoord2f(0, 1); glVertex3f(3.25, 1.65, 0);
	glTexCoord2f(1, 0); glVertex3f(3.55, 1.2, 0);
	glTexCoord2f(1, 1); glVertex3f(3.55, 1.2, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); (3.55, 1.05, -0.5);
	glTexCoord2f(0, 1); glVertex3f(3.55, 1.05, 0);
	glTexCoord2f(1, 0); glVertex3f(3.55, 0.6, 0);
	glTexCoord2f(1, 1); glVertex3f(3.55, 0.6, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(3.25, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(3.25, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.55, 0.45, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.55, 0.45, 0);
	glEnd(); }
	// левая стенка
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, 0);
	glTexCoord2f(0, 1); glVertex3f(7.75, 1.65, -0.5);
	glTexCoord2f(1, 0); glVertex3f(7.45, 1.2, -0.5);
	glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, 0);
	glTexCoord2f(0, 1); glVertex3f(7.3, 1.05, -0.5);
	glTexCoord2f(1, 0); glVertex3f(7, 0.6, -0.5);
	glTexCoord2f(1, 1); glVertex3f(7, 0.6, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, 0);
	glTexCoord2f(0, 1); glVertex3f(5.05, 0.45, -0.5);
	glTexCoord2f(1, 0); glVertex3f(4.75, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(4.75, 0, 0);
	glEnd(); }

	//слева блоки
	// верх
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, 0);
	glTexCoord2f(0, 1); glVertex3f(-6.2, 1.65, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-1.7, 1.65, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-1.7, 1.65, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-5.75, 1.05, 0);
	glTexCoord2f(0, 1); glVertex3f(-5.75, 1.05, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-2, 1.05, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-2, 1.05, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, 0);
	glTexCoord2f(0, 1); glVertex3f(-3.5, 0.45, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-2, 0.45, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-2, 0.45, 0);
	glEnd(); }
	// низ
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); (-2, 1.2, 0);
	glTexCoord2f(0, 1); glVertex3f(-2, 1.2, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-5.9, 1.2, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-2, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(-2, 0.6, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-5.45, 0.6, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.7, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.7, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-3.2, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-3.2, 0, 0);
	glEnd(); }
	// передняя стенка
	{glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.7, 1.65, 0);
	glTexCoord2f(1, 0); glVertex3f(-2, 1.2, 0);
	glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); (-5.75, 1.05, 0);
	glTexCoord2f(0, 1); (-2, 1.05, 0);
	glTexCoord2f(1, 0); glVertex3f(-2, 0.6, 0);
	glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, 0);
	glTexCoord2f(0, 1); glVertex3f(-2, 0.45, 0);
	glTexCoord2f(1, 0); glVertex3f(-1.7, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(-3.2, 0, 0);
	glEnd(); }
	// задняя стенка
	{glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-1.7, 1.65, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-2, 1.2, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(-5.75, 1.05, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-2, 1.05, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-2, 0.6, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-2, 0.45, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-1.7, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-3.2, 0, -0.5);
	glEnd(); }
	// правая стенка
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.7, 1.65, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-1.7, 1.65, 0);
	glTexCoord2f(1, 0); glVertex3f(-2, 1.2, 0);
	glTexCoord2f(1, 1); glVertex3f(-2, 1.2, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-2, 1.05, -0.5);
	glTexCoord2f(0, 1); glVertex3f(-2, 1.05, 0);
	glTexCoord2f(1, 0); (-2, 0.6, 0);
	glTexCoord2f(1, 1); glVertex3f(-2, 0.6, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.7, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.7, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-2, 0.45, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-2, 0.45, 0);
	glEnd(); }
	// левая стенка
	{glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, 0);
	glTexCoord2f(0, 1); glVertex3f(-6.2, 1.65, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-5.9, 1.2, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-5.75, 1.05, 0);
	glTexCoord2f(0, 1); glVertex3f(-5.75, 1.05, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-5.45, 0.6, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, 0);
	glTexCoord2f(0, 1); glVertex3f(-3.5, 0.45, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-3.2, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-3.2, 0, 0);
	glEnd(); }

	glPopMatrix();
	//отключаем источник света для осей
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	//рисуем оси
	glColor3f(1, 0, 0); 
	glVertex3f(0, 0, 0); glVertex3f(2, 0, 0); //Ox
	glColor3f(0, 0, 1); 
	glVertex3f(0, 0, 0); glVertex3f(0, 2, 0); //Oy
	glColor3f(0, 1, 0); 
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 2); //Oz
	glEnd();
	//линия от источника света до начала координат
	glBegin(GL_LINES);
	glColor3f(1, 1, 1); 
	glVertex3f(3 * rX, 3, 3 * rZ); 
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
//функция для изменения угла объекта и источника света
void ObjLightAngle()
{
	if (ObjRotState) {
		objAngle += 0.5;
		if (objAngle > 360.0)
			objAngle = 0;
	}
	if (LightRotState) {
		lightAngle += PI / 64;
		if (lightAngle > 2 * PI)
			lightAngle = 0;
		rX = sin(lightAngle);
		rZ = cos(lightAngle);
	}
	//перерисовываем окно
	glutPostRedisplay();
}
//функция для отслеживания нажатых клавиш
void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'o': //если нажата О
		ObjRotState = true;
		LightRotState = false;
		break;
	case 'l': //если нажата L
		ObjRotState = false;
		LightRotState = true;
		break;
	case 's': //и так далее
		ObjRotState = false;
		LightRotState = false;
		break;
	case 'f': //визуализация лицевых граней
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE); 
		break;
	case 'b': //визуализация нелицевых граней
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
		break;
	default:
		break;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CG_Lab_4");
	//функция рендера окна
	glutDisplayFunc(SceneRender);
	//функция при изменеии размеров окна
	glutReshapeFunc(FormReshape);
	//фукнция для изменения угла объекта/источника света
	glutIdleFunc(ObjLightAngle);
	//функция при нажатии клавиш
	glutKeyboardFunc(processNormalKeys);
	init();
	glutMainLoop();
}



//Буква A
	// Лицевая сторона
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0.3, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(1.2, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1.5, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(0.3, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(0.45, 0.9, 0);
	glTexCoord2f(1, 0); glVertex3f(1.05, 0.9, 0);
	glTexCoord2f(1, 1); glVertex3f(1.2, 0.6, 0);
	glEnd();
}
// задняя сторона
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(0, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(0.3, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.2, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(1.5, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(0.3, 0.6, -0.5);
	glTexCoord2f(0, 1); glVertex3f(0.45, 0.9, -0.5);
	glTexCoord2f(1, 0); glVertex3f(1.05, 0.9, -0.5);
	glTexCoord2f(1, 1); glVertex3f(1.2, 0.6, -0.5);
	glEnd();
}

{
	//левая А
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(0.3, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0.3, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.9, 1.5, 0);
	glEnd();
	//правая А
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(1.5, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1.5, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.9, 1.5, 0);
	glEnd();

	//верх
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(0.9, 1.5, 0);
	glTexCoord2f(0, 1); glVertex3f(0.9, 1.5, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.9, 1.5, 0);
	glEnd();
}
{
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.6, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(1.2, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1.2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.6, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(0.6, 1.5, 0);
	glEnd();
}

// K
{
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.6, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.6, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-1.6, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-1.6, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.4, 0.9, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.4, 0.9, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.2, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
	glTexCoord2f(0, 1); glVertex3f(-1.3, 0.6, -0.5);
	glTexCoord2f(1, 0); glVertex3f(-0.4, 0, -0.5);
	glTexCoord2f(1, 1); glVertex3f(-0.4, 0, 0);
	glEnd();
}
// передняя стенка
{glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(-1.6, 0, 0);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0, 0);
glTexCoord2f(1, 0); glVertex3f(-1.3, 1.5, 0);
glTexCoord2f(1, 1); glVertex3f(-1.6, 1.5, 0);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, 0);
glTexCoord2f(1, 0); glVertex3f(-0.4, 1.5, 0);
glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, 0);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, 0);
glTexCoord2f(1, 0); glVertex3f(-0.1, 0, 0);
glTexCoord2f(1, 1); glVertex3f(-0.4, 0, 0);
glEnd(); }
// задняя стенка
{glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(-1.6, 0, -0.5);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0, -0.5);
glTexCoord2f(1, 0); glVertex3f(-1.3, 1.5, -0.5);
glTexCoord2f(1, 1); glVertex3f(-1.6, 1.5, -0.5);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); (-1.3, 0.6, -0.5);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, -0.5);
glTexCoord2f(1, 0); glVertex3f(-0.4, 1.5, -0.5);
glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, -0.5);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); (-1.3, 0.6, -0.5);
glTexCoord2f(0, 1); (-1.3, 0.9, -0.5);
glTexCoord2f(1, 0); glVertex3f(-0.1, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(-0.4, 0, -0.5);
glEnd(); }
//право верх
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.3, 0.6, 0);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0.6, -0.5);
glTexCoord2f(1, 0); glVertex3f(-0.1, 1.5, -0.5);
glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, 0);
glEnd(); }
//право низ
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.3, 0.9, 0);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0.9, -0.5);
glTexCoord2f(1, 0); glVertex3f(-0.1, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(-0.1, 0, 0);
glEnd(); }
//право
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.3, 0, 0);
glTexCoord2f(0, 1); glVertex3f(-1.3, 0, -0.5);
glTexCoord2f(1, 0); glVertex3f(-1.3, 1.5, -0.5);
glTexCoord2f(1, 1); glVertex3f(-1.3, 1.5, 0);
glEnd(); }

//верх
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.7, 1.5, 0);
glTexCoord2f(0, 1); glVertex3f(-1.7, 1.5, -0.5);
glTexCoord2f(1, 0); glVertex3f(-1.7, 1.5, -0.5);
glTexCoord2f(1, 1); glVertex3f(-1.7, 1.5, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-0.4, 1.5, 0);
glTexCoord2f(0, 1); glVertex3f(-0.4, 1.5, -0.5);
glTexCoord2f(1, 0); glVertex3f(-0.1, 1.5, -0.5);
glTexCoord2f(1, 1); glVertex3f(-0.1, 1.5, 0);
glEnd(); }

//Буква И
//Лицевая сторона
{
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(1.7, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(2, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(2, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(1.7, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(1.7, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(2, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(2.9, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(3.2, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, 0);
	glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
	glEnd();
}


//Задняя сторона
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.7, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(1.7, 1.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.7, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(2.9, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(3.2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, -0.5);
	glEnd();
}

//правая сторона
{
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(2, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(2, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.5, 0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(2, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.2, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(3.2, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(3.2, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.2, 1.5, 0);
	glEnd();
}

//левая сторона
{
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); (1.7, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1.7, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(1.7, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(1.7, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(-1, 1, 0);
	glTexCoord2f(0, 0); glVertex3f(1.7, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1.7, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(2.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(2.9, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(2.9, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(2.9, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(2.9, 1.5, 0);
	glEnd();
}

//верх
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.7, 1.5, 0);
	glTexCoord2f(0, 1); glVertex3f(1.7, 1.5, -0.5);
	glTexCoord2f(1, 0); glVertex3f(2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(2, 1.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(2.9, 1.5, 0);
	glTexCoord2f(0, 1); glVertex3f(2.9, 1.5, -0.5);
	glTexCoord2f(1, 0); glVertex3f(3.2, 1.5, -0.5);
	glTexCoord2f(1, 1); glVertex3f(3.2, 1.5, 0);
	glEnd();
}

//справа блоки
// верх
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, 0);
glTexCoord2f(0, 1); glVertex3f(7.75, 1.65, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.25, 1.65, -0.5);
glTexCoord2f(1, 1); glVertex3f(3.25, 1.65, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, 0);
glTexCoord2f(0, 1); glVertex3f(7.3, 1.05, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.55, 1.05, -0.5);
glTexCoord2f(1, 1); glVertex3f(3.55, 1.05, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, 0);
glTexCoord2f(0, 1); glVertex3f(5.05, 0.45, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.55, 0.45, -0.5);
glTexCoord2f(1, 1); glVertex3f(3.55, 0.45, 0);
glEnd(); }
// низ
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(3.55, 1.2, 0);
glTexCoord2f(0, 1); glVertex3f(3.55, 1.2, -0.5);
glTexCoord2f(1, 0); glVertex3f(7.45, 1.2, -0.5);
glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(3.55, 0.6, 0);
glTexCoord2f(0, 1); glVertex3f(3.55, 0.6, -0.5);
glTexCoord2f(1, 0); glVertex3f(7, 0.6, -0.5);
glTexCoord2f(1, 1); glVertex3f(7, 0.6, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(3.25, 0, 0);
glTexCoord2f(0, 1); glVertex3f(3.25, 0, -0.5);
glTexCoord2f(1, 0); glVertex3f(4.75, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(4.75, 0, 0);
glEnd(); }
// передняя стешка
{glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, 0);
glTexCoord2f(0, 1); glVertex3f(3.25, 1.65, 0);
glTexCoord2f(1, 0); glVertex3f(3.55, 1.2, 0);
glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, 0);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, 0);
glTexCoord2f(0, 1); glVertex3f(3.55, 1.05, 0);
glTexCoord2f(1, 0); glVertex3f(3.55, 0.6, 0);
glTexCoord2f(1, 1); glVertex3f(7, 0.6, 0);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, 0);
glTexCoord2f(0, 1); glVertex3f(3.55, 0.45, 0);
glTexCoord2f(1, 0); glVertex3f(3.25, 0, 0);
glTexCoord2f(1, 1); glVertex3f(4.75, 0, 0);
glEnd(); }
// задняя стенка
{glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, -0.5);
glTexCoord2f(0, 1); glVertex3f(3.25, 1.65, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.55, 1.2, -0.5);
glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, -0.5);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, -0.5);
glTexCoord2f(0, 1); glVertex3f(3.55, 1.05, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.55, 0.6, -0.5);
glTexCoord2f(1, 1); glVertex3f(7, 0.6, -0.5);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, -0.5);
glTexCoord2f(0, 1); glVertex3f(3.55, 0.45, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.25, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(4.75, 0, -0.5);
glEnd(); }
// правая стенка
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(3.25, 1.65, -0.5);
glTexCoord2f(0, 1); glVertex3f(3.25, 1.65, 0);
glTexCoord2f(1, 0); glVertex3f(3.55, 1.2, 0);
glTexCoord2f(1, 1); glVertex3f(3.55, 1.2, -0.5);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); (3.55, 1.05, -0.5);
glTexCoord2f(0, 1); glVertex3f(3.55, 1.05, 0);
glTexCoord2f(1, 0); glVertex3f(3.55, 0.6, 0);
glTexCoord2f(1, 1); glVertex3f(3.55, 0.6, -0.5);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(3.25, 0, 0);
glTexCoord2f(0, 1); glVertex3f(3.25, 0, -0.5);
glTexCoord2f(1, 0); glVertex3f(3.55, 0.45, -0.5);
glTexCoord2f(1, 1); glVertex3f(3.55, 0.45, 0);
glEnd(); }
// левая стенка
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(7.75, 1.65, 0);
glTexCoord2f(0, 1); glVertex3f(7.75, 1.65, -0.5);
glTexCoord2f(1, 0); glVertex3f(7.45, 1.2, -0.5);
glTexCoord2f(1, 1); glVertex3f(7.45, 1.2, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(7.3, 1.05, 0);
glTexCoord2f(0, 1); glVertex3f(7.3, 1.05, -0.5);
glTexCoord2f(1, 0); glVertex3f(7, 0.6, -0.5);
glTexCoord2f(1, 1); glVertex3f(7, 0.6, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(5.05, 0.45, 0);
glTexCoord2f(0, 1); glVertex3f(5.05, 0.45, -0.5);
glTexCoord2f(1, 0); glVertex3f(4.75, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(4.75, 0, 0);
glEnd(); }

//слева блоки
// верх
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, 0);
glTexCoord2f(0, 1); glVertex3f(-6.2, 1.65, -0.5);
glTexCoord2f(1, 0); glVertex3f(-1.7, 1.65, -0.5);
glTexCoord2f(1, 1); glVertex3f(-1.7, 1.65, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-5.75, 1.05, 0);
glTexCoord2f(0, 1); glVertex3f(-5.75, 1.05, -0.5);
glTexCoord2f(1, 0); glVertex3f(-2, 1.05, -0.5);
glTexCoord2f(1, 1); glVertex3f(-2, 1.05, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, 0);
glTexCoord2f(0, 1); glVertex3f(-3.5, 0.45, -0.5);
glTexCoord2f(1, 0); glVertex3f(-2, 0.45, -0.5);
glTexCoord2f(1, 1); glVertex3f(-2, 0.45, 0);
glEnd(); }
// низ
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); (-2, 1.2, 0);
glTexCoord2f(0, 1); glVertex3f(-2, 1.2, -0.5);
glTexCoord2f(1, 0); glVertex3f(-5.9, 1.2, -0.5);
glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-2, 0.6, 0);
glTexCoord2f(0, 1); glVertex3f(-2, 0.6, -0.5);
glTexCoord2f(1, 0); glVertex3f(-5.45, 0.6, -0.5);
glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.7, 0, 0);
glTexCoord2f(0, 1); glVertex3f(-1.7, 0, -0.5);
glTexCoord2f(1, 0); glVertex3f(-3.2, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(-3.2, 0, 0);
glEnd(); }
// передняя стенка
{glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, 0);
glTexCoord2f(0, 1); glVertex3f(-1.7, 1.65, 0);
glTexCoord2f(1, 0); glVertex3f(-2, 1.2, 0);
glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, 0);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); (-5.75, 1.05, 0);
glTexCoord2f(0, 1); (-2, 1.05, 0);
glTexCoord2f(1, 0); glVertex3f(-2, 0.6, 0);
glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, 0);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, 1);
glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, 0);
glTexCoord2f(0, 1); glVertex3f(-2, 0.45, 0);
glTexCoord2f(1, 0); glVertex3f(-1.7, 0, 0);
glTexCoord2f(1, 1); glVertex3f(-3.2, 0, 0);
glEnd(); }
// задняя стенка
{glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, -0.5);
glTexCoord2f(0, 1); glVertex3f(-1.7, 1.65, -0.5);
glTexCoord2f(1, 0); glVertex3f(-2, 1.2, -0.5);
glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, -0.5);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(-5.75, 1.05, -0.5);
glTexCoord2f(0, 1); glVertex3f(-2, 1.05, -0.5);
glTexCoord2f(1, 0); glVertex3f(-2, 0.6, -0.5);
glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, -0.5);
glEnd();
glBegin(GL_POLYGON);
glNormal3f(0, 0, -1);
glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, -0.5);
glTexCoord2f(0, 1); glVertex3f(-2, 0.45, -0.5);
glTexCoord2f(1, 0); glVertex3f(-1.7, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(-3.2, 0, -0.5);
glEnd(); }
// правая стенка
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.7, 1.65, -0.5);
glTexCoord2f(0, 1); glVertex3f(-1.7, 1.65, 0);
glTexCoord2f(1, 0); glVertex3f(-2, 1.2, 0);
glTexCoord2f(1, 1); glVertex3f(-2, 1.2, -0.5);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-2, 1.05, -0.5);
glTexCoord2f(0, 1); glVertex3f(-2, 1.05, 0);
glTexCoord2f(1, 0); (-2, 0.6, 0);
glTexCoord2f(1, 1); glVertex3f(-2, 0.6, -0.5);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-1.7, 0, 0);
glTexCoord2f(0, 1); glVertex3f(-1.7, 0, -0.5);
glTexCoord2f(1, 0); glVertex3f(-2, 0.45, -0.5);
glTexCoord2f(1, 1); glVertex3f(-2, 0.45, 0);
glEnd(); }
// левая стенка
{glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-6.2, 1.65, 0);
glTexCoord2f(0, 1); glVertex3f(-6.2, 1.65, -0.5);
glTexCoord2f(1, 0); glVertex3f(-5.9, 1.2, -0.5);
glTexCoord2f(1, 1); glVertex3f(-5.9, 1.2, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-5.75, 1.05, 0);
glTexCoord2f(0, 1); glVertex3f(-5.75, 1.05, -0.5);
glTexCoord2f(1, 0); glVertex3f(-5.45, 0.6, -0.5);
glTexCoord2f(1, 1); glVertex3f(-5.45, 0.6, 0);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0, 0); glVertex3f(-3.5, 0.45, 0);
glTexCoord2f(0, 1); glVertex3f(-3.5, 0.45, -0.5);
glTexCoord2f(1, 0); glVertex3f(-3.2, 0, -0.5);
glTexCoord2f(1, 1); glVertex3f(-3.2, 0, 0);
glEnd(); }