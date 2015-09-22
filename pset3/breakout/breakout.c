//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    double velocity_x = drand48()+1;
    double velocity_y = drand48()+1;
    // keep playing until game over
    waitForClick();
    while (lives > 0 && bricks > 0)
    {
        // TODO
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        move(ball,velocity_x,velocity_y);
        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure circle follows top cursor
                double x = getX(event) - getWidth(paddle);
                if(x > 0)
                {
                   setLocation(paddle, x, 500);
                }
            }
        }
       GObject object = detectCollision(window,ball);
       if(object != NULL)
       {
            if(object == paddle)
            {
                    //velocity_y = -velocity_y;
                    velocity_y = -drand48()-2;
                    
            }
            else if(strcmp(getType(object), "GRect") == 0)
            {
                //velocity_y = (-velocity_y+drand48());
                velocity_y = drand48()+2;
                removeGWindow(window, object);
                points++;
                bricks--;
                updateScoreboard( window,  label,  points);
            }
       }

       if(getY(ball)+RADIUS*2 >= HEIGHT )
       {
           if(lives > 1)
           {
                waitForClick();    
                lives -= 1;
                setLocation(ball, WIDTH/2 - RADIUS, HEIGHT/2 - RADIUS);
           }
           else
           {
                lives -= 1;
           }
     
       }
       else if(getY(ball) <= 0)
       {
           velocity_y = -velocity_y;
                
       }
       if(((getX(ball) + getWidth(ball)) >= WIDTH) || (getX(ball) <= 0) )
       {
           velocity_x = -velocity_x;
                
       }
       pause(5);
           
  }
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    int X = 5;
    int Y = 30;
    string color[5] = {"RED","BLUE","YELLOW","PINK","GREEN"};
    for(int i = 0; i < ROWS; i++)
    {   
        
        for(int j = 0; j < COLS; j++)
        {
            GRect Bricks = newGRect(X, Y, 30, 10);
            setFilled(Bricks, true);
            setColor(Bricks, color[i]);
            add(window, Bricks);
            X += 40; 
        }
        X = 5;
        Y +=20;
    }
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval Ball = newGOval(WIDTH/2 - RADIUS, HEIGHT/2 - RADIUS, 20, 20);
    setFilled(Ball, true);
    setColor(Ball, "BLACK");
    add(window, Ball);
    return Ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect(WIDTH/2 - 30, 500, 60, 10);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-72");
    setColor(label, "GRAY");
    add(window, label);
    setLabel(label, "0");
    setLocation(label, 175, 200);
    return label;    
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    int x = getX(ball);
    int y = getY(ball);
    
    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    
    return NULL;
}
