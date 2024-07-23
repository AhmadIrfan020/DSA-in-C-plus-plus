#include <iostream>

using namespace std;

class Cookie {
    private:
        string color;

    public:
        Cookie (string c) {
            color = c;
        }
        string getColor () {
            return color;
        }
        void setColor (string c) {
            color = c;
        }
};


int main() {

    Cookie* cookieOne = new Cookie("green");
    cout << "C1: " << cookieOne->getColor() << endl;
    cookieOne->setColor("yellow"); 
    Cookie* cookieTwo = new Cookie("blue");
    cout << "New C1: " << cookieOne->getColor() << endl;
    cout << "C2: " << cookieTwo->getColor() << endl;

}

