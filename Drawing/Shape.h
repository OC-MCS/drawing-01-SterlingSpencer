#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct Record
{
	int color;
	ShapeEnum shape;
	Vector2f shapePos;
};

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
	private:

	public:
		virtual void draw(RenderWindow&)=0;
		virtual Record getFileRecord()=0;
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle : public DrawingShape
{
	private:
		CircleShape circle;
	public:
//================================================
// Purpose:The constructor that contains and gets information about the circle
// Parameters:It is passed the position and color of the circle
// Return:No Return
//================================================
		Circle(Vector2f circlePosition,Color circleColor)
		{
			circle.setPosition(circlePosition);
			circle.setRadius(10);
			circle.setOutlineThickness(2);
			circle.setOutlineColor(circleColor);
			circle.setFillColor(circleColor);
		}

//================================================
// Purpose:It draws the circle
// Parameters:It is passed the window information
// Return:No return
//================================================
		void draw(RenderWindow &win)
		{
			win.draw(circle);
		}

//================================================
// Purpose:Initializes the Record read and returns it
// Parameters:No parameters
// Return:It returns the Record read
//================================================
		Record getFileRecord()
		{
			Record read{ circle.getFillColor().toInteger(), CIRCLE, circle.getPosition() };
			return read;
		}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;
public:
//================================================
// Purpose:The constructor that contains and gets information about the square
// Parameters:It is passed the position and color of the square
// Return:No Return
//================================================
	Square(Vector2f squarePosition, Color squareColor)
	{
		square.setPosition(squarePosition);
		square.setOutlineColor(squareColor);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(20, 20));
		square.setFillColor(squareColor);
	}

//================================================
// Purpose:It draws the square
// Parameters:It is passed the window information
// Return:No return
//================================================
	void draw(RenderWindow &win)
	{
		win.draw(square);
	}

//================================================
// Purpose:Initializes the Record read and returns it
// Parameters:No parameters
// Return:It returns the Record read
//================================================
	Record getFileRecord()
	{
		Record read{ square.getFillColor().toInteger(), SQUARE, square.getPosition() };
		return read;
	}
};



