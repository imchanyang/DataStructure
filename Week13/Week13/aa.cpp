#include <iostream>
#include <string.h>

#ifdef __STDC_LIB_EXT1__
constexpr bool can_have_strcpy_s = true;
#else
constexpr bool can_have_strcpy_s = false;
#endif

using namespace std;

class Person {
    char* name;
    char* phone;
    int age;
    
public:
    Person(const char* _name, const char* _phone, int _age) {
        int len1 = strlen(_name) + 1;
        name = new char [len1];
        strncpy(name, _name, len1);
        
        int len2 = strlen(_phone) + 1;
        phone = new char[len2];
        strncpy(phone,_phone,len2);
        
        age = _age;
    }
    void Showdata() {
        cout << "name: " << name << endl;
        cout << "phone: " << phone << endl;
        cout << "age: " << age << endl;
    }
};

int main() {
    
    Person p("Han", "010-1234-1234", 24);
    p.Showdata();
    return 0;
}
