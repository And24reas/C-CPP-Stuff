#include <iostream>
#include <cstring>

using namespace std;

class STRING{
    public:
        STRING();
        STRING(char *str_in);
        STRING(const STRING &obj);
        ~STRING();
        int get_length() const;
        char *get_str() const;
        void print();
        void set_str(char *str_in);

    private:
        int length;
        char *str;
};

int main(){

    char  s[80] ="This is a String!";
    char  s_new[80] ="This is a new String!";
    STRING s1(s);
    STRING s2(s1);
    s1.print();
    s2.set_str(s_new);
    s2.print();
    return 0;
}

STRING::STRING(){
    length=0;
    str=NULL;
}

STRING::STRING(const STRING &obj){
    length=obj.get_length();
    str=new char[length];
    if(!str){
        cout<<"Error allocating memory!";
    }
    strcpy(str, obj.get_str());
}

STRING::STRING(char *str_in){
    length=strlen(str_in);
    str=new char[length];
    if(!str){
        cout<<"Error Allocating Memory!";
    }
    strcpy(str, str_in);
}

STRING::~STRING(){
    delete str;
}

int STRING::get_length() const{
    return length;
}

char *STRING::get_str() const{
    return str;
}

void STRING::print(){
    cout<<str;
}

void STRING::set_str(char *str_in){
    if(str!=NULL){
        delete str;
    }

    length = strlen(str_in);
    str = new char[length];
    if(!str){
        cout<<"Error allocating memory!";
    }

    strcpy(str, str_in);
}