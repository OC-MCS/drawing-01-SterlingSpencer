#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape canvas;
public:
//================================================
// Purpose:It is the constructor that initializes the position and size of the canvas
// Parameters:It is passed the position of the canvas
// Return:No return
//================================================
	DrawingUI(Vector2f p)
	{
		canvas.setPosition(p);
		canvas.setSize(Vector2f(400, 400));
	}

//================================================
// Purpose:It draws the canvas that the user can draw on
// Parameters:It is passed the window information and the ShapeMgr pointer mgr
// Return:No return
//================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		canvas.setOutlineColor(Color::White);
		canvas.setOutlineThickness(2);
		win.draw(canvas);

		vector<DrawingShape*> shapes;
		shapes = mgr->getShapes();

		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->draw(win);
		}
	}
	
//================================================
// Purpose:This checks to see if the mouse is present on the canvas
// Parameters:It is passed the mouse's current position
// Return:No return
//================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return canvas.getGlobalBounds().contains(mousePos) && canvas.getGlobalBounds().contains(Vector2f(mousePos.x + 20, mousePos.y + 20)); // just to make it compile
	}

};

