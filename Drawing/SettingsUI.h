#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include "Shape.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	CircleShape circleBtn;
	RectangleShape squareBtn;
	SettingsMgr *settingsManager;

public:
//================================================
// Purpose:The constructor that initializes settingsManager
// Parameters:The SettingsMgr pointer that is named mgr
// Return:No return
//================================================
	SettingsUI(SettingsMgr *mgr)
	{
		settingsManager = mgr;
	}

//================================================
// Purpose:To tell what the selected options were based on the mouses position
// Parameters:It is passed the position of the mouse
// Return:No return
//================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurColor(Color::Blue);
		}
		else if (redBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurColor(Color::Red);
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurColor(Color::Green);
		}
		else if (circleBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurShape(CIRCLE);
		}
		else if (squareBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurShape(SQUARE);
		}
	}

//================================================
// Purpose:This draws the buttons and labels on the left side
// Parameters:It is passed the dimensions of the window
// Return:No return
//================================================
	void draw(RenderWindow& win)
	{
		Font font1;
		if (!font1.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
		Text title1("Selected Color", font1, 25);
		title1.setPosition(15, 25);
		win.draw(title1);

		Vector2f blueBtnPos(100, 75);
		blueBtn.setPosition(blueBtnPos);
		blueBtn.setRadius(10);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		if (settingsManager->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}
		else
			blueBtn.setFillColor(Color::Transparent);

		win.draw(blueBtn);

		Vector2f redBtnPos(100, 125);
		redBtn.setPosition(redBtnPos);
		redBtn.setRadius(10);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		if (settingsManager->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}
		else
			redBtn.setFillColor(Color::Transparent);

		win.draw(redBtn);

		Vector2f greenBtnPos(100, 175);
		greenBtn.setPosition(greenBtnPos);
		greenBtn.setRadius(10);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		if (settingsManager->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}
		else
			greenBtn.setFillColor(Color::Transparent);

		win.draw(greenBtn);

		Font font2;
		if (!font2.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
		Text title2("Selected Shape", font2, 25);
		title2.setPosition(15, 225);
		win.draw(title2);

		Vector2f circleBtnPos(100, 275);
		circleBtn.setPosition(circleBtnPos);
		circleBtn.setRadius(10);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		if (settingsManager->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}
		else
			circleBtn.setFillColor(Color::Transparent);

		win.draw(circleBtn);

		Vector2f squareBtnPos(100, 325);
		squareBtn.setPosition(squareBtnPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(20, 20));
		if (settingsManager->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}
		else
			squareBtn.setFillColor(Color::Transparent);

		win.draw(squareBtn);
	}


};
