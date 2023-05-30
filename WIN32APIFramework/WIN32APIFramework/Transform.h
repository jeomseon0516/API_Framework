#pragma once

#include "Include.h"
#include "Vector2.h"

typedef class tagTransform
{
private:
    Vector2 anchor;
    Vector2 size;
public:
    Vector2 position;

    inline void ImageRender(const HDC& hdc, const HDC& memDC, int countX, int locomotion)
    {
        TransparentBlt(hdc,
            int(position.x - size.x * anchor.x),
            int(position.y - size.y * anchor.y),
            (int)size.x,
            (int)size.y,
            memDC,
            countX * (int)size.x,
            locomotion * (int)size.y,
            (int)size.x,
            (int)size.y,
            RGB(255, 0, 255));
    }

    void GetOffset(float& left, float& right, float& top, float& bottom)
    {
        left = size.x * anchor.x;
        right = size.x * (1 - anchor.x);

        top = size.y * anchor.y;
        bottom = size.y * (1 - anchor.y);
    }

    void DrawRect(const HDC& hdc)
    {
        float leftOffset, rightOffset, topOffset, bottomOffset;
        GetOffset(leftOffset, rightOffset, topOffset, bottomOffset);

        Rectangle(hdc,
            int(position.x - leftOffset),
            int(position.y + topOffset),
            int(position.x + rightOffset),
            int(position.y - bottomOffset));
    }

    void DrawEllipse(const HDC& hdc)
    {
        Ellipse(hdc,
            int(position.x - size.x * 0.5f),
            int(position.y + size.y * 0.5f),
            int(position.x + size.x * 0.5f),
            int(position.y - size.y * 0.5f));
    }

    void AnchorCorrection(float& value);

    Vector2 GetPosition() { return position; }
    void SetPosition(const Vector2& position) { this->position = position; }

    Vector2 GetSize() { return size; }

    void SetAnchor(const Vector2& anchor) { this->anchor = anchor; }
    void SetSize(const Vector2& size) { this->size = size; }

    float GetMinY() { return position.y - size.y * (1 - anchor.y); }

public:
     tagTransform(const Vector2& position, const Vector2& size, Vector2 anchor = Vector2::Center());
     tagTransform();
    ~tagTransform();
}Transform;

typedef struct tagLocomotion
{
    int countY;
    int endFrameX;

    tagLocomotion(int _locomotion = 0, int _endFrameX = 0) : countY(_locomotion), endFrameX(_endFrameX) {}
}Locomotion;

typedef struct tagFrame
{
    tagLocomotion locomotion;
    float frameTime;
    int countX;

    tagFrame() : frameTime(50), countX(0) {}
}Frame;
