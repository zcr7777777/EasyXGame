#pragma once  
#include <math.h> 
/// <summary>
/// 二维向量，实现了常用的向量运算
/// </summary>
class Vector2  
{  
	public:  
	float x;  
	float y;  
	Vector2(float x=0,float y=0);  
	Vector2(const Vector2& r) : x(r.x), y(r.y) {}
	Vector2 operator*(float r) {  
        return Vector2(x*r,y*r);  
	}  
	Vector2 operator+(const Vector2& r) const{  
        return Vector2(x+r.x,y+r.y);  
	}  
    Vector2 operator-(const Vector2& r) const{  
        return Vector2(x-r.x,y-r.y);  
	}  
	Vector2 operator-() const{  
        return Vector2(-x,-y);  
	}  
	Vector2 operator*(const Vector2& r) const{  
        return Vector2(x*r.x,y*r.y);  
	}  
    Vector2& operator=(Vector2&& r) noexcept {
        if (this != &r) {
            x = r.x;
            y = r.y;
            r.x = 0.0f;
            r.y = 0.0f;
        }
        return *this;
    }
    Vector2& operator=(const Vector2& r) {    
        x = r.x;    
        y = r.y;    
        return *this;    
    }  
	float Dot(const Vector2& r) const{  
        return x*r.x+y*r.y;  
	}  
	float Length() const{  
        return sqrt(x*x+y*y);  
	}  
	Vector2 Normalize() const{  
        return Vector2(x/Length(), y / Length());  
	}  
	void operator*=(const float& r) {  
        x*=r;  
        y*=r;  
	}  
	void operator+=(const Vector2& r) {  
        x+=r.x;  
        y+=r.y;  
	}  
    void operator-=(const Vector2& r) {  
        x-=r.x;  
        y-=r.y;  
	}  
	Vector2 operator*(float r) const{  
        return Vector2(x*r,y*r);  
	}  
};  
extern Vector2 operator*(float scalar, const Vector2& v);
/// <summary>
/// 二维变换类，封装了二维空间变换的信息：位置，缩放，旋转
/// </summary>
class Transform  
{  
public:  
	Vector2 position;  
	Vector2 scale;  
	float rotation;  
	Transform(Vector2 pos,Vector2 scale,float rot):position(pos),scale(scale),rotation(rot){}  
	Transform():position(0,0),scale(1,1),rotation(0){}  
};
