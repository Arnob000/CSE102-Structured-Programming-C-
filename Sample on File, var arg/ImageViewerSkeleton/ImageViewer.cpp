/*
	author: M Saifur Rahman
	last modified: December 12, 2020
*/
# include "iGraphics.h"

typedef struct _Image {
    int width;
    int height;
    int *rgPixels;
} Image;

Image g_image;

int pic_x, pic_y, image_index, g_imageIndex;
int g_screenHeight, g_screenWidth;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	iClear();
	if (g_image.rgPixels != NULL) {
        glRasterPos2f(pic_x, pic_y);
        glDrawPixels(g_image.width, g_image.height, GL_RGBA, GL_UNSIGNED_BYTE, g_image.rgPixels);
	} else {
	    iText(0, 0, "Image loading failed.");
	}
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}

	if (key >= '0' && key <= '9') {
        g_imageIndex = key - '0';
	}

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_LEFT)
	{
		pic_x--;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		pic_x++;
	}
	if(key == GLUT_KEY_UP)
	{
		pic_y++;
	}
	if(key == GLUT_KEY_DOWN)
	{
		pic_y--;
	}
	//place your codes for other keys here
}

void getImage(
    char *pstrFileName,
    int index,
    Image *pImage
    )
{
}

int main()
{

	//place your own initialization codes here.
	pic_x = 0;
	pic_y = 140;

    RECT rect;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
    g_screenWidth = rect.right - rect.left - 20;
    g_screenHeight = rect.bottom - rect.top - 35;

    getImage("image.dat", g_imageIndex, &g_image);

	iInitialize(g_screenWidth, g_screenHeight, "ImageViewer");

	return 0;
}
