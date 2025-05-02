# include "iGraphics.h"
# include "gl.h"
# include <math.h>

#define PI acos(0)

double ball_x=0, ball_y;

//increment/decrement
double dx=1;
double da=0,db=0;

int mode=1;
int help=0;
int ball1=0,ball2=0,ball3=0,ball4=0;

//phase
int phase=0;

void drawCurves(int a,int b,int c,int m,int ball,int ph);
void ballChange();
void drawSum(int m,int ball,int a1,int b1,int c1,int ph1,int a2,int b2,int c2,int ph2,int a3,int b3,int c3,int ph3);

void drawCurves(int a,int b,int c,int m,int ball,int ph)
{

    float i;
    float y;


    if(m)
    {
        for(i=0; i<=1350; i=i+.1)
        {
            if(c)
            {
                y=350+30*(a+da)*sin((b+db)*i*PI/180+ph*PI);

            }

            else
            {
                y=350+30*(a+da)*cos((b+db)*i*PI/180+ph*PI);

            }

            iSetColor(255,255,255);
            iPoint(i, y);                    //draw curves
        }

    }


    if(c)
    {
        ball_y=350+30*(a+da)*sin((b+db)*ball_x*PI/180+ph*PI);

    }

    else
    {
        ball_y=350+30*(a+da)*cos((b+db)*ball_x*PI/180+ph*PI);
    }

    if(ball)
    {
        iSetColor(255*ball,100*ball,50*ball);
        iFilledCircle(ball_x,ball_y,7);               //draw ball
    }

}

void drawSum(int m,int ball,int a1,int b1,int c1,int ph1,int a2,int b2,int c2,int ph2,int a3,int b3,int c3,int ph3)
{

    float i;
    float y,y1,y2,y3;


    if(m)
    {
        for(i=0; i<=1350; i=i+.1)
        {
            if(c1)
            {
                y1=30*(a1+da)*sin((b1+db)*i*PI/180+ph1*PI);

            }

            else if(!c1)
            {
                y1=30*(a1+da)*cos((b1+db)*i*PI/180+ph1*PI);

            }

            if(c2)
            {
                y2=30*(a2+da)*sin((b2+db)*i*PI/180+ph2*PI);

            }

            else if(!c2)
            {
                y2=30*(a2+da)*cos((b2+db)*i*PI/180+ph2*PI);

            }

            if(c3)
            {
                y3=30*(a3+da)*sin((b3+db)*i*PI/180+ph3*PI);

            }

            else if(!c3)
            {
                y3=30*(a3+da)*cos((b3+db)*i*PI/180+ph3*PI);

            }

            y=350+y1+y2+y3;                    //sum of curves

            iSetColor(255,255,255);
            iPoint(i, y);                    //draw sum
        }

    }

    float ball_y1=0,ball_y2=0,ball_y3=0;

    if(c1)
    {
        ball_y1=30*(a1+da)*sin((b1+db)*ball_x*PI/180+ph1*PI);

    }

    else if(!c1)
    {
        ball_y1=30*(a1+da)*cos((b1+db)*ball_x*PI/180+ph1*PI);
    }


    if(c2)
    {
        ball_y2=30*(a2+da)*sin((b2+db)*ball_x*PI/180+ph2*PI);

    }

    else if(!c2)
    {
        ball_y2=30*(a2+da)*cos((b2+db)*ball_x*PI/180+ph2*PI);
    }

    if(c3)
    {
        ball_y3=30*(a3+da)*sin((b3+db)*ball_x*PI/180+ph3*PI);

    }

    else if(!c3)
    {
        ball_y3=30*(a3+da)*cos((b3+db)*ball_x*PI/180+ph3*PI);
    }

    if(ball)
    {
        ball_y=350+ball_y1+ball_y2+ball_y3;
        iSetColor(0,255,0);
        iFilledCircle(ball_x,ball_y,7);                //draw ball
    }

}



void iDraw()
{
    iClear();

    if(help)
    {
        iShowBMP(0,0,"help.bmp");         //Help menu

        iSetColor(0, 0, 0);
        iText(40, 650, "Toggle Help/Main Page: press F1");
        iText(40, 630, "Toggle Curve Show/Hide: press s/S");
        iText(40, 610, "Toggle Tracer Show/Hide:<Curve No 1,2,3,Sum=4>");
        iText(40, 590, "Pause Animation: p/P");
        iText(40, 570, "Resume Animation: r/R");
        iText(40, 550, "Increase Amplitude: a");
        iText(40, 530, "Decrease Amplitude: A");
        iText(40, 510, "Increase Frequency: f");
        iText(40, 490, "Decrease Frequency: F");
        iText(40, 470, "Increase Speed: +");
        iText(40, 450, "Decrease Speed: -");
        iText(40, 430, "Exit: END");
        iText(40, 400, "Extra:");
        iText(60, 380, "Change Phase Angle: l/L");
        iText(60, 360, "Increase Amplitude & Frequency Simultaneously: Left Mouse Button");
        iText(60, 340, "Decrease Amplitude & Frequency Simultaneously: Right Mouse Button");

    }

    if(!help)
    {
        if(mode)
        {
            iSetColor(255,255,255);
            iLine(0,350,1350,350);                      //vertical line
        }

                                                        //draw curves
        drawCurves(1,2,1,mode,ball1*1,phase);

        drawCurves(1,2,0,mode,ball2*2,phase);

        drawCurves(2,4,1,mode,ball3*3,phase);

        drawSum(mode,ball4,1,2,1,phase,1,2,0,phase,2,4,1,phase);


        if(mode)
        {
            iSetColor(255, 255, 255);
            iText(10, 10, "Press p/P for pause, r/R for resume, END for exit.");
        }
    }
}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)     //Frequency & Amplitude
    {
        da+=.5;
        db+=.5;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        da-=.5;
        db-=.5;
    }
}

void iMouseMove(int mx, int my)
{
    //place your codes here
}


void iKeyboard(unsigned char key)
{
    if(key == 'p' || key == 'P')
    {
        iPauseTimer(0);
    }
    if(key == 'r' || key == 'R')
    {
        iResumeTimer(0);
    }
    if(key=='f')         //Frequency
    {
        db+=.1;
    }
    if(key=='F')
    {
        db-=.1;
    }
    if(key=='a')         //Amplitude
    {
        da+=.1;
    }
    if(key=='A')
    {
        da-=.1;
    }
    if(key=='s' || key=='S')
    {
        mode=!mode;
    }
    if(key == 'l'||key == 'L')  //Phase Angle
    {
        phase+=45;
    }
    if(key=='+')             //Speed
    {
        dx=1.5*dx;
    }
    if(key=='-')
    {
        dx=dx/1.5;
    }
    if(key=='1')            //Trace ball
    {
        ball1=!ball1;
    }
    if(key=='2')
    {
        ball2=!ball2;
    }
    if(key=='3')
    {
        ball3=!ball3;
    }
    if(key=='4')
    {
        ball4=!ball4;
    }

}


void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_F1)
    {
        help=!help;
    }

}

void ballChange()
{

    ball_x +=dx;

    if(ball_x > 1350 || ball_x < 0)
        dx = -dx;
}


int main()
{

    iSetTimer(200, ballChange);

    iInitialize(1350, 700, "1905108 Curves");

    return 0;
}

