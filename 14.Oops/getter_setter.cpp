#include<iostream>
using namespace std;

class Gun{
private:
    int ammo;
    int damage;
    string name;
public:
    void set_gunDetails(int ammo, int damage, string name){
        this->ammo = ammo;
        this->damage = damage;
        this->name = name;
    }
    void get_gunDetails(){
        cout<<name<<" "<<damage<<" "<<ammo<<" ";
    }
};

class Player{
private:
    class Helmet{
    private:
        int hp;
        int level;
    public:
        void set_Details(int hp, int level){
            this->hp = hp;
            this->level = level;
        }
        void get_Details(){
            cout<<level<<" "<<hp<<"\n";
        }
    };
    int health;
    int score;
    string name; 
    Gun gun;
    Helmet helmet;

    
public:
    void setter(int health, int score, string name, Gun gun){
        this->health = health;
        this->score = score;
        this->name = name;
        this->gun = gun;
    }
    void getter(){
        cout<<name<<" "<<health<<" "<<score<<" ";
        gun.get_gunDetails();
        helmet.get_Details();
    }
    int get_score(){
        return score;
    }
    string get_name(){
        return name;
    }
    void set_name(string name){
        this->name = name;
    }
    void set_Hemlet(int level){
        Helmet *helmet = new Helmet;
        int health;
        if(level == 1) health = 25;
        else if(level == 2) health = 50;
        else if(level == 3) health = 100;
        else cout<<"invalid level!!";
        helmet->set_Details(health, level);
        this->helmet = *helmet;
    }
    
};

int add_Score(Player a, Player b){
    return a.get_score() + b.get_score();
}

Player max_score(Player a, Player b){
    return (a.get_score() >= b.get_score()) ? a : b;
}

void change_name(Player a, string name){   // pass by value
    a.set_name(name);
}

int main(){
    Player A, B;  // A B C -> object    // static allocation 
    Player *C = new Player;            // dynamic allocation

    Gun X, Y;
    X.set_gunDetails(40, 50, "m416");
    Y.set_gunDetails(40, 65, "akm");

    A.setter(200, 90, "amit", X); 
    A.set_Hemlet(3);

    B.setter(230, 60, "ritu", Y);
    B.set_Hemlet(2);
    //C->setter(180, 85, "urvi");

    A.getter();
    B.getter();

    Player Players[] = {A, B};   // array of object

    cout<<"Total score of a and b: "<<add_Score(A,B)<<"\n";  // passing object in function
    cout<<"The player who have max score is: "<<max_score(A,B).get_name()<<"\n";

}