#include "User.h"

namespace bot {
    using std::string;

    class User::Implementation {
    private:
        string name;
    public:
        string getName() const {
            return name;
        }

        void setName(const string &name) {
            this->name = name;
        }
    };

    User::User() {
        implementation = new Implementation();
    }

    User::User(const User &obj) {
        this->implementation = new User::Implementation(*obj.implementation);
    }

    User::~User() {
        delete implementation;
    }

    string User::getName() const {
        return implementation->getName();
    }

    void User::setName(const std::string &name) {
        implementation->setName(name);
    }
}
