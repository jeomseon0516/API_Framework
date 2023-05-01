#include "MainUpdate.h"

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	startX = 100;
	startY = 100;

	sizeX = 100;
	sizeY = 100;
}

void MainUpdate::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		startY -= SPEED;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		startY += SPEED;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		startX -= SPEED;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		startX += SPEED;
	}

	endX = startX + sizeX;
	endY = startY + sizeY;
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, startX, startY, endX, endY);
}

void MainUpdate::Destroy()
{
}
