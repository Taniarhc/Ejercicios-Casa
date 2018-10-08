//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumna: Heredia Córdova Tania Rocío*********************************//
//*************	Practica 7					******//
//*************	Visual Studio 2017									******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int luna1t = 0;
int luna1m = 0;
int luna2m = 0;
int luna1j = 0;
int luna2j = 0;
int luna3j = 0;
int anillos1 = 0;
int anillos2 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat LuzAmbientalSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };			
GLfloat LuzDifusaSol[] = { 1.0, 0.0, 0.0, 1.0 };				
GLfloat LuzEspecularSol[] = { 0.0f, 0.0f, 1.0f, 1.0f };	
GLfloat LuzPosicionSol[]= { 0.0f, 0.0f, 0.0f, 1.0f };

GLfloat MercurioDiffuse[] = { 0.07568f, 0.61424f, 0.07568f, 1.0f };			// Marte
GLfloat MercurioAmbiental[] = { 0.0215f, 0.1745f, 0.0215f, 1.0f };
GLfloat MercurioSpecular[] = { 0.633, 0.727811, 0.633, 1.0 };
GLfloat MercurioShininess[] = { 0.6 };

GLfloat VenusDiffuse[] = { 0.18275f, 0.17f, 0.22525f, 1.0f };			// venus
GLfloat VenusAmbiental[] = { 0.05375f, 0.05f, 0.06625f, 1.0f };
GLfloat VenusSpecular[] = { 0.332741, 0.328634, 0.346435, 1.0 };
GLfloat VenusShininess[] = { 0.3 };


GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthAmbiental[] = { 0.05375f, 0.05f, 0.06625f, 1.0f };
GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };


GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonAmbiental[] = { 0.23125f, 0.23125f, 0.23125f, 1.0f };
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.61424f, 0.04136f, 0.04136f, 1.0f };			// Marte
GLfloat MarsAmbiental[] = { 0.1745f, 0.01175f, 0.01175f, 1.0f };
GLfloat MarsSpecular[] = { 0.727811, 0.626959, 0.626959, 1.0 };
GLfloat MarsShininess[] = { 0.6 };

GLfloat LM1ambient[] = { 0.25f, 0.20725f, 0.20725f, 0.922f };  //luna1marte
GLfloat LM1diffuse[] = { 1.0f, 0.829f, 0.829f, 0.922f };
GLfloat LM1specular[] = { 0.296648f, 0.296648f, 0.296648f, 0.922f };
GLfloat LM1shininess[] = { 11.264f };

GLfloat LM2ambient[] = { 0.0f,0.0f,0.0f,1.0f };// LUNA2MARTE
GLfloat LM2diffuse[] = { 0.5f,0.5f,0.0f,1.0f };
GLfloat LM2specular[] = { 0.60f,0.60f,0.50f,1.0f };
GLfloat LM2shininess[] = { 32.0f };

GLfloat Jupiterambiental[] = { 0.1f, 0.18725f, 0.1745f, 0.8f };   //Jupiter
GLfloat Jupiterdiffuse[] = { 0.396f, 0.74151f, 0.69102f, 0.8f };
GLfloat Jupiterspecular[] = { 0.297254f, 0.30829f, 0.306678f, 0.8f };
GLfloat Jupitershininess[] = { 12.8f };

GLfloat LJ1ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };  //LUNA1JUPITER
GLfloat LJ1diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
GLfloat LJ1specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
GLfloat LJ1shininess[] = { 27.8974f };

GLfloat LJ2ambient[] = { 0.2125f, 0.1275f, 0.054f, 1.0f }; //LUNA2JUPITER
GLfloat LJ2diffuse[] = { 0.714f, 0.4284f, 0.18144f, 1.0f };
GLfloat LJ2specular[] = { 0.393548f, 0.271906f, 0.166721f, 1.0f };
GLfloat LJ2shininess[] = {25.6f};

