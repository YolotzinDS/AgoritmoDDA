 #include <conio.h>
#include <windows.h>
#include <C:\Users\YOLO\Documents\Zamora Dev. C++\Dev-Cpp\include\GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>



using namespace std;

//definimos la svariables parra usar elm algoritmo dda
	int x_1, y_1, x_2, y_2, Pasos;
	int dy, dx;

		int steps = 0;
		float xinc, yinc;
		float Pendiente;
		//display, funcion que crea la imagen
		//descricpion geometrica de la imagen se va us
	void algoritmoDDA()//contiene
		{
			//delta
			dy = y_2 - y_1;
			dx = x_2 - x_1;


    //if()
		//Pnediente de la recta
	
	Pendiente = (dy * 1.0) / (dx * 1.0);

		//  Numero de pasos
		Pasos = max(dy, dx);
		glClear(GL_COLOR_BUFFER_BIT); //Con esta funcion el color de la ventana
		glColor3f(1,1,1);//Establecer color de objeto
		glLoadIdentity();
		//Plano Cartesiano
		glLineWidth(5.0);
		glColor3f(0.0471,  0.7176, 0.949); // blue
		glBegin(GL_LINES);
		glVertex2d(-20, 0);
        glVertex2d(20, 0);
	    glVertex2d(0, 20);
        glVertex2d(0, -20);
			glEnd();
  //cruce
  glLineWidth (2.0);
  glColor3f(4, 2, 0);
  glBegin(GL_LINES);

        for(int j = 21; j > -20; j--){ //Lineas horizontales
            glVertex2f(-20, j + 0.5);
            glVertex2f(20, j + 0.5);
		}
		for(int j = 21; j > -20; j--)//Lineas verticales
		{
         glVertex2f( j + 0.5 , -20);
            glVertex2f( j + 0.5, 20);

			}
		glEnd();
		glPointSize(18); //Se define el tamaño del pixel dependera de que tañaño lo quiera
		glBegin(GL_POINTS); //prin grefica
		        glColor3f(1.0, 1.0, 0.0);
		        glColor3f(1, 0, 1);
        	if(dx > dy){
			steps = dx;
		}else{
				steps = dy;
		}

			xinc = dx/ steps;
			yinc = dy/ steps;
	    	float xi = x_1 * 1.0;
	        float yi = y_1 * 1.0;

		for(int i = 1; i <= steps ; i++){
				glVertex2d(xi, round(yi)); //funcion opgl
				float x1 = x_1 + xinc;
        		float y1 = y_1 + yinc;
               	xi++;
				yi = yi + Pendiente;
			}

     //printf( " %f\n", x1 );
	//		    printf("x1 = %f", x1);
			    
 glEnd();

        glLineWidth(0.000001);
           glVertex2d(x_1 * 1.0, y_1 * 1.0);
            glVertex2d(x_2 * 1.0, y_2 * 1.0);

		glEnd();//Elemento paa que no se cierre la ventana
        		

		glFlush(); //
			}
		void Init(){
			glClearColor(1, 1,1, 0); //Color de pantalla de la 2da vengtana
		}

		void reshape(int width, int height)
		{
			glViewport(0, 0, width, height);
			glMatrixMode(GL_PROJECTION);//Tipo de proyeccion
			glLoadIdentity(); //Asigna nr la matriz identidad como de proyecto
			glOrtho (-20, 20, -20, 20, -1, 1);//SSe debe de usar una proyeccion
			glMatrixMode(GL_MODELVIEW);
			  }

		int main(int argc, char * argv[]){
               system ("color ce"); //COLOR PANT
  //  Capturara los datos para la graf.
		cout << "HOLA favor de ingresar los valores correspondientes :) " << endl ;
		cout << "Ingrese X1: " ; cin >> x_1;
		cout << "Ingrese Y1: " ; cin >> y_1;
		cout << "Ingrese X2: " ; cin >> x_2;
		cout << "Ingrese Y2: " ; cin >> y_2;

		glutInit(&argc, argv); //Realizar inclinacion
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//numero
		glutInitWindowSize(800, 800);//va ser cundo se va a  establecer la altura y la anchura del pixel
		glutCreateWindow("Algoritmo DDA"); //se gegnerara una 2da ventana de visualizacion
		Init();//p.init
		glutDisplayFunc(algoritmoDDA);//signa img.
		glutReshapeFunc(reshape);//Cambio de tamaño de la ventana actual
		glutMainLoop();//Con esta funcion las ventanas  que hayan creado

		return 0;
}



