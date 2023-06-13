#pragma once

class GlobalClass
{
    int m_value;
    static GlobalClass *s_instance;
    GlobalClass(int v = 0) {
        m_value = v;
    }
  public:
    int get_value() {
        return m_value;
    }
    void set_value(int v) {
        m_value = v;
    }
    static GlobalClass *instance() {
        if (!s_instance)
            s_instance = new GlobalClass;
        return s_instance;
    }
};

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
GlobalClass *GlobalClass::s_instance = 0;


class GlobalClass_ref {
    int m_value;
public:
    //static shared_ptr<GlobalClass2> s_instance;
    GlobalClass_ref(int v = 0) {
        m_value = v;
    }
    int get_value() {
        return m_value;
    }
    void set_value(int v) {
        m_value = v;
    }
    static GlobalClass_ref &instance() {
        static GlobalClass_ref s_instance;
        return s_instance;
    }
};


class GlobalClass_shared {
    int m_value;
public:

    GlobalClass_shared(int v = 0) {
        m_value = v;
    }
    int get_value() {
        return m_value;
    }
    void set_value(int v) {
        m_value = v;
    }
    static shared_ptr<GlobalClass_shared> instance() {
        static shared_ptr<GlobalClass_shared> shared_instance = std::make_shared<GlobalClass_shared>();
        return shared_instance;
    }
};

class T_dp_singleton
{
public:
    static void foo(void) {
        GlobalClass::instance()->set_value(1);
        GlobalClass_ref::instance().set_value(1);
        GlobalClass_shared::instance()->set_value(1);
        cout << "POINTER   foo: global is " << GlobalClass::instance()->get_value() << endl;
        cout << "REFERENCE foo: global is " << GlobalClass_ref::instance().get_value() << endl;
        cout << "SHARED    foo: global is " << GlobalClass_shared::instance()->get_value() << endl << endl;
    }

    static void bar(void) {
        GlobalClass::instance()->set_value(2);
        GlobalClass_ref::instance().set_value(2);
        GlobalClass_shared::instance()->set_value(2);
        cout << "POINTER   bar: global is " << GlobalClass::instance()->get_value() << endl;
        cout << "REFERENCE bar: global is " << GlobalClass_ref::instance().get_value() << endl;
        cout << "SHARED    bar: global is " << GlobalClass_shared::instance()->get_value() << endl << endl;
    }

    static void test() {
        cout << "POINTER   main: global is " << GlobalClass::instance()->get_value() << endl;
        cout << "REFERENCE main: global is " << GlobalClass_ref::instance().get_value() << endl;
        cout << "SHARED    main: global is " << GlobalClass_shared::instance()->get_value() << endl << endl;
        foo();
        bar();
    }
};
