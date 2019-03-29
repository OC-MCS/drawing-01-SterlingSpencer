#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };
void die(string);

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color selectedColor;
	ShapeEnum selectedShape;
public:
//================================================
// Purpose:The constructor that initializes the selected shape and color
// Parameters:It is passed the starting color and starting shape
// Return:No return
//================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		selectedColor = startingColor;
		selectedShape = startingShape;
	}

//================================================
// Purpose:The getter that returns the selected color
// Parameters:No parameters
// Return:It returns the selectedColor
//================================================
	Color getCurColor()
	{
		return selectedColor; // just to make it compile 
	}

//================================================
// Purpose:The getter that returns the selected shape
// Parameters:No parameters
// Return:It returns the selectedShape
//================================================
	ShapeEnum getCurShape()
	{
		return selectedShape; // just to make it compile;
	}

//================================================
// Purpose:The setter that sets the selectedColor to the curColor
// Parameters:It is passed curColor
// Return:No return
//================================================
	void setCurColor(Color curColor)
	{
		selectedColor = curColor;
	}

//================================================
// Purpose:The setter that sets the selectedShape to the curShape
// Parameters:It is passed curShape
// Return:No return
//================================================
	void setCurShape(ShapeEnum curShape)
	{
		selectedShape = curShape;
	}

//================================================
// Purpose:To read in the information about the color and shape from the binary file
// Parameters:It is passed the fstream readIn
// Return:No return
//================================================
	void readFile(fstream& readIn)
	{
		int temp;
		readIn.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		readIn.read(reinterpret_cast<char*>(&selectedShape), sizeof(selectedShape));
		selectedColor = Color(temp);
	}

//================================================
// Purpose:To send out the information about the color and shape to the binary file
// Parameters:It is passed the fstream sendOut
// Return:No return
//================================================
	void writeToFile(fstream& sendOut)
	{
		int temp = selectedColor.toInteger();
		sendOut.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		sendOut.write(reinterpret_cast<char*>(&selectedShape), sizeof(selectedShape));
	}
};

//================================================
// Purpose:If there is an error then it will end the program
// Parameters:It is passed the string msg
// Return:No return
//================================================
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
