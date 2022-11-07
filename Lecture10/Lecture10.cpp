#include <iostream>
#include "MuSoenMath.h"
#define PI 3.141592

using namespace std;

void main()
{
    std::cout << "Hello World!\n";
    vec3 v;
    v = vec3(2, 4, 1);

    mat3 Translate, Rotate, Scale;
    Translate = mat3(1, 0, 3
                    ,0, 1, 5
                    ,0, 0, 1);
    Rotate = mat3(float(cos(1/6*PI)), float(sin(1 / 6 * PI)), 0
                 , float(-sin(1 / 6 * PI)), float(cos(1 / 6 * PI)), 0
                 ,0, 0, 1);
    Scale = mat3(2, 0, 0
                ,0, 2, 0
                ,0, 0, 1);

    vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대
    p.print();
    vec3 pp = v.calculate(Translate).calculate(Rotate).calculate(Scale);   // 3,5 이동 | 30도 회전 | 2배 확대
    pp.print();

    vec3 trans = v * Translate;
    trans.print();
    vec3 tranS = v.calculate(Translate);
    tranS.print();
}