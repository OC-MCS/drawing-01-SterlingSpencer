#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:
//================================================
// Purpose:No Purpose
// Parameters:No Parameters
// Return:No Return
//================================================
	ShapeMgr()
	{
		
	}

//================================================
// Purpose:It determines if a circle or square was chosen
// Parameters: It is passed the position, shape type, and color of the shape
// Return:No return
//================================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle* circlePointer;
			circlePointer = new Circle(pos, color);
			shapes.push_back(circlePointer);
		}
		else if (whichShape == SQUARE)
		{
			Square* squarePointer;
			squarePointer = new Square(pos, color);
			shapes.push_back(squarePointer);
		}
	}

//================================================
// Purpose:It's the getter for the vector<DrawingShape*> shapes
// Parameters:No parameters
// Return:It returns the vector<DrawingShape*> shapes
//================================================
	const vector<DrawingShape*>&getShapes()
	{
		return shapes;
	}

//================================================
// Purpose:It helps get the shape data to the binary file
// Parameters:It is passed the fstream variable readIn
// Return:No Return
//================================================
	void readFile(fstream& readIn)
	{
		Record temp;
		while (readIn.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.shapePos, temp.shape, Color (temp.color));
		}
	}

//================================================
// Purpose:It helps move the shape data to the binary file
// Parameters:It is passed the fstream variable sendOut
// Return:No return
//================================================
	void writeToFile(fstream& sendOut)
	{
		Record temp;
		for (int i = 0; i < shapes.size(); i++)
		{
			temp = shapes[i]->getFileRecord();
			sendOut.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}
};