GLfloat LJ3ambient[] = { 0.25f, 0.25f, 0.25f, 1.0f }; //LUNA3JUPITER
GLfloat LJ3diffuse[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat LJ3specular[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
GLfloat LJ3shininess[] = { 76.8f };

GLfloat Saturnoambient[] = { 0.0f,0.1f,0.06f ,1.0f }; //saturno
GLfloat Saturnodiffuse[] = { 0.0f,0.50980392f,0.50980392f,1.0f };
GLfloat Saturnospecular[] = { 0.50196078f,0.50196078f,0.50196078f,1.0f };
GLfloat Saturnoshininess[] = {32.0f};

GLfloat AS1ambient[] = { 0.0f,0.0f,0.0f,1.0f };//anillo1s
GLfloat AS1diffuse[] = { 0.5f,0.0f,0.0f,1.0f };
GLfloat AS1specular[] = { 0.7f,0.6f,0.6f,1.0f };
GLfloat AS1shininess[] = { 32.0f };

GLfloat AS2ambient[] = { 0.105882f, 0.058824f, 0.113725f, 1.0f };//anillo2s
GLfloat AS2diffuse[] = { 0.427451f, 0.470588f, 0.541176f, 1.0f };
GLfloat AS2specular[] = { 0.333333f, 0.333333f, 0.521569f, 1.0f };
GLfloat AS2shininess[] = { 9.84615f };

GLfloat Uranoambient[] = { 0.05f,0.05f,0.0f,1.0f };//urano
GLfloat Uranodiffuse[] = { 0.5f,0.5f,0.4f,1.0f };
GLfloat Uranospecular[] = { 0.7f,0.7f,0.04f,1.0f };
GLfloat Uranoshininess[] = {10.0f};


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LuzAmbientalSol);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LuzDifusaSol);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LuzEspecularSol);				// Setup The Diffuse Light

	glEnable(GL_LIGHT1);							// Enable Light One

}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol);
	glEnable(GL_LIGHTING);

	glPushMatrix();//Sistema solar	

	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//Mercurio
	glRotatef(sol * 2, 0, 1, 0);//traslacion
	glTranslatef(3.2, 0, 0);
	glRotatef(mercurio, 0, 1, 0);//rotación
	glColor3f(0.5, 0.5, 0.5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MercurioAmbiental);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS,MercurioShininess);
	glutSolidSphere(0.3, 8, 8);
	glPopMatrix();
	glPushMatrix();//Venus
	glRotatef(sol * 1.5, 0, 1, 0);//traslacion
	glTranslatef(4.7, 0, 0);
	glRotatef(venus, 0, 1, 0);//rotación
	glColor3f(0.8, 0.4, 0.2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, VenusAmbiental);
	glMaterialfv(GL_FRONT, GL_SPECULAR,VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
	glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
	glPushMatrix();//tierra
	glRotatef(sol * 1.3, 0, 1, 0);//traslacion
	glTranslatef(6.4, 0, 0);
	glRotatef(tierra, 0, 1, 0);//rotación
	glColor3f(0.5, 0.6, 0.3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, EarthAmbiental);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(0.7, 8, 8);
	glPushMatrix();//Luna1T
	glRotatef(tierra * 0.6, 0, 1, 0);//traslacion
	glTranslatef(1.5, 0, 0);
	glRotatef(luna1t, 0, 1, 0);//rotación
	glColor3f(0.5, 0.7, 0.7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MoonAmbiental);
	glMaterialfv(GL_FRONT, GL_SPECULAR,MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.15, 8, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//marte
	glRotatef(sol * 2.2, 0, 1, 0);//traslacion
	glTranslatef(7.8, 0, 0);
	glRotatef(marte, 0, 1, 0);//rotación
	glColor3f(1, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MarsAmbiental);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutSolidSphere(0.4, 8, 8);
	glPushMatrix();//Luna1M
	glRotatef(marte * 1.5, 0, 1, 0);//traslacion
	glTranslatef(1.3, 0, 0);
	glRotatef(luna1m, 0, 1, 0);//rotación
	glColor3f(0.6, 0.7, 0.6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LM1diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, LM1ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LM1specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, LM1shininess);
	glutSolidSphere(0.2, 8, 8);
	glPopMatrix();
	glPushMatrix();//Luna2M
	glRotatef(marte * 1.1, 0, 1, 0);//traslacion
	glTranslatef(1.2, 0, 0);
	glRotatef(luna2m, 0, 1, 0);//rotación
	glColor3f(0.6, 0.5, 0.6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LM2diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, LM2ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LM2specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, LM2shininess);
	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//jupiter
	glRotatef(sol * 1.7, 0, 1, 0);//traslacion
	glTranslatef(9.8, 0, 0);
	glRotatef(jupiter, 0, 1, 0);//rotación
	glColor3f(0.7, 0.8, 0.9);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Jupiterdiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Jupiterambiental);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Jupiterspecular);
	glMaterialfv(GL_FRONT, GL_SHININESS,Jupitershininess);
	glutSolidSphere(1, 8, 8);
	glPushMatrix();//Luna1j
	glRotatef(jupiter * 1.5, 0, 1, 0);//traslacion
	glTranslatef(1.1, 0, 0);
	glRotatef(luna1j, 0, 1, 0);//rotación
	glColor3f(0.4, 0.5, 0.6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,LJ1diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT,LJ1ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LJ1specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, LJ1shininess);
	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
	glPushMatrix();//Luna2j
	glRotatef(jupiter * 1.7, 0, 1, 0);//traslacion
	glTranslatef(1.4, 0, 0);
	glRotatef(luna2j, 0, 1, 0);//rotación
	glColor3f(0.4, 0.5, 0.8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LJ2diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, LJ2ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LJ2specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, LJ2shininess);
	glutSolidSphere(0.3, 8, 8);
	glPopMatrix();
	glPushMatrix();//Luna3j
	glRotatef(jupiter * 1.2, 0, 1, 0);//traslacion
	glTranslatef(1.6, 0, 0);
	glRotatef(luna3j, 0, 1, 0);//rotación
	glColor3f(0.5, 0.2, 0.8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LJ3diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, LJ3ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LJ3specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, LJ3shininess);
	glutSolidSphere(0.2, 8, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//saturno
	glRotatef(sol * 0.8, 0, 1, 0);//traslacion
	glTranslatef(11.7, 0, 0);
	glRotatef(saturno, 0, 1, 0);//rotación
	glColor3f(0.9, 1.0, 0.9);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Saturnodiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Saturnoambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Saturnospecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Saturnoshininess);
	glutSolidSphere(0.9, 8, 8);
	glPushMatrix();//saturno
	glRotatef(anillos1, 0, 1, 0);//rotación
	glColor3f(0.6, 0.8, 0.3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,AS1diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, AS1ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, AS1specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, AS1shininess);
	glRotatef(60, 1, 0, 0);
	glScalef(1, 0.1, 1);
	glutSolidTorus(1.2, 0.2,10, 10);
	glPopMatrix();
	glPushMatrix();//saturno
	glRotatef(anillos2, 0, 1, 0);//rotación
	glColor3f(0.8, 0.8, 0.5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, AS2diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, AS2ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, AS2specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, AS2shininess);
	glRotatef(60, 1, 0, 0);
	glScalef(1, 0.1, 1);
	glutSolidTorus(1.6, 0.2,10, 10);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//urano
	glRotatef(sol * 2.5, 0, 1, 0);//traslacion
	glTranslatef(13.5, 0, 0);
	glRotatef(urano, 0, 1, 0);//rotación
	glColor3f(0.3, 0.9, 1.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,Uranodiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Uranoambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR,Uranospecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Uranoshininess);
	glutSolidSphere(0.8, 8, 8);
	glPopMatrix();
	glPopMatrix();


	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;
		mercurio = (mercurio - 1) % 360;
		venus = (venus - 1) % 360;
		tierra = (tierra - 1) % 360;
		marte = (marte - 1) % 360;
		jupiter = (jupiter - 1) % 360;
		saturno = (saturno - 1) % 360;
		urano = (urano - 1) % 360;
		luna1t = (luna1t - 1) % 360;
		luna1m = (luna1m - 1) % 360;
		luna2m = (luna2m - 1) % 360;
		luna1j = (luna1j - 1) % 360;
		luna2j = (luna2j - 1) % 360;
		luna3j = (luna3j - 1) % 360;
		anillos1 = (anillos1 - 1) % 360;
		anillos2 = (anillos2 - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
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
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
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


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 7"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}