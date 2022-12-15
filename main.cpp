#include <iostream>
#include <math.h>
using namespace std;

class Point
{
public:
    double t;
    double x;
    double y;
    double z;
    char name;

    Point(double t = 0, double x = 0, double y = 0, double z = 0, char name = '0'):
    t(t), x(x), y(y), z(z), name(name) {}


    void show()
    {
        cout <<"t"<< name << " = " << t << endl;
        cout <<"x"<< name << " = " << x << endl;
        cout <<"y"<< name << " = " << y << endl;
        cout <<"z"<< name << " = " << z << endl;
    }

};

class Line
{
public:
    Point p1;
    Point p2;
    double x;
    double y;
    double z;
    double r;
    Line(Point p1, Point p2): p1(p1), p2(p2)
    {
        this->x = p1.x - p2.x;
        this->y = p1.y - p2.y;
        this->z = p1.z - p2.z;
        this->r = abs((100000*(p1.t - p2.t))/333564);
    }

};

int main() {
    double error = 200;

    Point i(86320708 + error, -15102069, 21482069, 3683495, 'i');
    Point k(67335895 + error, 15338349, 15338349, 15338349, 'k');
    Point j(75293013 + error, 0, 6380000, 25789348, 'j');
    Point l(78283279 + error, 26566800, 0, 0, 'l');

    i.show(); cout << endl;
    k.show(); cout << endl;
    j.show(); cout << endl;
    l.show(); cout << endl;

    Line ji(j,i);
    Line ik(i,k);
    Line lk(l,k);
    Line ki(k,i);
    Line jk(j,k);


    double s9 = ik.r * ji.x - ji.r * ki.x;
    double s10 = ji.r * ki.y - ik.r * ji.y;
    double s11 = ik.r * ji.z - ji.r * ki.z;
    double s12 = (ik.r * (ji.r*ji.r + i.x*i.x - j.x*j.x + i.y*i.y - j.y*j.y + i.z*i.z - j.z*j.z)
            -ji.r*(ik.r*ik.r + i.x*i.x - k.x*k.x + i.y*i.y - k.y*k.y + i.z*i.z - k.z*k.z))/2;
    double s13 = lk.r*jk.x - jk.r*lk.x;
    double s14 = jk.r*lk.y - lk.r*jk.y;
    double s15 = lk.r*jk.z - jk.r*lk.z;
    double s16 = (lk.r*(jk.r*jk.r + k.x*k.x - j.x*j.x + k.y*k.y - j.y*j.y + k.z*k.z - j.z*j.z)
            -jk.r*(lk.r*lk.r + k.x*k.x - l.x*l.x + k.y*k.y - l.y*l.y + k.z*k.z - l.z*l.z))/2;
    double a = s9/s10;
    double b = s11/s10;
    double c = s12/s10;
    double d = s13/s14;
    double e = s15/s14;
    double f = s16/s14;
    double g = (e-b)/(a-d);
    double h = (f-c)/(a-d);
    double I = (a*g) + b;
    double J = (a*h) + c;
    double K = ik.r*ik.r + i.x*i.x - k.x*k.x + i.y*i.y - k.y*k.y + i.z*i.z - k.z*k.z + 2*h*ki.x + 2*J*ki.y;
    double L = 2*(g*ki.x + I*ki.y + ki.z);
    double m = 4*ik.r*ik.r*(g*g+I*I+1) - L*L;
    double n = 8*ik.r*ik.r*(g*(i.x-h) + I*(i.y - J) + i.z) + 2*L*K;
    double o = 4*ik.r*ik.r*((i.x-h)*(i.x-h) + (i.y-J)*(i.y-J) + i.z*i.z) - K*K;
    double s28 = n/(2*m);
    double s29 = (o/m);
    double s30 = (s28*s28) - s29;
    double root = sqrt(s30);
    cout << endl;
    int z1 = s28 + root;
    int z2 = s28 - root;
    int x1 = g*z1 + h;
    int x2 = g*z2 + h;
    int y1 = a*x1 + b*z1 + c;
    int y2 = a*x2 + b*z2 + c;

    double r1i = sqrt(pow((x1-i.x),2) + pow((y1-i.y),2) + pow((z1-i.z),2));
    double r1j = sqrt(pow((x1-j.x),2) + pow((y1-j.y),2) + pow((z1-j.z),2));
    double r1k = sqrt(pow((x1-k.x),2) + pow((y1-k.y),2) + pow((z1-k.z),2));
    double r1l = sqrt(pow((x1-l.x),2) + pow((y1-l.y),2) + pow((z1-l.z),2));

    cout << "z1 = "<<z1<<endl;
    cout << "x1 = "<<x1<<endl;
    cout << "y1 = "<<y1<<endl<<endl;

    cout << "r1i = " << r1i << endl;
    cout << "r1j = " << r1j << endl;
    cout << "r1k = " << r1k << endl;
    cout << "r1l = " << r1l << endl<< endl;

    double r1i_t = 2.58783e+07;
    double r1j_t = 2.25723e+07;
    double r1k_t = 2.01868e+07;
    double r1l_t = 2.34687e+07;

    cout << "absolute difference with error = "<< error <<" between point and i,j,k,l: " << endl;
    cout << r1i - r1i_t << endl;
    cout << r1j - r1j_t << endl;
    cout << r1k - r1k_t << endl;
    cout << r1l - r1l_t << endl << endl;
    cout << "relative difference : " << endl;
    cout << r1i*100/r1i_t << endl;
    cout << r1j*100/r1j_t << endl;
    cout << r1k*100/r1k_t << endl;
    cout << r1l*100/r1l_t << endl;

//    cout << "z2 = "<<z2<<endl;
//    cout << "x2 = "<<x2<<endl;
//    cout << "y2 = "<<y2<<endl;

    return 0;
}
