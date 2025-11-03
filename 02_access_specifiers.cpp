#include <iostream>
#include <string>

// --- 基类 ---
class Base {
public:
    int public_var = 1;
protected:
    int protected_var = 2;
private:
    int private_var = 3;
};

// --- public 继承 ---
class DerivedPublic : public Base {
public:
    void accessBaseMembers() {
        std::cout << "--- In DerivedPublic ---" << std::endl;
        std::cout << "Can access public_var: " << public_var << std::endl;       // OK: public 继承后仍然是 public
        std::cout << "Can access protected_var: " << protected_var << std::endl; // OK: public 继承后仍然是 protected
        // std::cout << "Cannot access private_var: " << private_var << std::endl;  // ERROR: 基类的 private 成员不可访问
    }
};

// --- protected 继承 ---
class DerivedProtected : protected Base {
public:
    void accessBaseMembers() {
        std::cout << "--- In DerivedProtected ---" << std::endl;
        std::cout << "Can access public_var (now protected): " << public_var << std::endl;       // OK: public 继承后变为 protected
        std::cout << "Can access protected_var (still protected): " << protected_var << std::endl; // OK: protected 继承后仍然是 protected
    }
};

// --- private 继承 ---
class DerivedPrivate : private Base {
public:
    void accessBaseMembers() {
        std::cout << "--- In DerivedPrivate ---" << std::endl;
        std::cout << "Can access public_var (now private): " << public_var << std::endl;       // OK: public 继承后变为 private
        std::cout << "Can access protected_var (now private): " << protected_var << std::endl; // OK: protected 继承后变为 private
    }
};


int main() {
    DerivedPublic d_pub;
    d_pub.accessBaseMembers();
    std::cout << "In main, can access d_pub.public_var: " << d_pub.public_var << std::endl; // OK: public 成员，外部可访问
    // std::cout << d_pub.protected_var; // ERROR: protected 成员，外部不可访问
    
    DerivedProtected d_prot;
    d_prot.accessBaseMembers();
    // std::cout << d_prot.public_var; // ERROR: 继承后变为 protected，外部不可访问

    DerivedPrivate d_priv;
    d_priv.accessBaseMembers();
    // std::cout << d_priv.public_var; // ERROR: 继承后变为 private，外部不可访问

    return 0;
}
