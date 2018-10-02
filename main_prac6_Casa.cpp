//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumna: Heredia Córdova Tania Rocío*********************************//
//*************	Practica 6						******//
//*************	Visual Studio 2017									******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int centro_atomo=0;
int part_h1 = 0;
int part_h2 = 0;
int part_h3= 0;
int part_v1 = 0;
int part_v2 = 0;
int part_v3 = 0;
int part_id1 = 0;
int part_id2 = 0;
int part_id3 = 0;
int part_ii1 = 0;
int part_ii2 = 0;
int part_ii3 = 0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara

	glPushMatrix();//Atomo
		
		glPushMatrix();
			glRotatef(centro_atomo, 0.0, 1.0, 0.0);	//El centro gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//centro amarillo
			glutSolidSphere(1.9,12,12);  //Draw atomo (radio,H,V);
		glPopMatrix();
		glPushMatrix();//part_horizontal
			glRotatef(centro_atomo * 2, 0, 1, 0);//traslacion
			glTranslatef(7.8,0,0);
			glRotatef(part_h1,0,1,0);//rotación
			glColor3f(0.5,0.5,0.5);
			glutSolidSphere(0.3, 8, 8);
		glPopMatrix();
		glPushMatrix();//part_horizontal2
			glRotatef(centro_atomo * 1.3, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_h2, 0, 1, 0);//rotación
			glColor3f(0.5, 0.6, 0.3);
			glutSolidSphere(0.7, 8, 8);
		glPopMatrix();
		glPushMatrix();//part_horizontal3
			glRotatef(centro_atomo * 2.2, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_h3, 0, 1, 0);//rotación
			glColor3f(1, 0.0, 0.0);
			glutSolidSphere(0.4, 8, 8);
		glPopMatrix();
		glPushMatrix();//vertical
			glRotatef(90, 0, 0, 1);
			glRotatef(centro_atomo * 1.2, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_v1, 0, 1, 0);//rotación
			glColor3f(0.4, 0.5, 0.8);
			glutSolidSphere(0.3, 8, 8);
		glPopMatrix();
		glPushMatrix();//part_vetical2
			glRotatef(90, 0, 0, 1);
			glRotatef(centro_atomo * 1.7, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_v2, 0, 1, 0);//rotación
			glColor3f(1, 0.3, 0.7);
			glutSolidSphere(0.7, 8, 8);
		glPopMatrix();
		glPushMatrix();//part_vertical3
		glRotatef(90,0,0,1);
			glRotatef(centro_atomo * 2.5, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_v3, 0, 1, 0);//rotación
			glColor3f(0.5, 1, 0.8);
			glutSolidSphere(0.4, 8, 8);
		glPopMatrix();
		glPushMatrix();//45° izq
			glRotatef(90, 1, 0, 1);
			glRotatef(centro_atomo * 0.7, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_ii1, 0, 1, 0);//rotación
			glColor3f(0.6, 0.4, 0.2);
			glutSolidSphere(0.3, 8, 8);
		glPopMatrix();
		glPushMatrix();//45° izq2
			glRotatef(90, 1, 0, 1);
			glRotatef(centro_atomo * 1.5, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_ii2, 0, 1, 0);//rotación
			glColor3f(0.7, 1, 0.3);
			glutSolidSphere(0.7, 8, 8);
		glPopMatrix();
		glPushMatrix();//45° izq3
			glRotatef(90, 1, 0, 1);
			glRotatef(centro_atomo * 1.1, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_ii3, 0, 1, 0);//rotación
			glColor3f(0.5, 1, 0);
			glutSolidSphere(0.4, 8, 8);
		glPopMatrix();
		glPushMatrix();//45° der
			glRotatef(270, 1, 0, 1);
			glRotatef(centro_atomo * 2.4, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_id1, 0, 1, 0);//rotación
			glColor3f(0.6, 0.3, 0.7);
			glutSolidSphere(0.3, 8, 8);
		glPopMatrix();
		glPushMatrix();//45° der2
			glRotatef(270, 1, 0, 1);
			glRotatef(centro_atomo * 2.7, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_id2, 0, 1, 0);//rotación
			glColor3f(0.7, 0.8, 0.9);
			glutSolidSphere(0.7, 8, 8);
		glPopMatrix();
			glPushMatrix();//45° der3
			glRotatef(270, 1, 0, 1);
			glRotatef(centro_atomo * 1.9, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(part_id3, 0, 1, 0);//rotación
			glColor3f(0.3, 0.4, 0.5);
			glutSolidSphere(0.4, 8, 8);
		glPopMatrix();
		
	glPopMatrix();
	
	
	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		centro_atomo = (centro_atomo - 1) % 360;
		part_h1 = (part_h1 - 1) % 360;
		part_h2 = (part_h2 - 1) % 360;
		part_h3 = (part_h3 - 1) % 360;
		part_v1 = (part_v1 - 1) % 360;
		part_v2 = (part_v2 - 1) % 360;
		part_v3 = (part_v3 - 1) % 360;
		part_id1 = (part_id1 - 1) % 360;
		part_id2 = (part_id2 - 1) % 360;
		part_id3 = (part_id3 - 1) % 360;
		part_ii1 = (part_ii1 - 1) % 360;
		part_ii2 = (part_ii2 - 1) % 360;
		part_ii3 = (part_ii3 - 1) % 360;

		
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}