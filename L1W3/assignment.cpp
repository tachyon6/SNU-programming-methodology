#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void draw1(int height){
    for(int i = 0; i < height; i++){
            for(int j = 0; j < height; j++){
                cout << "**";
            }
            cout << endl;
        }
}
void draw2(int height){
    for(int i = 0; i < height; i++){
            for(int j = 0; j < height-i-1; j++){
                cout << " ";
            }
            for(int j =  0; j <= i; j++){
                cout << "**";
            }
            for(int j = 0; j < height-i-1; j++){
                cout << " ";
            }
            cout << endl;
        }
}

void draw3(int height){
    int sum = 0;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < i; j++){
                cout << "**";
            }
            sum += (i+1);
            cout << sum;
            if(sum > 9){
                for(int j = 0; j < 2*height-2*i-2; j++){
                cout << "*";
                }
            } else {
            for(int j = 0; j < 2*height-2*i-1; j++){
                cout << "*";
            } }
            cout << endl;
        }
}

void draw4(int height){
    int a = 0;
    int b = 1;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < i; j++){
                cout << "**";
            }
            int next = a + b;
        a = b;
        b = next;
            cout << a;
            if(a > 9){
                for(int j = 0; j < 2*height-2*i-2; j++){
                cout << "*";
                }
            } else {
            for(int j = 0; j < 2*height-2*i-1; j++){
                cout << "*";
            }}
            cout << endl;
        }
}

int main() {
  int shape, height;
  cin>>shape>>height;
  switch (shape){
    case 1:
      draw1(height);
      break;
    case 2:
      draw2(height);
      break;
    case 3:
      draw3(height);
      break;
    case 4:
      draw4(height);
      break;
  }
  return 0;
}

//your code starts here (function definition : draw1, draw2, draw3, draw4)


//your code ends here