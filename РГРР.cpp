// РГРР.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 
#include <glut.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#pragma comment (lib, "opengl32.lib")
#define REDISPLAYTIMERID 1

int g_c = 0;
void timerFunc(int nTimerID)
{
	switch (nTimerID)
	{
	case REDISPLAYTIMERID:
		g_c++;
		glutPostRedisplay();
		glutTimerFunc(100, timerFunc, REDISPLAYTIMERID);
		break;
	}
}

void Initialize()
{
	//Выбрать фоновый (очищающий) цвет
	glClearColor(0, 0, 0, 0);

	//Установить проекцию
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Отрисовка точек
	glColor3f(1.0, 1.0, 1.0); //Выбираем белый цвет
	glPointSize(6);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	for (int i = 0; i < 150; i += 1) {
		float x = (rand() % 100) / 100.0;
		float y = (rand() % 100) / 100.0;
		glVertex2f(x, y); //Координаты точки
	}
	glEnd();
	glFlush();
	//Отрисовка земли
	glColor3f(1.0, 1.0, 1.0); //Выбираем белый цвет
	glBegin(GL_QUADS);//рисуем квадрат
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.1);
	glVertex2f(1.0, 0.1);
	glVertex2f(1.0, 0.0);
	glEnd();// рисование окончено
	glFlush();//ускоряет работу освобождая буферы.
}

//Войти в главный цикл
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);		//Указываем размер окна
	glutInitWindowPosition(0, 0);	//Позиция окна
	glutCreateWindow("Polygon");		//Имя окна
	Initialize();						//Вызов функции Initialize
	glutDisplayFunc(Draw);
	glutTimerFunc(100, timerFunc, REDISPLAYTIMERID);
	/*glutTimerFunc(33, TimerFunction, 1);*/  //первый запуск таймера//Вызов функции отрисовки
	glutMainLoop();

	return 0;
}




//glClearColor(0, 0, 0, 1);  задаём цвет фона (красный,синий,зеленый)
//glColor3f(0,0,0) задаём цвет фона 
//glClear(GL_COLOR_BUFFER_BIT); очищаем фон
//glPushMatrix() сохраняет текущую матрицу в стек....крч нужна для вывода
//glRotatef(theta, 0.0f,0.0f,0.0f) угол + поворачивает вдоль осей x,y,z
//glBegin(GL_TRIANGLES) позволяет начать отрисвоку ТРЕУГОЛЬНИКА
	//glColor3f(0.0f,0.0f,0.0f) задаёт цвет точки
	//glVertex2f(0.0f, 0.0f) задаёт те самые точки треугольника x и y
//glEnd() рисование окончено
//glPopMatrix() выводит текующую матрицу из стека....крч нужна для вывода
//SwapBuffers(hDC) меняет местами буфер после рисования
//glBegin(GL_POINTS) позволяет начать отрисвоку ТОЧКИ
//glPointSize(10) размер точки
//glBegin(GL_LINES) точки парами будут соединены отрезками
//glLineWidth(10) толщина линии
//glBegin(GL_LINE_STRIP) соединены будут все точки кроме 1 и последней
//glBegin(GL_LINE_LOOP) соединяет ВСЕ ТОЧКИ
//glBegin(GL_TRIANGLE_FAN) все треугольники будут вместе склеены
//glLoadIdentity() матрица преобразований возвращает систему координат на место
//glTranslatef(0.5,0,0) смещает систему координат
//glScalef(0,0,0) изменяет матрицу преобразований и увеличивает систему координат
//glVertexPointer(2, GL_FLOAT, 0, &vertices) передаёт адрес массива 1) кол-во переменных на одну точку 2) тип 3) .. 4)адрес массива
//glEnable//(Disable)//ClientState(GL_VERTEX_ARRAY) включает и отключает массив 
//glDrawArrays(GL_TRIANGLES, 0, 3) рисует примитив по количеству заданных точек 2) с какой вершины начать 3) сколько всего
//Gluint - Беззнаковый целый тип
//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &index) рисует примитивы по заданному массиву 1)тип примитива 2)кол во точек 3)тип массива 4)указатель на массив
//

