#include <stdio.h>
#include <string.h>

typedef struct PersonvTable PersonV;
typedef struct PersonObj Person;

struct PersonvTable {
    //Acessors
    char* (*getName) (Person*);
    int (*getAge) (Person*);
    char* (*getHistory) (Person*);

    //Mutators
    void (*setName) (Person*, char*);
    void (*setAge) (Person*, int);
    void (*setHistory) (Person*, char*);
};

struct PersonObj {
    char name[64];
    int age;
    char history[256];
    
    PersonV* methods;
};

char* getName(Person* this) {
    return this->name;
}

int getAge(Person* this) {
    return this->age;
}

char* getHistory(Person* this) {
    return this->history;
}

void setName(Person* this, char* name) {
    strncpy(this->name, name, sizeof(this->name));
}

void setAge(Person* this, int age) {
    this->age = age;
}

void setHistory(Person* this, char* history) {
    strncpy(this->history, history, sizeof(this->history));
}

PersonV methodsPerson = {
    getName,
    getAge,
    getHistory,
    setName,
    setAge,
    setHistory
};

Person ConstructorPerson(char* name, int age) { 
    Person new;
    new.methods = &methodsPerson;

    strncpy(new.name, name, sizeof(new.name));
    new.age = age;

    return new;
}

int main() {
    Person me = ConstructorPerson("Henrique dos Santos", 20);
    me.methods->setHistory(&me, "Hi, I'm an apprentice and I work at Bosch.");
    printf("\nName: %s\nAge: %d\nHistory: %s\n", me.methods->getName(&me),
                                             me.methods->getAge(&me),
                                             me.methods->getHistory(&me));

    return 0;
}