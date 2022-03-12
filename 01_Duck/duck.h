#include <iostream>

using namespace std;

class FlugVerhalten {
    public:
        virtual void fliegen() = 0;
};

class FliegenMitFluegeln : public FlugVerhalten {
    public:
        void fliegen(){
            cout << "Ich fliege mit Fluegeln" << endl;
        }
};

class FliegenNichtMoeglich : public FlugVerhalten {
    public:
        void fliegen(){
            cout << "Ich kann nicht fliegen" << endl;
        }
};


class QuackVerhalten {
    public:
        virtual void quack() = 0;
};

class Quack : public QuackVerhalten {
    public:
        void quack() {
            cout << "Ich kann quacken" << endl;
        }
};



class Ente {
    protected:
        FlugVerhalten * fv;
        QuackVerhalten * qv;

    public:
        Ente(){
            fv = new FliegenMitFluegeln();
            qv = new Quack();
        }

        void schwimmen(){
            cout << "Ich kann schwimmen" << endl;
        }

        virtual void fliegen() = 0;
};

class Stockente : public Ente {
    public:
        void fliegen(){
            Ente::fv->fliegen();
        }
        void quack(){
            Ente::qv->quack();
        }

        void setzeFlugverhalten(FlugVerhalten * neuesFlugverhalten){
            fv = neuesFlugverhalten;
        }

};