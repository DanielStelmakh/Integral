#include <iostream>
#include <valarray>

using namespace std;
float sq(float x);
float integrals(float x,float h,float n);
float Function(float x);
float trap(float x,float h,float n);
float simpson(float x,float h,float n);
int main() {
    float n;
    cin >> n;
    float h = 2.0 / n;
    cout << h << endl;
    float i=-1+h/2;
    float I = integrals(i,h,n);
    float U=trap(i,h,n);
   float z= simpson(i,h,n);
    cout<<"Метод прямоугольников"<<" "<<I<<endl;
    cout<<"Метод трапеций"<<" "<<U<<endl;
    cout<<z<<"Симпсон"<<" "<<endl;
    return 0;
}
float Function(float x){
    float b=1-sq(x);
    float ex=sqrt(b);
    float g=1.0/ex;
    return g;
}
float sq(float x){
    return x*x;
}
float integrals(float x,float h,float n) {
    float S = 0.0;
    for (int i = 0; i < n; i++) {
            if(x<1.0){
            S += (Function(x) * h);
            x += h;}
            }
    for (int i=2;i<10;i+=12)S+=Function(1-h/i)* h;
    return S;
}
float trap(float x,float h,float n){

    float S = 0.0;
    for (int i = 0; i < n; i++) {
            if(x<1.0&&x+h<1.0){
            S += (Function(x)+Function(x+h))/2 *h;
            x += h;}
    } for (int i=2;i<10;i+=8)S+=Function(1-h/i)* h;
    return S;
}
float simpson(float x,float h,float n){
    float S = 0.0;

    for (int i = 0; i < n; i+=2) {
        if(x<1.0 && x+h<1.0&& x+2*h<1.0){}
            S += (Function(x)+4*Function(x+h)+ Function(x+2*h)) *h/3;
            x += h;
        }

    for (int i=2;i<10;i+=4)S+=Function(1-h/i)* h;
    return S;
}